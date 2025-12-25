#include "../include/me_portaudio.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>


// This callback will never be called again after a certain period of time

static int me_callBackListening(ME_Sound * me_sound,
					  const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData ) {
    (void) inputBuffer;
    (void) outputBuffer;
    (void) framesPerBuffer;
    (void) timeInfo;
    (void) statusFlags;
    (void) userData;
    sCallbackCount++;
    return paContinue;
}
/*
int me_record(ME_Sound * me_sound) {
    PaStream* stream = NULL;
    PaStreamParameters inputParameters;
    PaError err = 0;
    int loopCount = 0;
    uint64_t previousCallbackCount = sCallbackCount;
    Pa_Initialize ();

    inputParameters.device = Pa_GetDefaultInputDevice(); // default input device 
    printf("Recording using device #%d\n", inputParameters.device);
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paInt16;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(
              &stream,
              &inputParameters,
              NULL,                  // &outputParameters,
              44100,
              512,
              paClipOff,      // we won't output out of range samples so don't bother clipping them
              me_callBackListening, // callback
              NULL ); // no callback userData
    if( err != paNoError ) {
        printf("Pa_OpenDefaultStream returned %d!\n", err);
        goto error2;
    }
    err = Pa_StartStream ( stream );
    if( err != paNoError ) {
        printf("Pa_StartStream returned %d!\n", err);
        goto error1;
    }

    while ( Pa_IsStreamActive ( stream ) == 1 ) {
        Pa_Sleep ( 1000 );

        if (previousCallbackCount == sCallbackCount) {
            printf("Callbacks stopped!\n");
            goto error1;
        }
        previousCallbackCount = sCallbackCount;

        loopCount++;
        if ((loopCount % 10) == 0) {
            printf("%d loops\n", loopCount);
        }
    }
    printf("Stream no longer Active!");

error1:
    Pa_CloseStream ( stream );
error2:
    Pa_Terminate ();
    return 0;
}

*/


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*
static int wireCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData )
{
    INPUT_SAMPLE *in;
    OUTPUT_SAMPLE *out;
    int inStride;
    int outStride;
    int inDone = 0;
    int outDone = 0;
    WireConfig_t *config = (WireConfig_t *) userData;
    unsigned int i;
    int inChannel, outChannel;

    // This may get called with NULL inputBuffer during initial setup. 
    if( inputBuffer == NULL) return 0;

    // Count flags 
    if( (statusFlags & paInputUnderflow) != 0 ) config->numInputUnderflows += 1;
    if( (statusFlags & paInputOverflow) != 0 ) config->numInputOverflows += 1;
    if( (statusFlags & paOutputUnderflow) != 0 ) config->numOutputUnderflows += 1;
    if( (statusFlags & paOutputOverflow) != 0 ) config->numOutputOverflows += 1;
    if( (statusFlags & paPrimingOutput) != 0 ) config->numPrimingOutputs += 1;
    config->numCallbacks += 1;

    inChannel=0, outChannel=0;
    while( !(inDone && outDone) )
    {
        if( config->isInputInterleaved )
        {
            in = ((INPUT_SAMPLE*)inputBuffer) + inChannel;
            inStride = config->numInputChannels;
        }
        else
        {
            in = ((INPUT_SAMPLE**)inputBuffer)[inChannel];
            inStride = 1;
        }

        if( config->isOutputInterleaved )
        {
            out = ((OUTPUT_SAMPLE*)outputBuffer) + outChannel;
            outStride = config->numOutputChannels;
        }
        else
        {
            out = ((OUTPUT_SAMPLE**)outputBuffer)[outChannel];
            outStride = 1;
        }

        for( i=0; i<framesPerBuffer; i++ )
        {
            *out = CONVERT_IN_TO_OUT( *in );
            out += outStride;
            in += inStride;
        }

        if(inChannel < (config->numInputChannels - 1)) inChannel++;
        else inDone = 1;
        if(outChannel < (config->numOutputChannels - 1)) outChannel++;
        else outDone = 1;
    }
    return 0;
}*/

/*******************************************************************/
int me_inoutRecording(ME_Sound * me_sound)
{
    PaError err = paNoError;
    WireConfig_t CONFIG;
    WireConfig_t *config = &CONFIG;
    int configIndex = 0;
    int maxInputChannels = 0;
    int maxOutputChannels = 0;

    err = Pa_Initialize();
    if( err != paNoError ) goto error;

    /* NOTE: INPUT/OUTPUT_DEVICE macros may use PaGetDefault...Device(), so call after Pa_Initialze() */
    config->inputDevice = INPUT_DEVICE;
    if (config->inputDevice == paNoDevice) {
        fprintf(stderr,"Error: No default input device.\n");
        goto done;
    }

    config->outputDevice = OUTPUT_DEVICE;
    if (config->outputDevice == paNoDevice) {
        fprintf(stderr,"Error: No default output device.\n");
        goto done;
    }

    printf("Please connect audio signal to input and listen for it on output!\n");
    printf("input format = %lu\n", INPUT_FORMAT );
    printf("output format = %lu\n", OUTPUT_FORMAT );
    printf("input device ID  = %d\n", config->inputDevice );
    printf("output device ID = %d\n", config->outputDevice );

    /* Determine the maximum number of channels supported by each device. */
    maxInputChannels = Pa_GetDeviceInfo(config->inputDevice)->maxInputChannels;
    printf("maxInputChannels = %d\n", maxInputChannels );

    maxOutputChannels = Pa_GetDeviceInfo(config->outputDevice)->maxOutputChannels;
    printf("maxOutputChannels = %d\n", maxOutputChannels );

    if (maxInputChannels < 1) {
        fprintf(stderr,"Error: device has no input channels. At least one channel required for full-duplex test.\n");
        goto done;
    }

    if (maxOutputChannels < 1) {
        fprintf(stderr,"Error: device has no output channels. At least one channel required for full-duplex test.\n");
        goto done;
    }

    if( INPUT_FORMAT == OUTPUT_FORMAT )
    {
        gInOutScaler = 1.0;
    }
    else if( (INPUT_FORMAT == paInt16) && (OUTPUT_FORMAT == paFloat32) )
    {
        gInOutScaler = 1.0/32768.0;
    }
    else if( (INPUT_FORMAT == paFloat32) && (OUTPUT_FORMAT == paInt16) )
    {
        gInOutScaler = 32768.0;
    }

    for( config->isInputInterleaved = 0; config->isInputInterleaved < 2; config->isInputInterleaved++ )
    {
        for( config->isOutputInterleaved = 0; config->isOutputInterleaved < 2; config->isOutputInterleaved++ )
        {
            for( config->numInputChannels = 1;
                    config->numInputChannels <= maxInputChannels;
                    config->numInputChannels++ )
            {
                for( config->numOutputChannels = 1;
                        config->numOutputChannels <= maxOutputChannels;
                        config->numOutputChannels++ )
                {
                           /* If framesPerCallback = 0, assertion fails in file pa_common/pa_process.c, line 1413: EX. */
                    for( config->framesPerCallback = 64;
                            config->framesPerCallback < 129;
                            config->framesPerCallback += 64 )
                    {
                        printf("-----------------------------------------------\n" );
                        printf("Configuration #%d\n", configIndex++ );
                        //err = TestConfiguration( config );
                        /* Give user a chance to bail out. */
                        if( err == 1 )
                        {
                            err = paNoError;
                            goto done;
                        }
                        else if( err != paNoError ) goto error;
                    }
                }
            }
        }
    }

done:
    Pa_Terminate();
    printf("Full duplex sound test complete.\n"); fflush(stdout);
    printf("Hit ENTER to quit.\n");  fflush(stdout);
    getchar();
    return 0;

error:
    Pa_Terminate();
    fprintf( stderr, "An error occurred while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
    printf("Hit ENTER to quit.\n");  fflush(stdout);
    getchar();
    return -1;
}

/*
static PaError TestConfiguration( WireConfig_t *config )
{
    int c;
    PaError err = paNoError;
    PaStream *stream;
    PaStreamParameters inputParameters, outputParameters;

    printf("input %sinterleaved!\n", (config->isInputInterleaved ? " " : "NOT ") );
    printf("output %sinterleaved!\n", (config->isOutputInterleaved ? " " : "NOT ") );
    printf("input channels = %d\n", config->numInputChannels );
    printf("output channels = %d\n", config->numOutputChannels );
    printf("framesPerCallback = %d\n", config->framesPerCallback );

    inputParameters.device = config->inputDevice;
    inputParameters.channelCount = config->numInputChannels;
    inputParameters.sampleFormat = INPUT_FORMAT | (config->isInputInterleaved ? 0 : paNonInterleaved);
    inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = config->outputDevice;
    outputParameters.channelCount = config->numOutputChannels;
    outputParameters.sampleFormat = OUTPUT_FORMAT | (config->isOutputInterleaved ? 0 : paNonInterleaved);
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    config->numInputUnderflows = 0;
    config->numInputOverflows = 0;
    config->numOutputUnderflows = 0;
    config->numOutputOverflows = 0;
    config->numPrimingOutputs = 0;
    config->numCallbacks = 0;

    // frames per buffer //
    // we won't output out of range samples so don't bother clipping them 
    // me_callBackListening
    err = Pa_OpenStream(
              &stream,
              &inputParameters,
              &outputParameters,
              SAMPLE_RATE,
              config->framesPerCallback,
              paClipOff, 
              &wireCallback,
              config );
    if( err != paNoError ) goto error;

    err = Pa_StartStream( stream );
    if( err != paNoError ) goto error;

    printf("Now recording and playing. - Hit ENTER for next configuration, or 'q' to quit.\n");  fflush(stdout);
    c = getchar();

    printf("Closing stream.\n");
    err = Pa_CloseStream( stream );
    if( err != paNoError ) goto error;

#define CHECK_FLAG_COUNT(member) \
    if( config->member > 0 ) printf("FLAGS SET: " #member " = %d\n", config->member );
    CHECK_FLAG_COUNT( numInputUnderflows );
    CHECK_FLAG_COUNT( numInputOverflows );
    CHECK_FLAG_COUNT( numOutputUnderflows );
    CHECK_FLAG_COUNT( numOutputOverflows );
    CHECK_FLAG_COUNT( numPrimingOutputs );
    printf("number of callbacks = %d\n", config->numCallbacks );

    if( c == 'q' ) return 1;

error:
    return err;
}*/
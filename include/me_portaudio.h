#ifndef __ME_SOUND_PORTAUDIO_H__
#define __ME_SOUND_PORTAUDIO_H__



#define SAMPLE_RATE            (44100)

typedef struct WireConfig_s
{
    PaDeviceIndex inputDevice;
    PaDeviceIndex outputDevice;
    int isInputInterleaved;
    int isOutputInterleaved;
    int numInputChannels;
    int numOutputChannels;
    int framesPerCallback;
    /* count status flags */
    int numInputUnderflows;
    int numInputOverflows;
    int numOutputUnderflows;
    int numOutputOverflows;
    int numPrimingOutputs;
    int numCallbacks;
} WireConfig_t;

#define USE_FLOAT_INPUT        (1)
#define USE_FLOAT_OUTPUT       (1)

/* Latencies set to defaults. */

#if USE_FLOAT_INPUT
    #define INPUT_FORMAT  paFloat32
    typedef float INPUT_SAMPLE;
#else
    #define INPUT_FORMAT  paInt16
    typedef short INPUT_SAMPLE;
#endif

#if USE_FLOAT_OUTPUT
    #define OUTPUT_FORMAT  paFloat32
    typedef float OUTPUT_SAMPLE;
#else
    #define OUTPUT_FORMAT  paInt16
    typedef short OUTPUT_SAMPLE;
#endif

double gInOutScaler = 1.0;
#define CONVERT_IN_TO_OUT(in)  ((OUTPUT_SAMPLE) ((in) * gInOutScaler))

#define INPUT_DEVICE           (Pa_GetDefaultInputDevice())
#define OUTPUT_DEVICE          (Pa_GetDefaultOutputDevice())

static PaError TestConfiguration( WireConfig_t *config );

static int wireCallback( const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData );



static int me_wireCallback(ME_Sound * me_sound, const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData );

int me_inoutRecording(ME_Sound * me_sound);

static int64_t sCallbackCount = 0;
// This callback will never be called again after a certain period of time

static int me_callBackListening(ME_Sound * me_sound);

int me_record(ME_Sound * me_sound);


#endif
#include "../include/me_system.h"

ME_System * create_MirtilleSystem(){
	ME_System * me_system = (ME_System *) malloc(sizeof(ME_System));
	if(me_system == NULL){
		return NULL;
	}
	assert(me_system != NULL);

	return me_system;
}


void me_init_System(ME_System * me_system, const char * title){
	// TODO : HERE
	assert(me_system != NULL);
	assert(title != NULL);
}

void me_configuration_init_system(ME_System * me_system){
	// TODO : HERE
	assert(me_system != NULL);
}

void kill_video_system(ME_System * me_system){
	pthread_kill(me_system->video_pid, SIGKILL);
}

void me_getResolution(int * _W, int *_H){
	pid_t pid;
int fd[2];

#define WRITE_END 1

#define READ_END 0

pipe(fd);
pid = fork();

if(pid==0)
{
    dup2(fd[WRITE_END], STDOUT_FILENO);
    close(fd[READ_END]);
    close(fd[WRITE_END]);
    execlp("/bin/xdpyinfo", "xdpyinfo", (char*) NULL);
    fprintf(stderr, "Failed to execute '%s'\n", "xdpyinfo");
    exit(1);
}
else
{ 
    pid=fork();

    if(pid==0)
    {
        dup2( fd[READ_END], STDIN_FILENO);
        close(fd[WRITE_END]);
        close(fd[READ_END]);
        execlp("/bin/grep", "grep", "dimensions", (char*) NULL);
        fprintf(stderr, "Failed to execute '%s'\n", "grep");
        exit(1);
    }
    else
    {
        /*int status;
        dup2 (fd[1], STDOUT_FILENO);
        close(fd[0]);*/
        close(fd[1]);
        char foo[2096];

        int nbytes = read(fd[0], foo, sizeof(foo));
        foo[9 + 1270] = 0;
        char resolution[10];
        sprintf(resolution, "%s", foo+1270);
        //printf("Output: (%.*s)\n", nbytes, foo+1270);
        printf("=(%s)\n", resolution);
        int W, H;
        sscanf(resolution, "%dx%d", &W, &H);

        printf("Width=%d X Height=%d\n", W, H);

        *_W = W;
        *_H = H;

        wait(NULL);
        //waitpid(pid, &status, 0);
    }
}
}

void getResolution2(){
	#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);
	int link[2];
	pid_t pid;
	char foo[4096];

	if (pipe(link)==-1)
	die("pipe");

	if ((pid = fork()) == -1)
	die("fork");

	if(pid == 0) {

	dup2 (link[1], STDOUT_FILENO);
	close(link[0]);
	close(link[1]);
	execl("/bin/ls", "xdpyinfo", "|", "grep", "dimensions",  (char *)0);
	die("execl");

	} else {
	close(link[1]);
	int nbytes = read(link[0], foo, sizeof(foo));
	printf("Output: (%.*s)\n", nbytes, foo);
	wait(NULL);
	}

}

void me_destroy_System(ME_System * me_system){
	// TODO : HERE
	assert(me_system != NULL);
}

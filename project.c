#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(){
    char devname[] = "/dev/input/event2";
    int device = open(devname, O_RDONLY);
    struct input_event ev;
  
    while(1){
        read(device,&ev, sizeof(ev));

        if(ev.type == 1 && ev.value == 1 && ev.code ==21){
            printf("Y pressed Key: %i State: %i\n",ev.code,ev.value);
            pid_t pid = fork();
            printf("fork returned: %d\n", (int) pid);
 
            if (pid<0) {
                perror("Fork failed");
            }
            if (pid==0){
                printf("I am the child with pid %d\n", (int) getpid());
                system("sudo ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg yolov3-tiny.weights ~/Desktop/obj.mp4");
            }
            printf("I am the parent \n");
            printf("Parent ending. \n");
           
        }
    }
    return 0;
}
 
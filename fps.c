#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void getElapsedTime(struct timeval Tstart, struct timeval Tend){

	Tend.tv_usec = Tend.tv_usec - Tstart.tv_usec;
	Tend.tv_sec = Tend.tv_sec - Tstart.tv_sec;
	Tend.tv_usec += (Tend.tv_sec*1000000);

	printf("elapsed time : %lf sec\n", Tend.tv_usec/1000000.0);

}

int main(){
	
	int i=0;
	int cnt = 0;
	struct timeval Tstart, Tend;
	
	gettimeofday(&Tstart,NULL);
	sleep(1);
	gettimeofday(&Tend,NULL);
	getElapsedTime(&Tstart,Tend);
	
	return 0;


}	

/**
* @file main.c
* @brief Description
* @date 2015-10-24
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <limits.h>

#include "debug.h"
#include "memory.h"

int main(int argc, char *argv[]){


	int min,max,i;
	char cmd[255];
	

	if(argc <2 ){

		printf("You need to give me more atributtes <min number> <max. number> <path>(with a / at the end)\n");
	}else if(argc<3){
		
		printf("You need to give me more atributtes <max. number> <path>(with a / at the end) \n");
	
	}
	else{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		
		for (i=min; i <= max; ++i)
		{
			snprintf(cmd,sizeof(cmd),"convert %sDSC_0%d.NEF %sDSC_0%d.jpg",argv[3],i,argv[3],i);  /*if you want to change the
																						name of the file simply change the DSC part*/
		
		system(cmd);//run the command

		
		}
		

	}

	

	return 0;
}


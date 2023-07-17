#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

char* receiver()
{
    void *shared_mem;
    char buff[100];
    int shmid;

    shmid=shmget((key_t) 1122, 1024, 0666|IPC_CREAT);
    shared_mem=shmat(shmid,NULL,0);
    
    return((char *) shared_mem);
  
}

void deStuffer()
{
    char *message=receiver();
  
    
     int count=0,j=0;
    char destuff[100];
    for(int i=0;i<strlen(message);i++)
    {
        if(message[i]=='1')
        {
            count++;
        }
        else{
            count=0;
        }

        destuff[j]=message[i];
        j++;

        if(count==5)
        {
            i++;
            count=0;
        }

    }
       printf("Received Message: %s",destuff);
}

int main()
{
    deStuffer();
}
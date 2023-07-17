#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

void sender(char buff[])
{
    void *shared_mem;
    int shmid;

    shmid=shmget((key_t) 1122, 1024, 0666|IPC_CREAT);
    shared_mem=shmat(shmid,NULL,0);
    // read(0,buff,100);
    strcpy(shared_mem,buff);
    printf("MESSAGE SENT: %s",(char *)shared_mem);
}

void bitStuffer()
{
    int N,i;
	char Data[100],stuffedData[100];
	
	printf("ENTER YOUR DATA: ");
	scanf("%s",&Data);
	
	
	int cnt=0,j=0;
	for(i=0;i<strlen(Data);i++)
	{
		if(Data[i]=='1')
		{
			cnt++;
		}
		else
		{
			cnt=0;
		}
		stuffedData[j]=Data[i];
		j++;
		
		if(cnt==5 && Data[i+1]=='1')
		{
			stuffedData[j]='0';
			j++;
			cnt=0;
		}
	}
    stuffedData[i]='\0';

    sender(stuffedData);
}

int main()
{
    bitStuffer();
}
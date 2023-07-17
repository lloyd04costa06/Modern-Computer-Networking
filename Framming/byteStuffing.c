#include<stdio.h>
#include<string.h>


void ByteStuffing()
{
    char data[100],stuffed[100];

    printf("ENTER YOUR DATA: ");
    scanf("%s",&data);

    int j=0;
    stuffed[j]='F'; //put ur flag at the start
    j++; //move to next postion of stuffed array

    for(int i=0;i<strlen(data);i++)
    {
        if(data[i]=='E') 
        {
            stuffed[j]='E';
            j++;
            stuffed[j]='E';
            j++;
        }
        else if(data[i]=='F')
        {
            stuffed[j]='E';
            j++;
            stuffed[j]='F';
            j++;
        }
        else{
            stuffed[j]=data[i];
            j++;
        }
    }

    stuffed[j]='F';
    stuffed[j+1]='\0';

    printf("STUFFED MESSAGE: %s",stuffed);
    byteUnstuffer(stuffed);
    
}

void byteUnstuffer(char stuffed[])
{
    char destuffed[100];
    int j=0;

    for(int i=0; i<strlen(stuffed);i++)
    {
        if (i==0 || i==strlen(stuffed)-1)
        {continue;}

        if(stuffed[i]=='E' && stuffed[i+1]=='E')
        {
            destuffed[j]='E';
            j++;
            i++;
        }
        else if(stuffed[i]=='E' && stuffed[i+1]=='F')
        {
             destuffed[j]='F';
            j++;
            i++;
        }
        else{
            destuffed[j]=stuffed[i];
            j++;
        }
    }
    destuffed[j]='\0';


    printf("\nReceived Messg: %s\n",destuffed);
}


int main()
{
    ByteStuffing();
}
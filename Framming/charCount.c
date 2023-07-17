#include<stdio.h>
#include<string.h>
#define FRAMESIZE 7
void sender()
{
    char data[100],stuffed[100],j=0;

    printf("ENTER YOUR DATA: ");
    scanf("%s",&data);

    int dsize=strlen(data);
    int fsize;
    printf("ENTR FRAME SIZE: ");
    scanf("%d",&fsize);
    int f=fsize;

    int tframe=fsize-1;
    int totFrames=(dsize/tframe)+1;
    

    for(int i=0;i<totFrames+dsize;i++)
    {
       if(i%fsize==0)
       {
        if((dsize-j)<fsize)
        {
            fsize=dsize-j+1;
        }
        stuffed[i]=(char)(48+fsize);
        fsize=f;
       }
       else{
        stuffed[i]=data[j];
        j++;
       }
    }
    stuffed[totFrames+dsize]='\0';
    printf("Stuffed Data %s",stuffed);
    destuffer(stuffed,fsize);
}

void destuffer(char stuffeddata[],int fsize)
{
    char destuff[100];
    int j=0;
    for(int i=0;i<strlen(stuffeddata);i++)
    {
        if(i%fsize!=0) //avery stuffed count u ignore and insert the others to new array and increase its counter
        {
            destuff[j]=stuffeddata[i];
            j++;
        }
    }

    printf("\nAFTER DESTUFFING: %s",destuff);
}
int main()
{
    sender();
}
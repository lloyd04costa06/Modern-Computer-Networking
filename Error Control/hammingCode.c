#include<stdio.h>

void HammingEncoder()
{
    int data[10];
    printf("ENTER THE 4 BITS: ");
    scanf("%d",&data[3]);
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);
    scanf("%d",&data[7]);

    data[1]=data[3]^data[5]^data[7];
    data[2]=data[3]^data[6]^data[7];
    data[4]=data[5]^data[6]^data[7];
    printf("ENCODED HAMMING: ");
    for(int i=1;i<8;i++)
    {
        printf("%d ",data[i]);
    }

    
}

void HammingDecoder()
{
    int rec[10];
    printf("\nENTER THE RECIEVED DATA: ");
    for(int i=1;i<8;i++)
    {
        scanf("%d",&rec[i]);
    }

    int c1=rec[1]^rec[3]^rec[5]^rec[7];
    int c2=rec[2]^rec[3]^rec[6]^rec[7];
    int c3=rec[4]^rec[5]^rec[6]^rec[7];

    int c=c3*4 + c2*2 + c1* 1;

    if(c==0)
    {
        printf("NO ERROR IN CODE\n");
    }
    else{
        printf("ERROR AT POSITION %d",c);

        rec[c]=!rec[c];
        printf("CORRECT HAMMING: ");
    for(int i=1;i<8;i++)
    {
        printf("%d ",rec[i]);
    }

    }


}
int main()
{
    HammingEncoder();
    HammingDecoder();
    

}

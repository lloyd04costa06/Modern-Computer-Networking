#include<stdio.h>
#include<string.h>

int main()
{
    char bin1[100],bin2[100];
    char checksum[100], complement[100],sum[100];

    printf("ENTER THE 1ST BIINARY DATA STRING: ");
    scanf("%s",&bin1);

     printf("ENTER THE 2nd BIINARY DATA STRING: ");
    scanf("%s",&bin2);

    if(strlen(bin1) == strlen(bin2))
    {
        int length=strlen(bin1);
        int carry=0;

        for(int i=length-1; i>=0; i--)
        {
            int bits1= bin1[i]-'0'; //converting char to int
            int bits2= bin2[i]-'0';

            int temp= bits1 ^ bits2 ^ carry;
            sum[i]=temp+'0'; ///converting int to char
            carry=( (bits1 & bits2) | (bits1 & carry) | (bits2 & carry) );
        }

        printf("THE SUM IS: %d%s",carry,sum);

        for(int i=0; i<length;i++)
        {

            if (sum[i]=='0')
            {complement[i]='1';}
            else
            {complement[i]='0';}

            //or u can write in one line complement[i]=(sum[i]=='0')? '1':'0';

        }

        printf("\nCheckSum is: %d%s",1-carry,complement);


    }
    else{
        printf("WRONG INPUT STRING\n");
    }

}
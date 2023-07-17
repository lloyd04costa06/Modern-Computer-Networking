#include<stdio.h>
#include<string.h>
char data[100];

void Manchester_encoding()
{
    char Manchester[100];
    int j=0,i;
    for(i=0;i<strlen(data);i++)
    {
        if(data[i]=='0') //if bit is zero, u have to push 1 and then 0
        {
            Manchester[j]='1';
            j++;
            Manchester[j]='0';
            j++;
        }
        else if(data[i]=='1')  //if bit is 1, u have to push 0 and then 1
        {
            Manchester[j]='0';  //push 0 in current loc
            j++;                //go to next loc
            Manchester[j]='1'; //push 1 in the loc
            j++;                //go to next loc and keep it ready for future
        }

    }
    Manchester[j]='\0';
    printf("MANCHESTER ENCODING: %s",Manchester);

}

void Diff_Manchester_encoding()
{
    char prev_bit='1';
    char Diff_Man[100];
    int j=0,i;

    for(i=0;i<strlen(data);i++)
    {
       if(data[i]=='1') //current bit  is 1
       {
         if(prev_bit =='0') 
         {
            Diff_Man[j]='0'; 
            j++;
            Diff_Man[j]='1';
            j++;

            prev_bit='1';
         }
         else{
            Diff_Man[j]='1';
            j++;
            Diff_Man[j]='0';
            j++;

            prev_bit='0';
         }
       }
       else{
            if(prev_bit =='0')
         {
            Diff_Man[j]='1';
            j++;
            Diff_Man[j]='0';
            j++;

            prev_bit='0';
         }
         else{
            Diff_Man[j]='0';
            j++;
            Diff_Man[j]='1';
            j++;

            prev_bit='1';
         }
       }
    }
   Diff_Man[j]='\0';
    printf("\nDIFFERENTIAL MANCHESTER ENCODING: %s",Diff_Man);
}

int main()
{
    printf("ENTER THE BINARY DATA: ");
    scanf("%s",&data);

    Manchester_encoding();
    Diff_Manchester_encoding();
}
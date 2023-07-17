
/*Steps to perform CRC
1) Input the Data and Polynomial (both strings)
2) create CRC fucntion
3) Following are the steps to be taken isnide CRC fucntion
   a) Find the length of data and generator strings
   b) Add trailing zeros to data, (size of Generator string)-1 zeros shld be added
   c) Creat a new string variable named check;
   d) Copy content of data into check string. (How much ti copy? just generatorLength bits only shld be copied)
   e) Now run the for loop
   f) inside for loop check if the value is 1, then do XOR()
   g) now move the bits left position by 1
   h) now just add the next bit inside the check to move ahead
*/

#include<stdio.h>
#include<string.h>
 char data[100],gen[10];
char check[100];

void XOR(char check_val[], char gen[])
{
    for(int i=0; i<strlen(gen);i++)
    {
        check_val[i]= ((check_val[i]==gen[i])? '0':'1');
    }
}

void CRC()
{
    int dLen=strlen(data);
    int gLen=strlen(gen);

    // Add your trailing zeros
    for(int i=0;i<gLen-1;i++)
    {
        data[dLen+i]='0';
    }

     
    strncpy(check,data,gLen); //copy the bits to check

    for(int i=0;i<dLen;i++)
    {
        if(data[i]=='1') //if its 1 then xor
        {
            XOR(check,gen);
        }

        for(int j=0;j<gLen-1;j++) //move left by 1 position
        {
            data[j]=data[j+1];
        }

        check[gLen-1]=data[i+gLen]; //add the next bit 
    }

    printf("CRC: %s",check);
}


void sender()
{
   
    printf("ENTER THE DATA: ");
    scanf("%s",&data);

    printf("ENTER THE GENERATING POLYNOMIAL: ");
    scanf("%s",&gen);

    CRC();
}

void receiver()
{
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\n\n");
    printf("Data received: %s\n", data);

    // Cyclic Redundancy Check
    crc();

    // Check if the remainder is zero to find the error
    if (strncmp(check, "0", strlen(gen)) != 0)
        printf("\nError detected\n\n");
    else
        printf("\nNo error detected\n\n");
}

void reciever()
{

}
int main()
{
    sender();
}
#include<stdio.h>
#define MAX 20

int N;
int COST[MAX][MAX];

struct NODE{
    unsigned distance[MAX];
    unsigned from[MAX];
}NODE_INFO[100];

void input()
{
    printf("ENTER NUMBER OF NODES: ");
    scanf("%d",&N);

    printf("ENTER THE COST MATRIX: ");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&COST[i][j]);
            COST[i][i]=0;
            NODE_INFO[i].distance[j]=COST[i][j];
            NODE_INFO[i].from[j]=j;
        }

    }

}

void DIST_VEC()
{
    int count;
    do{
        count=0;
         for(int i=0;i<N;i++)
         {
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    if(NODE_INFO[i].distance[j] > COST[i][k] + NODE_INFO[k].distance[j] )
                    {
                            NODE_INFO[i].distance[j]=NODE_INFO[i].distance[k] + NODE_INFO[k].distance[j];
                            NODE_INFO[i].from[j]=k;
                            count++;
                    }
                }
            }
        }
    }while(count!=0);
   
}

void print()
{
    for(int i=0;i<N;i++)
    {
        printf("ROUTER: \n",i+1);
        for(int j=0;j<N;j++)
        printf("Node %d via %d Distance %d\n",j+1,NODE_INFO[i].from[j]+1,NODE_INFO[i].distance[j]);
    }
}


int main()
{
  input();
  DIST_VEC();
  print();
}
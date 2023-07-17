#include<stdio.h>
#define MAX 20

int N;
int COST[100][100];

struct NODE{
    int cost[MAX];
    int visited;
   
}ROUTER[100];

void input()
{
    printf("ENTER NUMBER OF NODES: ");
    scanf("%d",&N);

    printf("ENTER THE COST MATRIX: (ENTER 9999 for no connection)");

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&COST[i][j]);
          
            ROUTER[i].cost[j]=COST[i][j];
            ROUTER[i].visited=0;
        }
    }
   

}

void LINK_STATE()
{
    int src;

    //Initialize all routers
    for(int i=0;i<N;i++)
    {
        ROUTER[i].cost[i]=0;
        ROUTER[i].visited=0;
    }

    //set the source router visited
    printf("ENTER SOURCE NODE: ");
    scanf("%d",&src);

    ROUTER[src].visited=1;

    for(int i=0;i<N;i++)
    {
        int minCost=9999;
        int minRouter=-1;

        //Find router with minimum cost
        for(int j=0;j<N;j++)
        {
            if(!ROUTER[i].visited && ROUTER[i].cost[i] <=minCost)
            {
                minCost=ROUTER[i].cost[i];
                minRouter=i;
            }
        }

        //Mark the miuimum cost router as visted
        ROUTER[minRouter].visited=1;

        //Upte the cost of adjacent nodes
        for(int j=0;j<N;j++)
        {
            if(!ROUTER[i].visited && ROUTER[i].cost[i] && ROUTER[minRouter].cost[i] + ROUTER[minRouter].cost[minRouter] <ROUTER[i].cost[i])
            {
                ROUTER[i].cost[i]=ROUTER[minRouter].cost[i] + ROUTER[minRouter].cost[minRouter];
            }
        }
    }
}

void print()
{
    for(int i=0;i<N;i++)
    {
        printf("Router: %d\n",i+1);
        for(int j=0;j<N;j++)
        {
            printf("Router %d with path %d\n",j+1,ROUTER[i].cost[j]);
        }
    }
}
int main()
{
    input();
    LINK_STATE();
    print();
}
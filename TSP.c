#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void TSP(pnode head)
{
	int arrlength = -1;
    pnode graph = head;
    scanf("%d", &arrlength);

    int *arr = (int *)(calloc(arrlength, sizeof(int)));
    for (int i = 0; i < arrlength; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int j, i, temp0;
    int bestpath; //currentpath;
    //int Pathexists, pathFound; //flags
    int pathFound = 0;
    bestpath = 999999;

    for(j=1; j <= arrlength; j++){

        for(i=0; i < arrlength-1; i++){

            temp0=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp0;
              
            //one more loop that goes over all given nodes and finds shortest path between each node
            int currentpath = 0;
            int Pathexists = 1;
            for(int node = 0; node<arrlength-1;  node++){
                int dijk = shortsPath_cmd(graph, *(arr+node), *(arr+(node+1)));
                if (dijk == -1)
                   Pathexists = 0;
                currentpath += dijk;
            }
             //finds best solution

            if (Pathexists && (currentpath < bestpath)){
                bestpath = currentpath;
                pathFound = 1;
            }
        }
    }
    if(!pathFound){
        bestpath = -1;
    }  

    printf("TSP shortest path: %d \n",bestpath);

    //free the memory
    free(arr);
}

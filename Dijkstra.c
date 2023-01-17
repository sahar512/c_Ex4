#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pDnode buildDijkstra_NodeList(pnode start, int src){
    pDnode head =NULL; 
    pDnode *index = &head; 
    while (start!=NULL)
    {
        (*index)=(pDnode)malloc(sizeof(Dnode)); 
        if((*index)==NULL){
            perror("there is no enough space to create dijkstra strct"); 
            exit(0);
        }
        (*index)->node=start; 
        if(start->node_num==src){
            (*index)->weight=0; 
        }
        else{
           // (*index)->dd = NULL;
            (*index)->weight=INFINITY; 
        }
        (*index)->isUse=0;
        (*index)->next=NULL; 
        index=&((*index)->next); 
        start=start->next; 
    }
    return head; 
}
void deleteDijkstra(pDnode Dij){
    while(Dij!=NULL){
        pDnode timp = Dij; 
        Dij =Dij->next; 
        free(timp); 
    }
}
pDnode getpointerDij(pDnode Dij, int w ){
    while(Dij!=NULL){
        if (Dij->node->node_num==w){
            return Dij; 
        }
        Dij=Dij->next;
    }
    return NULL; 
}
pDnode MinDij(pDnode head){
    pDnode s =NULL; 
    while(head!=NULL){
        if(!head->isUse && head->weight<INFINITY &&(s==NULL||s->weight< head->weight)){
            s=head; 
        }
        head=head->next; 
    }
    if(s!=NULL){
        s->isUse=1; 
    }
    return s; 
}
int shortsPath_cmd(pnode head, int src,int dest){
    pDnode Dij=buildDijkstra_NodeList(head,src);
    pDnode a=MinDij(Dij); 
    while (a !=NULL)
    {
        pedge eIndex = a->node->edges; 
        while (eIndex !=NULL)
        {
            pDnode v =getpointerDij(Dij,eIndex->endpoint->node_num); 
            int nDist=a->weight + eIndex->weight; 
            if(v->weight > nDist){
                v->weight=nDist; 
              //  v->dd = a; 
            }
            eIndex=eIndex->next; 
        }
        a=MinDij(Dij);
    }
    int dis =getpointerDij(Dij,dest)->weight; 
    dis=(dis==INFINITY)?-1:dis;
    deleteDijkstra(Dij); 
    return dis; 
}

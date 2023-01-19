#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head); 
    int size=0; 
    scanf("%d", &size); 
    char b='B';
    scanf("%c",&b);
    for(int i=0;i<size;i++){
        scanf("%c",&b); 
        insert_node_cmd(head); 
    } 
}
void insert_node_cmd(pnode *head){
    int d=-1; 
    scanf("%d",&d);
    pnode s = getNode(head,d); 
    if (s==NULL){
        s = (pnode)malloc(sizeof(node));
        //s =malloc(sizeof(node));
        if (s==NULL){
            return; 
        }
        s->node_num=d; 
        s->next=*head; 
        s->edges=NULL;
        *head=s; 
    }
    else{
        pedge index =s->edges; 
        while (index!=NULL)
        {
            pedge timp0= index->next;
            free(index); 
            index=timp0; 
        }
        s->edges=NULL; 
        
    }
    pedge *lastE =&(s->edges);
    int dest =-1; 
    int done=scanf("%d",&dest);
    while(done!=0 && done!=EOF){
        pnode dnode = getNode(head,dest); 
        if(dnode==NULL){
            dnode=(pnode)malloc(sizeof(node));
            //dnode=malloc(sizeof(node));
            if(dnode==NULL){
                return;
            }
            dnode->node_num=dest; 
            dnode->edges=NULL; 
            dnode->next=*head;
            *head=dnode;
        }
        int w =-1; 
        scanf("%d",&w);
        *lastE=(pedge)malloc(sizeof(edge));
        if((*lastE)==NULL){
            return;
        }
        (*lastE)->endpoint=dnode;
        (*lastE)->weight=w;
        (*lastE)->next=NULL;
        lastE=&((*lastE)->next);
        done=scanf("%d",&dest);
    }
}
pnode getNode(pnode *head, int id){
    pnode index= *head; 
    // if(index==NULL){
    //     return NULL; 
    // }
    // else{
    //     if(index->node_num!=d){
    //         index=index->next;
    //     }
    //     return index; 
    // }
    while (index!=NULL)
    {
        if(index->node_num==id){
            return index; 
        }
        index=index->next; 
    }
    return NULL; 
}
void deleteGraph_cmd(pnode*head){
    // pnode nIndex = *head; 
    // if (nIndex==NULL){
    //     *head=NULL; 
    // }
    // pedge eIndex=nIndex->edges; 
    // while(eIndex!=NULL){
    //     pedge eIndex=nIndex->edges; 
    //     pedge timp1= eIndex ;
    //     eIndex=eIndex->next; 
    //     free(timp1);
    // }
    // pnode temp1=nIndex; 
    // nIndex=nIndex->next; 
    // free(temp1); 
    pnode nIndex = *head; 
    while(nIndex!=NULL){
        pedge eIndex=nIndex->edges; 
        while(eIndex!=NULL){

            //pedge eIndex=nIndex->edges; 
            pedge timp1= eIndex ;
            eIndex=eIndex->next; 
            free(timp1);
        }
        pnode temp1=nIndex; 
        nIndex=nIndex->next; 
        free(temp1); 
    }
    *head=NULL;
} 
void delete_node_cmd(pnode *head){
    int k=-1; 
    scanf("%d",&k); 
    pnode nIndex=*head; 
    pnode *isFirst=NULL; 
    pnode pAns=NULL; 
    if(nIndex->node_num==k){
        isFirst=head; 
    }
    while(nIndex!=NULL){
        if(nIndex->next!=NULL&& nIndex->next->node_num==k){
            pAns=nIndex;
        }
        if(nIndex->edges!=NULL && nIndex->edges->endpoint->node_num==k){
            pedge timp3=nIndex->edges; 
            nIndex->edges=nIndex->edges->next;
            free(timp3); 
            nIndex=nIndex->next;
            continue;  
        }
        pedge eIndex=nIndex->edges; 
        if(eIndex!=NULL){
            while (eIndex->next !=NULL)
            {
                //pedge e =eIndex->next; 
                if(eIndex->next->endpoint->node_num==k){
                    pedge timp3=eIndex->next; 
                    eIndex->next=timp3->next;
                    free(timp3) ; 
                }
                else{
                    eIndex=eIndex->next;
                }
                
            }
            
        }
        nIndex=nIndex->next; 

    }
    if(isFirst!=NULL){
        pedge eIndex=(*isFirst)->edges; 
        while(eIndex!=NULL){
            pedge timp3=eIndex; 
            eIndex =eIndex->next; 
            free(timp3); 
        }
        pnode timp3=*isFirst; 
        *isFirst=timp3->next; 
        free(timp3); 
    }
    else if(pAns!=NULL){
        pnode remove=pAns->next; 
        pedge eIndex=remove->edges; 
        while(eIndex!=NULL){
            pedge timp3=eIndex; 
            eIndex=eIndex->next; 
            free(timp3); 
        }
        pAns->next=remove->next; 
        free(remove); 
    }
}  
void printGraph_cmd(pnode head)
{
    pnode nodeIndex = head;
    while (nodeIndex != NULL)
    {
        printf("Node %d: ", nodeIndex->node_num);
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            printf("dest %d: weight %d, ", edgeIndex->endpoint->node_num, edgeIndex->weight);
            edgeIndex = edgeIndex->next;
        }
        printf("\n");
        nodeIndex = nodeIndex->next;
    }
}
 
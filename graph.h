#ifndef GRAPH_
#define GRAPH_
#define INFINITY 10000000

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Dijkstra_Node{
    pnode node; 
    struct Dijkastra_Node *dd; 
    int weight; 
    int isUse; 
    struct Dijkstra_Node *next; 
}Dnode, *pDnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head,int src,int dest);
void TSP(pnode head);
pnode getNode(pnode *head, int id);  

#endif
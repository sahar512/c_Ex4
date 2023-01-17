#include <stdio.h>
#include "graph.h"
int main()
{
    char choice = '\0';
    pnode timp = NULL;
    pnode *head = &timp;
    while (scanf("%c", &choice) != EOF)
    {
        if (choice == 'A')
        {
            build_graph_cmd(head);
        }
        else if (choice == 'B')
        {
            insert_node_cmd(head);
        }
        else if (choice == 'D')
        {
            delete_node_cmd(head);
        }
        else if (choice == 'S')
        {
            int s = -1, d = -1;
            scanf("%d %d", &s, &d);
            int dis = shortsPath_cmd(*head, s, d);
            printf("Dijsktra shortest path: %d \n", dis);
        }
        else if (choice == 'T') {
            TSP(*head);
            
        }
    }
    deleteGraph_cmd(head);
    return 0;
}
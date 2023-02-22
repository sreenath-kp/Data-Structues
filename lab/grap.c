#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int value;
    struct Edge *link;
} vertex;

typedef struct Edge
{
    struct graph *dest;
    struct Edge *next;
} edge;
vertex *graph[20];
int adjmat[20][20],vertices[20],n;

void addVertex(int item)
{
    vertex *new = (vertex *)malloc(sizeof(vertex));
    new->value = item;
    new->link = NULL;
    int i = 0;
    if (graph[0] == NULL)
    {
        graph[0] = new;
    }
    else
    {
        while (graph[i] != NULL)
        {
            i++;
        }
        graph[i] = new;
    }
}

void insertvertices(int i)
{
    int data;
    scanf("%d",&data);
    vertices[i] = data;
    addVertex(data);

}
void displayvertices()
{
    for (int i = 0; i < n ; i++)
    {
        printf("%d ",vertices[i]);
    }
    printf("\n");
}
void buildmat(int o,int p)
{
    int i,j,k;
    for (int i = 0; i < n; i++)
    {
        if (vertices[i] == p)
        {
            k = i;
        }
        
    }
    for (int j = 0; j < n; j++)
    {
        if (vertices[j] == o)   
        {
            adjmat[k][j] = 1;
        }
        
    }
    
    
}
void display_adjmat()
{
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%d  ", vertices[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", vertices[i]);
        for (int j = 0; j < n; j++)
            printf("%d  ", adjmat[i][j]);
        printf("\n");
    }
    printf("\n");
}
vertex *searchdest(int key)
{
    int i;
    for ( i = 0; graph[i] != NULL; i++)
        if (graph[i]->value == key)
            return graph[i];
    if (graph[i] == NULL)
        printf("Not found\n");
}
void linking()
{
    int e,key;
    edge* prev;
    for (int i = 0; graph[i] != NULL; i++)
    {
       printf("\nHow many edges do %d have : ", graph[i]->value);
        scanf("%d", &e);
        if (e>=1)
        {
            printf("Enter edge 1 of %d : ", graph[i]->value);
            scanf("%d", &key);
            buildmat(key, graph[i]->value);
            edge* new = (edge *)malloc(sizeof(edge));
            new->dest = searchdest(key);
            new->next = NULL;
            graph[i]->link = new;
            prev = new;
        }
        for (int i = 1; i < e; i++)
        {
            printf("Enter edge %d of %d : ", i + 1, graph[i]->value);
            scanf("%d", &key);
            buildmat(key, graph[i]->value);
            edge *newl = (edge *)malloc(sizeof(edge));
            newl->dest = searchdest(key);
            newl->next = NULL;
            prev->next = newl;
            prev = newl;
        }
        
    }
    
}
void main()
{
    int op = 1, c;
    while (op)
    {
        printf("MENU\n");
        printf("1.Insert \n2.DFS\n3.BFS\n4.EXIT\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            printf("Enter no of vertices : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    adjmat[i][j] = 0;
            printf("Enter vertices : ");
            for (int i = 0; i < n; i++)
                insertvertices(i);
            printf("Vertices : ");
            displayvertices();
            linking();
            printf("Adjacency matrix :\n");
            display_adjmat();

            break;
        }

        case 2:
        {
            // dfs();
            break;
        }

        case 3:
        {
            // bfs();
            break;
        }

        case 4:
            op = 0;
            printf("Exiting\n");
            break;

        default:
            printf("INVALID INPUT !!! \n");
            break;
        }
    }
    printf("\n");
}
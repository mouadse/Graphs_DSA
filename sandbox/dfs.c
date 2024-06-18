#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Node {
  int vertex;
  struct Node *next;
} node;

typedef struct Graph {
  int num_of_vertices;
  node **adj_list;
  int *visited;
} Graph;

Graph *createGraph(int);
void addEdge(Graph *, int, int);
void printGraph(Graph *);
void dfs(Graph *, int);

node *create_node(int val);

int main(void) {

  Graph *graph = createGraph(9);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 5);
  addEdge(graph, 3, 6);
  addEdge(graph, 6, 7);
  addEdge(graph, 6, 8);
  addEdge(graph, 7, 8);
  printf("DFS from 0 is:\n");
  dfs(graph, 0);
  printf("\n");
  return (EXIT_SUCCESS);
}

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  assert(n != NULL);
  n->next = NULL;
  n->vertex = val;
  return (n);
}

Graph *createGraph(int num_of_vertices) {
  Graph *g = malloc(sizeof(Graph));
  assert(g != NULL);
  g->num_of_vertices = num_of_vertices;
  g->adj_list = malloc(sizeof(node) * num_of_vertices);
  assert(g->adj_list != NULL);
  g->visited = malloc(sizeof(int) * num_of_vertices);
  assert(g->visited != NULL);
  int i;
  for (i = 0; i < num_of_vertices; i++) {
    g->visited[i] = 0;
    g->adj_list[i] = NULL;
  }
  return (g);
}

void addEdge(Graph *g, int src, int dst) {
  node *n = create_node(src);
  n->next = g->adj_list[dst];
  g->adj_list[dst] = n;

  n = create_node(dst);
  n->next = g->adj_list[src];
  g->adj_list[src] = n;
}

void printGraph(Graph *g) {
  assert(g != NULL);
  int v;
  for (v = 0; v < g->num_of_vertices; v++) {
    node *tmp = g->adj_list[v];
    printf("Node of the following vertex are %d\n", v);
    while (tmp != NULL) {
      printf("%d -> ", tmp->vertex);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

void dfs(Graph *g, int vertex) {
  assert(g != NULL);
  node *adj_list = g->adj_list[vertex];
  node *tmp = adj_list;
  g->visited[vertex] = 1;
  printf("%d ", vertex);
  while (tmp) {
    int connected_vertex = tmp->vertex;
    if (!g->visited[connected_vertex])
      dfs(g, connected_vertex);
    tmp = tmp->next;
  }
}

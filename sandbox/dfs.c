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
  printf("Hello World!!!\n");
  return (EXIT_SUCCESS);
}

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  assert(n != NULL);
  n->next = NULL;
  n->vertex = val;
  return (n);
}

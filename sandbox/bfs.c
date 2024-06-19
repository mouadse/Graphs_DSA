#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 42

typedef struct Queue {
  int items[SIZE];
  int front;
  int rear;
} queue;

typedef struct Node {
  int vertex;
  struct Node *next;
} node;

typedef struct Graph {
  int *visited;
  node **adjList;
  int num_of_vertices;
} graph;

// Function signatures
node *create_node(int val);
graph *create_graph(int vertices);
void addEdge(graph *g, int src, int dst);
queue *create_queue();
void enqueue(queue *q, int ver);
int isEmpty(queue *q);
int dequeue(queue *q);
int poolQueue(queue *q);
void bfs(graph *g, int startVertex);

int main(void) {
  // code goes here

  return (EXIT_SUCCESS);
}

// Function definitions

void bfs(graph *g, int startVertex) {
  queue *q = create_queue();
  g->visited[startVertex] = 1;
  enqueue(q, startVertex);
  printf("BFS from %d\n", startVertex);
  while (!isEmpty(q)) {
    printf("%d ", poolQueue(q));
    int currentVertex = dequeue(q);
    node *tmp = g->adjList[currentVertex];
    while (tmp) {
      int adjVertex = tmp->vertex;
      if (g->visited[adjVertex] == 0) {
        g->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      tmp = tmp->next;
    }
  }
}

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  if (!n)
    return NULL;
  n->vertex = val;
  n->next = NULL;
  return n;
}

graph *create_graph(int vertices) {
  graph *g = malloc(sizeof(graph));
  g->num_of_vertices = vertices;
  g->adjList = malloc(sizeof(node *) * vertices);
  g->visited = malloc(sizeof(int) * vertices);

  for (int i = 0; i < vertices; i++) {
    g->visited[i] = 0;
    g->adjList[i] = NULL;
  }
  return g;
}

void addEdge(graph *g, int src, int dst) {
  node *n = create_node(src);
  n->next = g->adjList[dst];
  g->adjList[dst] = n;

  n = create_node(dst);
  n->next = g->adjList[src];
  g->adjList[src] = n;
}

queue *create_queue() {
  queue *q = malloc(sizeof(queue));
  if (!q)
    return NULL;
  q->front = -1;
  q->rear = -1;
  return q;
}

void enqueue(queue *q, int ver) {
  assert(q != NULL);
  if (q->rear == SIZE - 1)
    printf("The queue is full\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = ver;
  }
}

int isEmpty(queue *q) { return (q->rear == -1); }

int dequeue(queue *q) {
  int value = -1;
  assert(q != NULL);
  if (isEmpty(q)) {
    printf("The queue is empty!!!\n");
    return value;
  } else {
    value = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
      q->front = q->rear = -1;
  }
  return value;
}

int poolQueue(queue *q) { return (q->items[q->front]); }

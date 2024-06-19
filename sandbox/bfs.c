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

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  if (!n)
    return (NULL);
  n->vertex = val;
  n->next = NULL;
  return (n);
}

queue *create_queue() {
  queue *q = malloc(sizeof(queue));
  if (!q)
    return (NULL);
  q->front = -1;
  q->rear = -1;
  return (q);
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
    printf("The queue is isEmpty!!!\n");
    return (value);
  } else {
    value = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
      q->front = q->rear = -1;
  }
  return (value);
}

int poolQueue(queue *q) { return (q->items[q->front]); }

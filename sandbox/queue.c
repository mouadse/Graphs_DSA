#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct QueueRep {
  int len;
  Node *head;
  Node *tail;
} QueueRep;

QueueRep *setup_queue() {
  QueueRep *Q = malloc(sizeof(QueueRep));
  assert(Q != NULL);
  Q->len = 0;
  Q->head = Q->tail = NULL;
  return (Q);
}

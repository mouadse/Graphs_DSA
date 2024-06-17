#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {

  int val;
  struct Node *next;
} node;

typedef struct Queue {
  int length;
  node *head;
  node *tail;
} queue;

queue *create();
void enqueue(queue *q, int x);
int deque(queue *q);
int peek();
int size();
int isEmpty(queue *q);
node *create_node(int value);
void dropQueue(queue *q);
#endif

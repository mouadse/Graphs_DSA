#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct s_node {
  int val;
  struct s_node *next;
} node;

typedef struct s_queue {
  int size;
  node *front;
  node *rear;
} queue;

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  if (!new_node)
    return (NULL);
  new_node->val = data;
  new_node->next = NULL;
  return (new_node);
}

queue *create_queue() {
  queue *new_queue = malloc(sizeof(queue));
  if (!new_queue)
    return (NULL);
  new_queue->size = 0;
  new_queue->front = new_queue->rear = NULL;
  return (new_queue);
}

int is_empty(queue *mQueue) {
  if (!mQueue || !mQueue->front)
    return (1);
  return (0);
}

void enqueue(queue *mQueue, int data) {
  if (!mQueue)
    return;

  node *new_node = create_node(data);

  if (is_empty(mQueue)) {
    mQueue->front = mQueue->rear = new_node;
  } else {
    mQueue->rear->next = new_node;
    mQueue->rear = new_node;
  }
  mQueue->size++;
}

int dequeue(queue *ourQueue) {
  int data = 0;
  if (!ourQueue || is_empty(ourQueue))
    return (-1);
  node *tmp = ourQueue->front;

  if (ourQueue->front == ourQueue->rear)
    ourQueue->front = ourQueue->rear = NULL;
  else {
    ourQueue->front = tmp->next;
  }
  data = tmp->val;
  free(tmp);
  ourQueue->size--;
  return (data);
}

int main(void) {
  queue *ourQueue = create_queue();

  enqueue(ourQueue, 1);
  enqueue(ourQueue, 2);
  enqueue(ourQueue, 3);
  enqueue(ourQueue, 4);
  enqueue(ourQueue, 5);
  enqueue(ourQueue, 6);
  enqueue(ourQueue, 7);
  enqueue(ourQueue, 8);

  while (ourQueue->size) {
    int val = dequeue(ourQueue);
    printf("The val is %d\n", val);
  }
  free(ourQueue);
  return (EXIT_SUCCESS);
}

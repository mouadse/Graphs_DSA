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

// Let's implement BFS first

void BFS(int G[][7], int start, int n) {
  queue *ourQueue = create_queue();
  static int visited[7] = {0};
  int i = start;
  printf("%d\n", i);
  visited[i] = 1;
  enqueue(ourQueue, i);
  while (!is_empty(ourQueue)) {
    i = dequeue(ourQueue);
    for (int j = 0; j < n; j++) {
      if (G[i][j] == 1 && visited[j] == 0) {
        printf("%d\n", j);
        visited[j] = 1;
        enqueue(ourQueue, j);
      }
    }
  }
}

// Let's implement a DFS algorithm now

void DFS(int G[][7], int start, int n) {
  static int visited[7] = {0};
  if (visited[start] == 0) {
    printf("%d\n", start);
    visited[start] = 1;
    for (int j = 1; j < n; j++) {
      if (G[start][j] == 1 && !visited[j])
        DFS(G, j, n);
    }
  }
}

int main(void) {
  int G[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},
                 {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
                 {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0, 0}};
  printf("This is DFS: \n");
  DFS(G, 3, 7);
  printf("This is BFS: \n");
  BFS(G, 3, 7);
  return (EXIT_SUCCESS);
}

#include "queue.h"
#include <assert.h>
#include <stdio.h>

int count; // this is a global var

int main(void) {
  queue *q = malloc(sizeof(queue));
  if (!q)
    return (EXIT_FAILURE);
  q->head = q->tail = NULL;
  q->length = 0;
  for (int i = 0; i < 10; i++) {
    enqueue(q, i);
  }
  // dropQueue(q);
  return (EXIT_SUCCESS);
}

queue *create() {
  queue *q = malloc(sizeof(queue));
  assert(q != NULL);
  q->head = q->tail = NULL;
  q->length = 0;
  return (q);
}

void enqueue(queue *q, int x) {
  node *m_node = create_node(x);
  assert(q != NULL);
  if (q->tail != NULL) {
    q->tail->next = m_node;
    q->tail = m_node;
  } else {
    q->head = q->tail = m_node;
  }
  q->length++;
}

node *create_node(int value) {
  node *m_node = malloc(sizeof(node));
  if (!m_node)
    return (NULL);
  m_node->next = NULL;
  m_node->val = value;
  return (m_node);
}

int isEmpty(queue *q) { return (q->length == 0); }

void dropQueue(queue *q) {
  assert(q != NULL);
  node *tmp = q->head;
  while (tmp != NULL) {
    node *curr = tmp->next;
    free(tmp);
    tmp = curr;
  }
  free(q);
}

int deque(queue *q) {

  // check for NULL edge cases
  assert(q->length > 0);
  int value = -1;
  node *tmp = q->head;
  value = tmp->val;
  q->head = tmp->next;
  if (!q->head)
    q->tail = NULL;
  free(tmp);
  q->length--;
  return (value);
}

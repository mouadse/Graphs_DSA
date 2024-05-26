#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_VERTICES 100

typedef struct Node {
  int vertex;
  struct Node *next;
} node;

typedef struct Graph {
  int num_of_vertices;
  node **adj_list;
  int *visited;
} graph;

node *create_node(int v) {
  node *m_node = malloc(sizeof(node));
  if (!m_node)
    return (NULL);
  m_node->vertex = v;
  m_node->next = NULL;
  return (m_node);
}

graph *create_graph(int vertices) {
  graph *m_graph = malloc(sizeof(graph));
  if (!m_graph)
    return (NULL);
  m_graph->num_of_vertices = vertices;
  m_graph->adj_list = malloc(sizeof(node *) * vertices);
  if (!m_graph->adj_list)
    return (NULL);
  m_graph->visited = malloc(sizeof(int) * vertices);
  if (!m_graph->visited)
    return (NULL);

  for (int i = 0; i < vertices; i++) {
    m_graph->adj_list[i] = NULL;
    m_graph->visited[i] = 0;
  }
  return (m_graph);
}

// now time to add edges to our Graph dsa

void addEdge(graph *m_graph, int src, int dest) {
  node *new_node = create_node(dest);
  new_node->next = m_graph->adj_list[src];
  m_graph->adj_list[src] = new_node;

  new_node = create_node(src);
  new_node->next = m_graph->adj_list[dest];
  m_graph->adj_list[dest] = new_node;
}

// Let's add a function to print our graph for fun and visualization purposes

void printGraph(graph *m_graph) {
  for (int v = 0; v < m_graph->num_of_vertices; v++) {
    node *tmp = m_graph->adj_list[v];
    printf("\n Vertex %d: ", v);
    while (tmp != NULL) {
      if (tmp->next == NULL) {
        printf("%d", tmp->vertex);
        break;
      } else {
        printf("%d <--> ", tmp->vertex);
        tmp = tmp->next;
      }
    }
    printf("\n");
  }
}

int main(void) {

  graph *m_graph = create_graph(5);
  addEdge(m_graph, 0, 1);
  addEdge(m_graph, 0, 4);
  addEdge(m_graph, 1, 2);
  addEdge(m_graph, 1, 3);
  addEdge(m_graph, 1, 4);
  addEdge(m_graph, 2, 3);
  addEdge(m_graph, 3, 4);

  printGraph(m_graph);

  return (EXIT_SUCCESS);
}

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

// Now let's implment our DFS algo

void DFS(graph *m_graph, int vertex) {
  node *adj_list = m_graph->adj_list[vertex];
  node *temp = adj_list;

  m_graph->visited[vertex] = 1;
  printf("Visited %d\n", vertex);

  while (temp != NULL) {
    int connected_vertex = temp->vertex;
    if (m_graph->visited[connected_vertex] == 0)
      DFS(m_graph, connected_vertex);
    temp = temp->next;
  }
}

int maze[5][5] = {{0, 1, 0, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 1, 0},
                  {0, 1, 1, 1, 0},
                  {0, 0, 0, 0, 0}};

int getVertex(int row, int col, int ncols) { return row * ncols + col; }

void createGraphFromMaze(graph *graph, int maze[5][5], int nrows, int ncols) {
  for (int row = 0; row < nrows; row++) {
    for (int col = 0; col < ncols; col++) {
      if (maze[row][col] == 0) {
        if (row > 0 && maze[row - 1][col] == 0) {
          addEdge(graph, getVertex(row, col, ncols),
                  getVertex(row - 1, col, ncols));
        }
        if (row < nrows - 1 && maze[row + 1][col] == 0) {
          addEdge(graph, getVertex(row, col, ncols),
                  getVertex(row + 1, col, ncols));
        }
        if (col > 0 && maze[row][col - 1] == 0) {
          addEdge(graph, getVertex(row, col, ncols),
                  getVertex(row, col - 1, ncols));
        }
        if (col < ncols - 1 && maze[row][col + 1] == 0) {
          addEdge(graph, getVertex(row, col, ncols),
                  getVertex(row, col + 1, ncols));
        }
      }
    }
  }
}

int main(void) {

  // graph *m_graph = create_graph(5);
  // addEdge(m_graph, 0, 1);
  // addEdge(m_graph, 0, 4);
  // addEdge(m_graph, 1, 2);
  // addEdge(m_graph, 1, 3);
  // addEdge(m_graph, 1, 4);
  // addEdge(m_graph, 2, 3);
  // addEdge(m_graph, 3, 4);

  // printGraph(m_graph);
  graph *gp = create_graph(5 * 5);

  createGraphFromMaze(gp, maze, 5, 5);

  DFS(gp, getVertex(0, 0, 5));

  return (EXIT_SUCCESS);
}

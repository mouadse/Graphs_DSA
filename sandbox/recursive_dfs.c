#include <stdbool.h>
#include <stdio.h>

// Dimensions of the grid
#define ROWS 5
#define COLS 5

// Directions for moving up, down, left, and right
int rowDirections[] = {-1, 1, 0, 0};
int colDirections[] = {0, 0, -1, 1};

// Function to check if a position is within the grid and not a wall
bool isValidMove(char grid[ROWS][COLS], bool visited[ROWS][COLS], int row,
                 int col) {
  return (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
          grid[row][col] != 'W' && !visited[row][col]);
}

// DFS function to explore the grid
bool dfs(char grid[ROWS][COLS], bool visited[ROWS][COLS], int row, int col) {
  if (grid[row][col] == 'E') {
    return true;
  }

  // Mark the current cell as visited
  visited[row][col] = true;

  // Explore all four possible directions
  for (int i = 0; i < 4; i++) {
    int newRow = row + rowDirections[i];
    int newCol = col + colDirections[i];

    if (isValidMove(grid, visited, newRow, newCol)) {
      if (dfs(grid, visited, newRow, newCol)) {
        return true;
      }
    }
  }
  return false;
}

// Function to find the player's starting position and start DFS
bool findPathToExit(char grid[ROWS][COLS]) {
  bool visited[ROWS][COLS] = {false};

  // Find the player's starting position
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (grid[row][col] == 'P') {
        return dfs(grid, visited, row, col);
      }
    }
  }

  return false;
}

int main() {
  char grid[ROWS][COLS] = {{'P', '.', 'W', 'W', 'W'},
                           {'.', '.', 'W', '.', '.'},
                           {'W', '.', 'W', '.', 'W'},
                           {'W', '.', '.', '.', 'E'},
                           {'W', 'W', 'W', 'W', 'W'}};

  if (findPathToExit(grid)) {
    printf("A path to the exit exists!\n");
  } else {
    printf("No path to the exit exists.\n");
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b ? a : b); }

int DFS(int **grid, int gridSize, int h, int i, int j) {
  int ans = 1;
  grid[i][j] = 0;

  if (i > 0 && grid[i - 1][j] == 1)
    ans += DFS(grid, gridSize, h, i - 1, j);
  if (j > 0 && grid[i][j - 1] == 1)
    ans += DFS(grid, gridSize, h, i, j - 1);
  if (i < gridSize - 1 && grid[i + 1][j] == 1)
    ans += DFS(grid, gridSize, h, i + 1, j);
  if (j < h - 1 && grid[i][j + 1] == 1)
    ans += DFS(grid, gridSize, h, i, j + 1);
  return (ans);
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize) {
  int maxArea = 0;
  int h = gridColSize[0];
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < h; j++) {
      if (grid[i][j] == 1)
        maxArea = max(maxArea, DFS(grid, gridSize, h, i, j));
    }
  }
  return (maxArea);
}

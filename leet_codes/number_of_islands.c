int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(char **grid, int col, int row, int cols, int rows) {
  if (row >= 0 && col >= 0 && row < rows && col < cols &&
      grid[row][col] == '1') {
    for (int dir = 0; dir < 4; dir++) {
      DFS(grid, col + directions[dir][1], row + directions[dir][0], cols, rows);
      grid[row][col] = '0';
    }
  }
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
  int rows = gridSize;
  int cols = gridColSize[0];

  int count = 0;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (grid[row][col] == '1') {
        DFS(grid, col, row, cols, rows);
        count++;
      }
    }
  }
  return (count);
}

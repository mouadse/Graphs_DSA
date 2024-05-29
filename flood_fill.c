#include <stdio.h>

#define ROWS 8
#define COLS 8

void dfs(int image[ROWS][COLS], int x, int y, int newColor, int originalColor) {
  // Check for base cases
  if (x < 0 || x >= ROWS || y < 0 || y >= COLS ||
      image[x][y] != originalColor) {
    return;
  }

  // Replace the color
  image[x][y] = newColor;

  // Recursively apply to all 4 directions
  dfs(image, x + 1, y, newColor, originalColor);
  dfs(image, x - 1, y, newColor, originalColor);
  dfs(image, x, y + 1, newColor, originalColor);
  dfs(image, x, y - 1, newColor, originalColor);
}

void floodFillDFS(int image[ROWS][COLS], int startX, int startY, int newColor) {
  int originalColor = image[startX][startY];
  if (originalColor != newColor) {
    dfs(image, startX, startY, newColor, originalColor);
  }
}

int main() {
  int image[ROWS][COLS] = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                           {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1},
                           {0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}};

  int startX = 0, startY = 0, newColor = 2;

  floodFillDFS(image, startX, startY, newColor);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }

  return 0;
}

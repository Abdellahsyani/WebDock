#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(int ac, char **av) {
  if (ac != 4)
    return 1;

  int w = atoi(av[1]), h = atoi(av[2]), it = atoi(av[3]);
  if (w <= 0 || h <= 0 || it < 0)
    return 1;

  int board[h][w], tmp[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      board[i][j] = 0;
      tmp[i][j] = 0;
    }
  }

  int x = 0, y = 0;
  bool pen = false;
  char c;

  while (read(0, &c, 1) == 1) {
    if (c == 'w' && y > 0)
      y--;
    else if (c == 's' && y < h - 1)
      y++;
    else if (c == 'a' && x > 0)
      x--;
    else if (c == 'd' && x < w - 1)
      x++;
    else if (c == 'x')
      pen = !pen;

    if (pen)
      board[y][x] = 1;
  }

  for (int i = 0; i < it; i++) {
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        int nb = 0;
        for (int c = 0; c < 9; c++) {
          int ny = y + (c / 3) - 1;
          int nx = x + (c % 3) - 1;
          if (ny >= 0 && ny < h && nx >= 0 && nx < w)
            nb += board[ny][nx];
        }
        if (board[y][x])
          nb--;
        if (board[y][x] && (nb == 2 || nb == 3))
          tmp[y][x] = 1;
        else if (!board[y][x] && (nb == 3))
          tmp[y][x] = 1;
      }
    }
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++){
        board[y][x] = tmp[y][x];
      }
    }
  }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      putchar(board[y][x] ? 'O' : ' ');
    }
    putchar('\n');
  }
  return 0;
}

#include <stdio.h>

const int MAX_LINES = 100;

int shortest_line_index(int lines[], int n) {
  int shortest = 0;

  for (int j = 1; j < n; j++) {
    if (lines[j] < lines[shortest]) {
      shortest = j;
    }
  }

  return shortest;
}

void solve(int lines[], int n, int m) {
  for (int i = 0; i < m; i++) {
    int shortest = shortest_line_index(lines, n);

    printf("%d\n", lines[shortest]);

    lines[shortest]++;
  }
}

int main(int argc, char *argv[]) {
  int n;
  int m;

  scanf("%d%d", &n, &m);

  int lines[MAX_LINES];

  for (int i = 0; i < n; i++) {
    scanf("%d", &lines[i]);
  }

  solve(lines, n, m);

  return 0;
}

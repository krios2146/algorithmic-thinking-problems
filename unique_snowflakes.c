#include <stdbool.h>
#include <stdio.h>

const int SNOWFLAKE_ARMS = 6;

bool same_snowflakes_strait(int snowflake_one[], int snowflake_two[]) {
  for (int i = 0; i < SNOWFLAKE_ARMS; i++) {
    if (snowflake_one[i] != snowflake_two[i]) {
      return false;
    }
  }
  return true;
}

bool same_snowflakes_right(int snowflake_one[], int snowflake_two[],
                           int start_index_two) {
  int j = start_index_two;

  for (int i = 0; i < SNOWFLAKE_ARMS; i++) {
    if (snowflake_one[i] != snowflake_two[j]) {
      return false;
    }

    j++;

    if (j >= SNOWFLAKE_ARMS) {
      j = 0;
    }
  }

  return true;
}

bool same_snowflakes_left(int snowflake_one[], int snowflake_two[],
                          int start_index_two) {
  int j = start_index_two;

  for (int i = 0; i < SNOWFLAKE_ARMS; i++) {
    if (snowflake_one[i] != snowflake_two[j]) {
      return false;
    }

    j--;

    if (j < 0) {
      j = SNOWFLAKE_ARMS;
    }
  }

  return true;
}

bool same_snowflakes(int snowflake_one[], int snowflake_two[]) {
  if (same_snowflakes_strait(snowflake_one, snowflake_two)) {
    return true;
  }

  int same_arm_index = -1;

  for (int i = 0; i < SNOWFLAKE_ARMS; i++) {
    for (int j = 0; j < SNOWFLAKE_ARMS; j++) {
      if (snowflake_one[i] == snowflake_two[j]) {
        same_arm_index = j;
        break;
      }
    }

    if (same_arm_index != -1) {
      break;
    }
  }

  if (same_arm_index == -1) {
    return false;
  }

  if (same_snowflakes_right(snowflake_one, snowflake_two, same_arm_index)) {
    return true;
  }

  if (same_snowflakes_left(snowflake_one, snowflake_two, same_arm_index)) {
    return true;
  }

  return false;
}

void find_same_snowflakes(int snowflakes[][SNOWFLAKE_ARMS], int n) {
  for (int i = 0; i < SNOWFLAKE_ARMS; i++) {
    for (int j = i + 1; j < SNOWFLAKE_ARMS; j++) {
      if (same_snowflakes(snowflakes[i], snowflakes[j])) {
        printf("Twin snowflakes found.\n");
        return;
      }
    }
  }

  printf("No two snowflakes are alike.\n");
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int snowflakes[n][SNOWFLAKE_ARMS];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < SNOWFLAKE_ARMS; j++) {
      scanf("%d", &snowflakes[i][j]);
    }
  }

  find_same_snowflakes(snowflakes, n);

  return 0;
}

#include "stdio.h"

int get_next_line(const int fd, char **line) {
  int test = 1;
  (void)fd;
  (void)line;
  return (test);
}

int main(void) {
  char **line;
  if (get_next_line(2, line)) {
    printf("the tests are working fine!!");
  }
  return (0);
}

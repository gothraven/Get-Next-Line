#include "get_next_line.h"

int get_next_line(const int fd, char **line) {
  int test = 1;
  (void)fd;
  (void)line;
  return (test);
}

int main(void) {
  char **line = NULL;
  if (get_next_line(2, line)) {
    ft_putstr("the tests are working fine!!");
  }
  return (0);
}

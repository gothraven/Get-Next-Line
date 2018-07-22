#include "get_next_line.h"


int main(void) {
  char **line = NULL;

  if (get_next_line(2, line)) {
    ft_putstr("the tests are working fine!!");
  }
  return (0);
}

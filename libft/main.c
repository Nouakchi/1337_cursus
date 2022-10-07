#include "libft.h"

int main () {
  char str[] = "holidays";
  char tof[] = "hol";
  printf("%s", ft_strnstr(str, tof, 5));
  return (0);
}

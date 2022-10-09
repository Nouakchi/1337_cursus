#include "libft.h"

int main () {
  char str[] = "holidays";
  char tof[] = "hol";
  printf("%s", ft_strtrim(str, tof));
  return (0);
}

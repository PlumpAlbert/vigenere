#include <stdio.h>
#include <unitypes.h>
#include <string.h>
#include "unicode.h"

int main(int argc, char *argv[]) {
  char *s = "пи";
  printf("%s\n\n", s);
  uint16_t *uni = NULL;
  size_t len = char_to_unicode(uni, s, strlen(s));
  for (size_t i = 0; i < len; i++)
  {
    printf("%lu : %04X\n", i, uni[i]);
  }
  char test[1024];
  unicode_to_char(test, uni, len);
  return 0;
}
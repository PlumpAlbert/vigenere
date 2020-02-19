#include "unicode.h"

size_t
char_to_unicode(uint16_t *__restrict__ dest, char *src, size_t n)
{
  uint16_t *buf = malloc(sizeof(uint16_t) * n);
  size_t buf_size = 0;
  for (size_t i = 0; i < n; i++)
  {
    uint8_t c = src[i];
    if (c < 127)
    {
      buf[buf_size++] = c;
      continue;
    }
    uint16_t u = c << 8;
    u += (uint8_t)src[++i];
    u -= UNICODE_CONST;
    buf[buf_size++] = u;
  }
  if (dest == NULL)
    dest = buf;
  else
    memcpy(dest, buf, buf_size);
  return buf_size;
}

size_t
unicode_to_char(char *__restrict__ dest, uint16_t *src, size_t n)
{
  char *buf = malloc(sizeof(char) * n * 2);
  size_t buf_size = 0;
  for (size_t i = 0; i < n; i++)
  {
    uint16_t uc = src[i];
    uint8_t *p = (uint8_t *)&uc;
    if (uc < 127)
    {
      buf[buf_size++] = uc;
      continue;
    }
    uc += UNICODE_CONST;
    for (size_t j = 2; j > 0; j--)
      buf[buf_size++] = p[j - 1];
  }
  buf[buf_size++] = '\0';
  if (dest != NULL)
    memcpy(dest, buf, buf_size);
  else
    dest = buf;
  return buf_size;
}
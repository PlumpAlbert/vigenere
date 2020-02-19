#include <unitypes.h>
#include <malloc.h>
#include <string.h>

#define UNICODE_CONST 0xCC80

size_t
char_to_unicode(uint16_t **dest, char *src, size_t n);

size_t
unicode_to_char(char ** dest, uint16_t *src, size_t n);
#ifndef PBOS_STDIO
#define PBOS_STDIO

#include <stivale2.h>

void stdio_init(struct stivale2_struct_tag_terminal *term_struct_tag);
void printf(char *fmt, ...);
void puts(char *str);
void putd(int i, int base);

#endif
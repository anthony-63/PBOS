#include <std/stdio.h>
#include <std/string.h>
#include <std/stdlib.h>

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

void (*g_write)(const char *str, size_t len);

void stdio_init(struct stivale2_struct_tag_terminal *term_struct_tag){
    void *term_write_ptr = (void*) term_struct_tag->term_write;
    g_write = term_write_ptr;
}

void printf(char* fmt, ...) {
    
    va_list lst;
    va_start(lst, fmt);

    for(char* ptr = fmt; *ptr != '\0'; ptr++) {
        if(*ptr == '%') {
            ptr++;
            switch(*ptr) {
                case 's':
                    puts(va_arg(lst, char*));
                    break;
                case 'd':
                    putd(va_arg(lst, int), 10);
                    break;
                case 'x':
                    putd(va_arg(lst, int), 16);
                    break;
            }
        }else{ 
            g_write(ptr, 1);
        }
    }

    va_end(lst);
}

void puts(char *str){
    g_write(str, strlen(str));
}
void putd(int i, int base){
    char r[2048];
    itoa(r, i, base);
    puts(r);
}
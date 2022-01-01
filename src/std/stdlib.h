#ifndef PBOS_STDLIB
#define PBOS_STDLIB

#define pause for(;;) __asm__("hlt")

int dcount(int i);
void itoa(char* buffer, int value, int base);
int abs(int i);

#endif
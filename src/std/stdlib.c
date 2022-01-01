#include <std/stdlib.h>

int dcount(int i) {
    int t = i;
    int c = 0;
    do {
        t /= 10;
        ++c;
    } while (t != 0);
    return c;
}

void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

char* reverse(char *buffer, int i, int j){
    while (i < j) swap(&buffer[i++], &buffer[j--]);
    return buffer;
}

void itoa(char* buffer, int value, int base){
    if (base < 2 || base > 32) return;
    int n = abs(value);
    int i = 0;
    while (n){
        int r = n % base;
        if (r >= 10) buffer[i++] = 65 + (r - 10);
        else buffer[i++] = 48 + r;
        n = n / base;
    }
    if (i == 0) buffer[i++] = '0';
    if (value < 0 && base == 10) buffer[i++] = '-';
    buffer[i] = '\0';
    buffer = reverse(buffer, 0, i - 1);
}

int abs(int i) {
    return i < 0 ? -i : i;
}
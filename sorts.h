#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int option(int, const char*, int*, int*, int*, int*, int*);

typedef struct Voiter {
    char* name; //Строка произвольной длины
    char* number; //Строка длиной 7 символов вида XXX-YYY (x - буква, y - цифра)
    int age; //возраст (целое число)
} Voiter;

typedef enum ERR {
    ERR_OK,
    ERR_MEM
} ERR;

typedef void (*sort)(void *base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));
typedef int (*cmp)(const void*, const void*);

ERR rand_name(char**);
ERR rand_num(char**);

int CompName1 (const void* a, const void* b);
int CompName2 (const void* a, const void* b);
int CompNumber1 (const void* a, const void* b);
int CompNumber2 (const void* a, const void* b);
int CompAge1 (const void* a, const void* b);
int CompAge2 (const void* a, const void* b);
void comb_sort(void*, size_t, size_t, int (*)(const void *, const void *));
void heap_sort(void*, size_t, size_t, int (*)(const void*, const void*));

void print_arr(Voiter **a, int m, int n);
#include "sorts.h"

ERR rand_name(char** s) {
    int max_len = 50;
    int len = 8 + rand() % (max_len - 8);
    char* str = malloc((len + 1) * sizeof(char));
    if (!str) {
        *s = NULL;
        return ERR_MEM;
    }

    char* char2 = "aA";
    for (int i = 0; i < len; ++i) {
        str[i] = rand() % 26 + char2[rand() % 2];
    }
    str[len] = '\0';
    
    if (*s != NULL) {
        free(*s);
    }

    *s = str;
    return ERR_OK;
}

ERR rand_num(char** n) {
    char* str = malloc((8) * sizeof(char));
    if (!str) {
        *n = NULL;
        return ERR_MEM;
    }
    char* char2 = "aA";

    str[0] = rand() % 26 + char2[rand() % 2];
    str[1] = rand() % 26 + char2[rand() % 2];
    str[2] = rand() % 26 + char2[rand() % 2];
    str[3] = '-';
    str[4] = (char)('0' + rand() % 10);
    str[5] = (char)('0' + rand() % 10);
    str[6] = (char)('0' + rand() % 10);
    str[7] = '\0';

    if (*n != NULL) {
        free(*n);
    }

    *n = str;
    return ERR_OK;
}
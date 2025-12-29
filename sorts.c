#include "sorts.h"

void comb_sort(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*)) {
    if (nmemb < 2) {
        return;
    }
    char* array = base;
    size_t interv = nmemb;
    int flag = 1;  

    while(interv > 1 || flag == 1) {
        interv = (size_t)(interv / 1.3);
        if (interv < 1) {
            interv = 1;
        }
        flag = 0;
        
        for (size_t i = 0; i + interv < nmemb; ++i) {
            char* lev = array + size * i;
            char* pr = array + size * (i + interv);
            
            if (cmp(lev, pr) > 0) {
                for (size_t j = 0; j < size; ++j) {
                    char bait = pr[j];
                    pr[j] = lev[j];
                    lev[j] = bait;
                }
                flag = 1;
            }
        }
    }
}

void heap_sort(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*)) {
    if (nmemb < 2) {
        return;
    }
    char* array = base;

    for (int i = (int)nmemb / 2 - 1; i >= 0; i--) {
        size_t index = (size_t)i;

        while (1) {
            size_t big_bos = index;
            size_t lev = 2 * index + 1;
            size_t pr = 2 * index + 2;
            
            if (lev < nmemb && cmp(array + size * lev, array + size * big_bos) > 0) {
                big_bos = lev;
            }
            if (pr < nmemb && cmp(array + size * pr, array + size * big_bos) > 0) {
                big_bos = pr;
            } 

            if (big_bos == index) {
                break;
            }

            for (size_t k = 0; k < size; k++) {
                char bait = array[index * size + k];
                array[index * size + k] = array[big_bos * size + k];
                array[big_bos * size + k] = bait;
            }
            index = big_bos;
        }
    }

    for (int end = (int)nmemb - 1; end > 0; end--) {
        size_t end_index = (size_t)end;

        for (size_t k = 0; k < size; k++) {
            char bait = array[k];
            array[k] = array[end_index * size + k];
            array[end_index * size + k] = bait;
        }

        size_t index = 0;
        while (1) {
            size_t big_bos = index;
            size_t lev = 2 * index + 1;
            size_t pr = 2 * index + 2;
            
            if (lev < end_index && cmp(array + size * lev, array + size * big_bos) > 0) {
                big_bos = lev;
            }
            if (pr < end_index && cmp(array + size * pr, array + size * big_bos) > 0) {
                big_bos = pr;
            } 

            if (big_bos == index) {
                break;
            }

            for (size_t k = 0; k < size; k++) {
                char bait = array[index * size + k];
                array[index * size + k] = array[big_bos * size + k];
                array[big_bos * size + k] = bait;
            }
            index = big_bos;
        }
    }
}

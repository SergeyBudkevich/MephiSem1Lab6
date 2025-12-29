#include "sorts.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    int alg = 0; //ТИП СОРТИРОВКИ 
    int field = 0; //ПОЛЕ СОРТИРОВКИ
    int orin = 0; //НАПРАВЛЕНИЕ СОРТИРОВКИ
    int n = 0; //КОЛ-ВО ЭЛЕМЕНТОВ В МАССИВЕ
    int m = 0; //КОЛ-ВО МАССИВОВ
    int all = 0;
    int c;

    //ВВОД И ЕГО ПРОВЕРКА:
    while ((c = getopt(argc, argv, "a:f:o:n:m:")) != -1) {
        if (option(c, optarg, &alg, &field, &orin, &n, &m) != 0) {
            return 1;
        }

        if (alg && field && orin && n && m) {
           all = 1;
           break;
        }
    }


    if (optind < argc) {
        fprintf(stderr, "Ошибка: лишние аргументы");
        return 1;
    }

    if (all == 0 || alg == 0 || field == 0 || n == 0 || m == 0 || orin == 0) {
        fprintf(stderr, "Ошибка: укажите все параметры!\n");
        return 1;
    }

    //ЗАПОЛНЕНИЕ РАНДОМНЫМИ ЗНАЧЕНИЯМИ:
    Voiter** array_m = malloc(m * sizeof(Voiter*));
    if (!array_m) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        return 1;
    }

    for (int i = 0; i < m; ++i) {
        array_m[i] = malloc(n * sizeof(Voiter));
        if (!array_m[i]) {
            fprintf(stderr, "Ошибка выделения памяти!\n");
            return 1;
        }
        
        for (int j = 0; j < n; ++j) {
            array_m[i][j].age = rand() % 82 + 18;

            char* s = NULL;
            ERR ch1 = rand_name(&s);
            if (ch1 == ERR_MEM) {
                fprintf(stderr, "Ошибка выделения памяти!");
                return 1;
            }
            array_m[i][j].name = s;

            char* num = NULL;
            ERR ch2 = rand_num(&num);
            if (ch2 == ERR_MEM) {
                fprintf(stderr, "Ошибка выделения памяти!");
                return 1;
            }
            array_m[i][j].number = num;
        }
    }

    //СОРТИРОВКА
    sort sort = NULL;
    cmp cmp = NULL;

    switch (alg) {
        case 1: 
            sort = qsort;
            break;
        case 2: 
            sort = comb_sort;  
            break;
        case 3: 
            sort = heap_sort;  
            break;
    }

    switch (field) {
        case 1:
            if (orin == 1) {
                cmp = CompName1;
            } else {
                cmp = CompName2;   
            }
            break;
        case 2: 
            if (orin == 1) {
                cmp = CompNumber1;
            } else {
                cmp = CompNumber2;   
            }
            break;
        case 3:
            if (orin == 1) {
                cmp = CompAge1;
            } else {
                cmp = CompAge2;   
            }
            break;
    }

    printf("До сортировки:\n");
    print_all(array_m, m, n);    

    clock_t start = clock();

    for (int k = 0; k < m; k++) {
        sort(array_m[k], (size_t)n, sizeof(Voiter), cmp);
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("После сортировки:\n");
    print_all(array_m, m, n);

    printf("Время - %f, Кол-во элементов - %d", time, n);

    //ОЧИСТКА ПАМЯТИ 
    for (int l = 0; l < m; ++l) {
        for(int k = 0; k < n; ++k) {
            free(array_m[l][k].name);
            free(array_m[l][k].number);
        }
        free(array_m[l]);
    }

    free(array_m);
    return 0;
}


int option(int c, const char* optarg, int* alg, int* field, int* orin, int* n, int* m) {
    switch (c) {
    case 'a':
        if (strcmp(optarg, "1") != 0 && strcmp(optarg, "2") != 0 && strcmp(optarg, "3") != 0) {
            fprintf(stderr, "Ошибка: -a принимает только 1, 2, 3\n");
            return 1;
        }
        *alg = atoi(optarg);
        return 0;

    case 'f':
        if (strcmp(optarg, "1") != 0 && strcmp(optarg, "2") != 0 && strcmp(optarg, "3") != 0) {
            fprintf(stderr, "Ошибка: -f принимает только 1, 2, 3\n");
            return 1;
        }
        *field = atoi(optarg);
        return 0;

    case 'o':
        if (strcmp(optarg, "1") != 0 && strcmp(optarg, "2") != 0) {
            fprintf(stderr, "Ошибка: -o принимает только 1, 2\n");
            return 1;
        }
        *orin = atoi(optarg);
        return 0;

    case 'n':
        for (int i = 0; optarg[i]; i++) {
            if (!isdigit(optarg[i])) {
                fprintf(stderr, "Ошибка: -n принимает только цифры\n");
                return 1;
            }
        }
        *n = atoi(optarg);
        if (*n <= 0) {
            fprintf(stderr, "Ошибка: -n должно быть > 0\n");
            return 1;
        }
        return 0;

    case 'm':
        for (int i = 0; optarg[i]; i++) {
            if (!isdigit(optarg[i])) {
                fprintf(stderr, "Ошибка: -m принимает только цифры\n");
                return 1;
            }
        }
        *m = atoi(optarg);
        if (*m <= 0) {
            fprintf(stderr, "Ошибка: -m должно быть > 0\n");
            return 1;
        }
        return 0;

    default:
        fprintf(stderr, "Неизвестный флаг\n");
        return 1;
    }
}

void print_all(Voiter** array, int m, int n) {
    for (int k = 0; k < m; k++) {
        printf("Массив %d:\n", k);
        for (int i = 0; i < n; i++) {
            printf("%s %s %d\n", array[k][i].name, array[k][i].number, array[k][i].age);
        }
        printf("\n");
    }
}



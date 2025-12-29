#include "sorts.h"

int CompName1 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return strcmp(va->name, vb->name);
}

int CompName2 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return strcmp(vb->name, va->name);
}

int CompNumber1 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return strcmp(va->number, vb->number);
}

int CompNumber2 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return strcmp(vb->number, va->number);
}

int CompAge1 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return va->age - vb->age;
}

int CompAge2 (const void* a, const void* b) {
    const Voiter *va = a;
    const Voiter *vb = b;
    return vb->age - va->age;
}
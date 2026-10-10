typedef struct N { struct N *prev; struct N *next; } N;
typedef struct L { char pad[8]; N *first; N *last; } L;
void func_005429F0(L *arg0, N *arg1) {
    N *t;
    if (arg0 == 0) return;
    arg1->next = 0;
    if (arg0->first != 0) {
        t = arg0->last;
        arg1->prev = t;
        t->next = arg1;
    } else {
        arg0->first = arg1;
        arg1->prev = 0;
    }
    arg0->last = arg1;
}

typedef struct N { struct N *next; char pad[0xEC]; } N;
typedef struct P { N *head; N n[32]; } P;
void func_00606568(P *arg0) {
    int i;
    for (i = 0; i < 31; i++) arg0->n[i].next = &arg0->n[i + 1];
    arg0->head = &arg0->n[0];
    arg0->n[31].next = 0;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Queue {
    int pad0[3];
    int size;
    int tail;
    int pad14;
    int count;
    int pad1C;
    int sema;
};

extern int D_0064C4B0;
extern void func_005ADCE0(int sema);
extern void func_005ADCC0(int sema);

void func_00564910(struct Queue *q) {
    func_005ADCE0(q->sema);
    if (++q->count == q->size) {
        if (D_0064C4B0 == 0)
            D_0064C4B0 = 1;
    }
    q->tail = q->tail + 1 == q->size ? 0 : q->tail + 1;
    func_005ADCC0(q->sema);
}

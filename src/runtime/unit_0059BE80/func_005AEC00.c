/* compiler: ee-gcc2.9-991111 */
struct Ent {
    unsigned char kind;
    unsigned char val;
};

struct Queue {
    int head;
    int tail;
    struct Ent e[512];
};

extern struct Queue D_00885EE8;
extern int D_00885EE0;
extern int D_006582A8;
extern void func_005ADCD0(int sema);

int func_005AEC00(unsigned int c) {
    struct Queue *q;
    int i;
    if (c >= 0x80 || D_006582A8 == 0)
        return -1;
    q = &D_00885EE8;
    i = q->tail & 0x1FF;
    q->tail = i + 1;
    q->e[i].kind = 1;
    q->e[i].val = c;
    func_005ADCD0(D_00885EE0);
    return c;
}

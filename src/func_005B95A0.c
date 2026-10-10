/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    unsigned int id;
    int a;
    int b;
    void *buf;
} Msg;

extern char D_0088C548[];
extern int func_005AE0D0(int, Msg *);

int func_005B95A0(unsigned short id, int a, int b) {
    Msg m;
    m.id = id;
    m.a = a;
    m.b = b;
    m.buf = (void *)((unsigned int)D_0088C548 | 0x20000000);
    return func_005AE0D0(1, &m);
}

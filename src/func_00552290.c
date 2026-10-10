/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x10];
    char lock[0x30];
    void *m40;
    char m44[0x3C];
    char m80[0x14];
    int m94;
} Conn_00552290;

void func_00576788(void *lock);
void func_005767C0(void *lock);
void func_00551A50(void *h, void *p);
void func_00551B38(void *h, void *p);

void func_00552290(Conn_00552290 *c) {
    func_00576788(c->lock);
    func_00551A50(c->m40, c->m44);
    if (c->m94 != 0) {
        func_00551B38(c->m40, c->m80);
        c->m94 = 0;
    }
    func_005767C0(c->lock);
}

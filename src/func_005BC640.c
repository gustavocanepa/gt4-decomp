/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct {
    int m0;
    char *m4;
    char data[0xE8];
} Obj_005BC640;

void *func_00575DC8(int size);
void func_005BC5F0(void) __attribute__((noreturn));
void *func_005A48D8(void *p, int c, int n);

Obj_005BC640 *func_005BC640(void) {
    Obj_005BC640 *p = func_00575DC8(sizeof(Obj_005BC640));
    if (p == 0) {
        func_005BC5F0();
    }
    func_005A48D8(p, 0, sizeof(Obj_005BC640));
    p->m4 = (char *)p + 0xE0;
    return p;
}

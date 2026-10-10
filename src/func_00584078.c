/* compiler: ee-gcc2.9-991111 */
struct State {
    int f0, f4, f8;
    int init;
    int f10, f14;
    int a;
    int b;
};

extern struct State D_00875878;

int func_00584078(int *a, int *b) {
    struct State *s = &D_00875878;
    if (s->init == 0) {
        return 0x81058001;
    }
    if (a) {
        *a = s->a;
    }
    if (b) {
        *b = s->b;
    }
    return 0;
}

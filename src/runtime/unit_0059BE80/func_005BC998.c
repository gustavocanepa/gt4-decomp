/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct State {
    int m0;
    void *m4;
    char pad[0xD8];
} State;

extern State D_0088D7D0;
extern int D_0088D8B0;
extern char D_0088D8B8[];
extern void *func_005A48D8(void *dst, int c, unsigned int n);

State *func_005BC998(void)
{
    if (D_0088D8B0 == 0) {
        D_0088D8B0 = 1;
        func_005A48D8(&D_0088D7D0, 0, sizeof(State));
        D_0088D7D0.m4 = D_0088D8B8;
    }
    return &D_0088D7D0;
}

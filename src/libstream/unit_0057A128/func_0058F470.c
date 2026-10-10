/* compiler: ee-gcc2.9-991111 */
typedef struct {
    char pad0[8];
    int m8;
    char padC[0x334 - 0xC];
} Port_0058F470;

typedef struct {
    char pad0[0x7C];
    int m7C;
} Status_0058F470;

extern Port_0058F470 D_0087FA80[];

Status_0058F470 *func_0058F3A0(int port);

int func_0058F470(int port) {
    int v = func_0058F3A0(port)->m7C;
    if (v == 0) {
        return 0;
    }
    if (v == D_0087FA80[port].m8) {
        return 0;
    }
    D_0087FA80[port].m8 = v;
    return 1;
}

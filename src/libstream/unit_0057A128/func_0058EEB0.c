/* compiler: ee-gcc2.9-991111 */
typedef struct Port {
    int state;
    int unk4;
    int unk8;
    int unkC;
    char pad[0x334 - 0x10];
} Port;

extern Port D_0087FA80[];
extern int func_0058FC68(int port);

int func_0058EEB0(int port) {
    int r = func_0058FC68(port);
    if (r < 0)
        return r;
    D_0087FA80[port].state = 0;
    D_0087FA80[port].unk4 = 0;
    D_0087FA80[port].unkC = 0;
    return 1;
}

struct E { char pad[0x70]; int f; char pad2[0x1BC - 0x74]; };
extern struct E *D_0064C3E4;
int func_0054A338(int i) {
    if (i < 2) return D_0064C3E4[i].f;
    return 0;
}

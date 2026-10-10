struct S {
    char pad[0x60];
    int x;
    int y;
};

extern S D_00654E20[7];

void func_005658F8(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        S *p = D_00654E20;
        int i = 6;
        do {
            i--;
            p->x = 0;
            p++;
        } while (i != -1);
    }
    if (prio == 0xFFFF && init == 0) {
        S *base = D_00654E20;
        if (base != 0) {
            S *p = base + 7;
            while (p != base) {
                p--;
            }
        }
    }
}

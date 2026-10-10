extern "C" char D_00846398[];
extern "C" char D_008463A0[];
extern "C" char D_008463A8[];
extern "C" char D_006A7310[];
extern "C" char D_006A7658[];
extern "C" char D_006A79C0[];
extern "C" void func_0057B168(void *self, void *data);

extern "C" void func_00448E70(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        func_0057B168(D_00846398, D_006A7310);
    if (prio == 0xFFFF && init == 1)
        func_0057B168(D_008463A0, D_006A7658);
    if (prio == 0xFFFF && init == 1)
        func_0057B168(D_008463A8, D_006A79C0);
}

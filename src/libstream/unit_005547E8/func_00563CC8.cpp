/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Parses a stream header field by field with the bit reader func_00563158 (4x4, 2, 2, 1, 1 bits
   into globals, three flags kept for D_00654DC8, an optional block behind a 1-bit flag). Fields
   stored through get() take their address in a saved register before the call, as the original. */
extern "C" int func_00563158(int n);
extern int D_00654DA8[4];
extern int D_00654DB8;
extern int D_00654DBC;
extern int D_00654DC0;
extern int D_00654DC8[9];
static inline void get(int *dst, int n) { *dst = func_00563158(n); }
extern "C" void func_00563CC8(void) {
    D_00654DA8[0] = func_00563158(4);
    D_00654DA8[1] = func_00563158(4);
    D_00654DA8[2] = func_00563158(4);
    D_00654DA8[3] = func_00563158(4);
    int a = func_00563158(2);
    get(&D_00654DB8, 2);
    get(&D_00654DBC, 1);
    get(&D_00654DC0, 1);
    func_00563158(1);
    int b = func_00563158(1);
    int c = func_00563158(1);
    int d = func_00563158(1);
    func_00563158(1);
    func_00563158(1);
    func_00563158(1);
    if (func_00563158(1)) {
        func_00563158(1);
        func_00563158(3);
        func_00563158(1);
        func_00563158(7);
        func_00563158(8);
    }
    D_00654DC8[6] = a;
    D_00654DC8[7] = c;
    D_00654DC8[8] = b;
    D_00654DC8[5] = d;
}

/* A function-local static written out: guard D_00620188, object D_00842510 (inline constructor:
   handle, then zeroes) and the atexit-registered destructor stub func_003295E0. The guard store and
   the registration share a do-while(0): its loop notes keep them after the constructor's stores. */
struct Obj { int h; int f4, f8, fC, f10, f14, f18; };
extern "C" int D_00620188;
extern "C" Obj D_00842510;
extern "C" int func_003294C0(void);
extern "C" void func_003295E0(void);
extern "C" int func_005A2ED0(void (*fn)(void));

extern "C" Obj *func_00329530(void) {
    if (D_00620188 == 0) {
        Obj *o = &D_00842510;
        o->h = func_003294C0();
        o->f4 = 0;
        o->f8 = 0;
        o->fC = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        do {
            D_00620188 = 1;
            func_005A2ED0(func_003295E0);
        } while (0);
    }
    return &D_00842510;
}

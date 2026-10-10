typedef int s32;

struct Handle { s32 p; s32 pad[3]; };
extern s32 D_00618EF0;
extern "C" void func_002FC8C8(Handle *, s32);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FC870(Handle *, s32);

extern "C" void func_0021DE38(void *self, s32 n, s32 x) {
    if (n > 0) {
        Handle h;
        func_002FC8C8(&h, x);
        s32 r = func_002FE250(h.p);
        D_00618EF0 = r != 0;
        func_002FC870(&h, 2);
    }
}

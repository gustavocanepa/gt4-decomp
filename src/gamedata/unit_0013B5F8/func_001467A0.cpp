typedef int s32;

extern "C" s32 func_00146758(void *);
extern "C" s32 func_00146780(void *);

extern "C" s32 func_001467A0(void *self) {
    s32 r;
    if (func_00146758(self)) r = 1;
    else r = func_00146780(self) ? 2 : 0;
    return r;
}

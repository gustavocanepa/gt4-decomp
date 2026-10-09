typedef int s32;

struct Obj {
    char pad0[0xC8];
    s32 h;
};

extern "C" void func_002F9B08(void *arg0, s32 *arg1);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_00263428(Obj *self);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_002DEDC8(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_00263428(self);
    zero = 0;
    func_002F9B08(buf, &zero);
    dst = &self->h;
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_002F9B38(buf, 2);
}

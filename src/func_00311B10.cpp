typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 h;
};

extern "C" void func_00309348(void *arg0, s32 *arg1);
extern "C" void func_00309378(void *arg0, int arg1);
extern "C" void func_00328500(Obj *self);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00311B10(Obj *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    func_00328500(self);
    zero = 0;
    func_00309348(buf, &zero);
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
    func_00309378(buf, 2);
}

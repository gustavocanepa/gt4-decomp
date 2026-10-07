typedef int s32;

struct Obj {
    char pad0[0xA90];
    s32 arr[(0xAA8 - 0xA90) / 4];
    s32 unkAA8;
};

extern "C" void func_005F31C0(Obj *arg0, s32 arg1) {
    s32 *ctr = &arg0->unkAA8;
    s32 idx = *ctr;
    arg0->arr[idx] = arg1;
    *ctr = idx + 1;
}

typedef int s32;

struct Obj {
    char pad0[0x450];
    s32 arr[(0x458 - 0x450) / 4];
    s32 unk458;
};

extern "C" void func_005F29E8(Obj *arg0, s32 arg1) {
    s32 *ctr = &arg0->unk458;
    s32 idx = *ctr;
    arg0->arr[idx] = arg1;
    *ctr = idx + 1;
}

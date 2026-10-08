typedef int s32;

struct Obj003A4980 {
    char pad0[0x1C];
    s32 unk1C;
    char pad1[0x24 - 0x1C - 4];
    s32 arr[1];
};

extern "C" void func_003A4980(struct Obj003A4980 *arg0, s32 arg1) {
    s32 idx = arg0->unk1C;
    if (idx >= 8) {
        idx = 7;
    }
    arg0->arr[idx] = arg1;
}

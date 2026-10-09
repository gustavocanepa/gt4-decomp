typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002661D8(Obj *arg0, s32 arg1) {
    s32 full = arg0->unk98;
    s32 low = full & 7;
    full &= ~0xF;
    s32 val = low;
    if (arg1 != 0) {
        val = low | 8;
    }
    arg0->unk98 = full | val;
}

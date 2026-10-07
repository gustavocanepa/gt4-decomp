typedef int s32;

struct Obj {
    char pad[0x1140];
    s32 unk1140;
};

extern "C" void func_00437408(Obj *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0->unk1140 & ~arg1;
    arg0->unk1140 = (arg2 != 0) ? (temp_v0 | arg1) : temp_v0;
}

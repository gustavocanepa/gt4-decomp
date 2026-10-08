typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_00268450(Obj *arg0, s32 arg1) {
    arg0->unk98 = (arg0->unk98 & 0x87FFFFFF) | ((arg1 & 0xF) << 27);
}

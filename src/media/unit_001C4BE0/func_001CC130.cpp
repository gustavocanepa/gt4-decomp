typedef unsigned short u16;
typedef int s32;

struct Obj {
    char pad[0x48];
    u16 unk48;
};

extern "C" void func_001CC130(Obj *arg0, s32 arg1) {
    u16 v = arg0->unk48;
    if (arg1 != 0) {
        arg0->unk48 = v | 4;
        return;
    }
    arg0->unk48 = v & 0xFFFB;
}

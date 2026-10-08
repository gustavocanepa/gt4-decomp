typedef unsigned int u32;

struct Obj {
    char pad[0x98];
    u32 unk98;
};

extern "C" void func_00265D48(Obj *arg0) {
    arg0->unk98 = arg0->unk98 & 0xFFFBFFFF;
}

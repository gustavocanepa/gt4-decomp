typedef short s16;
typedef unsigned short u16;
typedef int s32;

struct Elem {
    char pad[0x94];
    u16 unk94;
};

struct Obj {
    char pad[0xA4];
    s16 unkA4;
};

extern "C" s32 func_00251860(Obj *arg0, s32 arg1) {
    s32 off = arg1 * 2;
    Elem *e = (Elem *)(off + (s32)arg0);
    return e->unk94 >= arg0->unkA4;
}

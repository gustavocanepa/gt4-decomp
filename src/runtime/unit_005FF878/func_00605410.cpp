typedef unsigned short u16;
typedef int s32;

struct Obj {
    char pad[0x10];
    u16 *unk10;
};

extern "C" u16 func_00605410(Obj *arg0, s32 arg1) {
    return arg0->unk10[arg1];
}

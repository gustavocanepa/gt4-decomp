typedef unsigned short u16;
typedef int s32;

struct Obj {
    char pad[0x4];
    u16 unk4;
};

extern "C" Obj *func_00450040(s32 arg0, s32 arg1);

extern "C" u16 func_00450070(s32 arg0) {
    return func_00450040(arg0, 0)->unk4;
}

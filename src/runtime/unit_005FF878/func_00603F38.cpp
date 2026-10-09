typedef unsigned short u16;

struct Obj00603F38 {
    char pad0[0x8];
    u16 unk8;
};

extern "C" struct Obj00603F38 *func_00450040(void);

extern "C" u16 func_00603F38(void) {
    return func_00450040()->unk8;
}

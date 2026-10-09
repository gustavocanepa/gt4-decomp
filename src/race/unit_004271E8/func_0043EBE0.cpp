typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" u16 func_0043EBE0(Obj *arg0) {
    return *(u16 *)((char *)arg0 + arg0->unk490 * 0x178 + 0x134);
}

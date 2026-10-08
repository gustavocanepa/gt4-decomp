typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" f32 func_0033B610(Obj *arg0) {
    char *p = (char *)arg0 + arg0->unk8C * 0x44;
    return *(f32 *)(p + 0x40);
}

typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" void func_0043E850(struct Obj *arg0, s16 arg1) {
    *(s16 *)((char *)arg0 + arg0->unk490 * 0x178 + 0x144) = arg1;
}

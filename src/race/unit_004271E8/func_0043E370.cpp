typedef int s32;
typedef short s16;

struct Elem0043E370 {
    char pad[0x134];
    s16 unk134;
};

struct Obj0043E370 {
    char pad[0x490];
    s32 unk490;
};

extern "C" void func_0043E370(Obj0043E370 *arg0, s16 arg1) {
    ((Elem0043E370 *)((char *)arg0 + arg0->unk490 * 0x178))->unk134 = arg1;
}

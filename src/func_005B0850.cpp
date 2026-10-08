typedef int s32;

struct Obj0 {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
};

struct Obj1 {
    char pad[0x1C];
    s32 *unk1C;
};

extern "C" void func_005B0850(struct Obj0 *arg0, struct Obj1 *arg1) {
    arg1->unk1C[arg0->unk10] = arg0->unk14;
}

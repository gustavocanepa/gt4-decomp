typedef int s32;

struct S8 {
    char data[8];
};

struct Obj0047CFB8 {
    char pad0[8];
    s32 unk8;
    S8 unkC;
};

extern "C" void func_0047CFB8(struct Obj0047CFB8 *arg0, struct S8 *arg1) {
    arg0->unkC = *arg1;
    arg0->unk8 = 1;
}

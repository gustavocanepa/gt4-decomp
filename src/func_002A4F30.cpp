typedef int s32;

struct Obj002A4F30 {
    char pad0[0x108];
    s32 unk108;
    char pad1[0x11C - 0x108 - 4];
    s32 unk11C;
};

extern "C" void func_002638B0(void);
extern "C" void func_00265FF0(struct Obj002A4F30 *arg0, s32 arg1);

extern "C" void func_002A4F30(struct Obj002A4F30 *arg0) {
    struct Obj002A4F30 *s0 = arg0;

    func_002638B0();
    func_00265FF0(s0, 0);
    s0->unk11C = s0->unk108;
}

typedef int s32;
typedef unsigned char u8;

struct Arg1 {
    u8 unk0;
    char pad0[3];
    u8 unk4;
    char pad1[3];
    s32 unk8;
};

struct Arg0 {
    char pad0[0xD8];
    u8 unkD8;
    u8 unkD9;
};

extern "C" void func_005A609C(void *arg0, s32 arg1, u8 arg2);

extern "C" void func_00110390(Arg0 *arg0, Arg1 *arg1) {
    u8 t = arg1->unk0;

    arg0->unkD8 = t;
    arg0->unkD9 = arg1->unk4;
    func_005A609C((char *)arg0 + 0x10, arg1->unk8, t);
}

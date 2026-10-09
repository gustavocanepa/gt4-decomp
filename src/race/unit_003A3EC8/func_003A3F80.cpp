typedef short s16;
typedef int s32;

struct Obj {
    char pad[0x28];
    s32 unk28;
    char pad2C[0x30 - 0x28 - 4];
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
};

extern "C" void func_003A3F80(Obj *arg0) {
    arg0->unk28 = 0;
    arg0->unk32 = 0;
    arg0->unk34 = 0;
    arg0->unk36 = 0;
    arg0->unk30 = 0;
}

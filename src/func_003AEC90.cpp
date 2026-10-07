typedef short s16;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x8];
    s16 unk8;
    s16 unkA;
};

extern "C" void func_003AEC90(Obj *arg0, s16 arg1, s16 arg2) {
    arg0->unk8 = arg1;
    arg0->unkA = arg2;
}

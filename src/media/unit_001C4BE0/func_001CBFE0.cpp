typedef int s32;
typedef short s16;

extern char D_00661688[];

struct Struct_001CBFE0 {
    s32 unk0;
    char pad4[0x48 - 4];
    s16 unk48;
    s16 unk4A;
    void *unk4C;
};

extern "C" void func_001CBFE0(Struct_001CBFE0 *arg0) {
    arg0->unk4C = D_00661688;
    arg0->unk0 = -1;
    arg0->unk48 = 0;
    arg0->unk4A = 0;
}

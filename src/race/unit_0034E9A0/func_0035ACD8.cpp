typedef int s32;
typedef unsigned char u8;

struct Elem8 {
    s32 unk0;
    s32 unk4;
};

extern Elem8 D_006207E4[];

struct Inner {
    char pad[0x5FA];
    u8 unk5FA;
    u8 unk5FB;
};

extern "C" void func_0035ACD8(char *arg0, s32 arg1) {
    s32 v1 = D_006207E4[arg1].unk0;
    struct Inner *a0 = (struct Inner *)(arg0 + 0x104);

    if (v1 != 0 || a0->unk5FB == 0) {
        a0->unk5FA = (u8)arg1;
        a0->unk5FB = (u8)v1;
    }
}

typedef int s32;
typedef unsigned char u8;

struct Src {
    s32 unk0;
    s32 unk4;
};

struct Elem {
    char pad[0x68];
    s32 unk68;
};

struct Dst {
    char pad[0x1F];
    u8 unk1F;
};

extern "C" void func_0055CFB8(char *arg0, Src *arg1) {
    ((Elem *)(arg1->unk0 * 4 + arg0))->unk68 = arg1->unk4;
    ((Dst *)arg0)->unk1F = 1;
}

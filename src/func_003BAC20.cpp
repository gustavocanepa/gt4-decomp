typedef int s32;
typedef unsigned char u8;

struct S003BAC20 {
    char pad[8];
    s32 unk8;
};

extern "C" void func_003BAC20(S003BAC20 *arg0) {
    if (*(u8 *)&arg0->unk8 != 0) {
        arg0->unk8 = arg0->unk8 & ~0xFF;
    }
}

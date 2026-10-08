typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad[0x44];
    u8 unk44;
};

extern "C" void *D_006D6054;

extern "C" f32 func_003E2B00(Obj *arg0) {
    char *p = (char *)D_006D6054 + (s32)arg0->unk44 * 0xA0;
    return *(f32 *)(p + 0xB4);
}

typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x1A];
    u8 unk1A;
};

extern "C" s32 func_006152E0(struct Obj *arg0) {
    return (arg0->unk1A & 6) ? 0 : -1;
}

typedef int s32;
typedef unsigned char u8;

struct Inner {
    char pad[0xCBE7];
    u8 unkCBE7;
};

struct Obj {
    char pad[4];
    Inner *unk4;
};

extern "C" s32 func_00468A40(Obj *arg0) {
    s32 result = 1;
    if (arg0->unk4->unkCBE7 == 0) {
        result = -1;
    }
    return result;
}

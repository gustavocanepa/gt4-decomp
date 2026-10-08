typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 unk0;
    u8 unk1;
};

extern "C" s32 func_00613B68(void *arg0, Obj *arg1) {
    return arg1->unk0 | (arg1->unk1 << 8);
}

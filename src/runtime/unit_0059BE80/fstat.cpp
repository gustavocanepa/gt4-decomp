typedef int s32;
typedef long s64;

struct Obj {
    char pad[0x4];
    s32 unk4;
    char pad48[0x48 - 0x8];
    s64 unk48;
};

extern "C" s32 fstat(void *arg0, Obj *arg1) {
    arg1->unk48 = 0;
    arg1->unk4 = 0x2000;
    return 0;
}

typedef int s32;

struct Elem {
    char pad[0x10];
    s32 unk10;
};

struct Obj {
    char pad[0x20];
};

extern "C" s32 func_00435768(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + (arg1 << 5)))->unk10 & 1;
}

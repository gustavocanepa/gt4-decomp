typedef int s32;
typedef unsigned int u32;
typedef long long s64;

struct Elem {
    char pad[0x10];
    s64 unk10;
    char pad2[0x18];
};

extern "C" s64 func_00433708(char *arg0, u32 arg1) {
    if (arg1 < 0xAU) {
        Elem *entry = &((Elem *)arg0)[arg1];
        return entry->unk10;
    }
    return -1;
}

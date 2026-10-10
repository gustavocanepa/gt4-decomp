typedef unsigned short u16;

struct Struct_001CF2B8 {
    char pad0[0x48];
    u16 unk48;
    char pad48[0xB8 - 0x4A];
};

extern char D_00694DC0[];

extern "C" void *func_001CF2E0(struct Struct_001CF2B8 *arg0) {
    u16 flag = arg0->unk48 & 1;
    if ((flag & 0xFFFF) != 0) {
        return (char *)arg0 + 0xB8;
    }
    return D_00694DC0;
}

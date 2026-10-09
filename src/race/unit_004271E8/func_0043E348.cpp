typedef int s32;
typedef unsigned char u8;

struct Elem {
    char pad[0x132];
    u8 unk132;
};

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" void func_0043E348(struct Obj *arg0, u8 arg1) {
    ((Elem *)((char *)arg0 + arg0->unk490 * 0x178))->unk132 = arg1;
}

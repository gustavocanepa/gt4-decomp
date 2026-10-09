typedef int s32;
typedef unsigned char u8;

struct Elem {
    char pad[0x155];
    u8 unk155;
};

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" void func_0043E788(struct Obj *arg0, u8 arg1) {
    ((Elem *)((char *)arg0 + arg0->unk490 * 0x178))->unk155 = arg1;
}

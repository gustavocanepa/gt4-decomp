typedef int s32;

struct Obj {
    char pad[0x740];
    s32 unk740;
};

struct Elem {
    char pad[0x840];
    s32 unk840;
};

extern "C" void func_00605260(Obj *arg0, s32 arg1) {
    ((Elem *)((char *)arg0 + arg1 * 4))->unk840 = arg0->unk740;
}

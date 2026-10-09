typedef int s32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" void *func_00604CE8(Obj *arg0) {
    return (char *)arg0 + arg0->unk2DC * 0x16C + 4;
}

typedef int s32;

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" char *func_005F37B0(struct Obj *arg0) {
    return (char *)arg0 + ((1 - arg0->unk8C) * 0x44) + 4;
}

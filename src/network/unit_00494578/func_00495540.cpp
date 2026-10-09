typedef int s32;

struct Obj {
    char pad[0x3C];
    s32 unk3C;
};

extern "C" void *func_00495540(Obj *arg0) {
    arg0->unk3C = 1;
    return (char *)arg0 + 0x28;
}

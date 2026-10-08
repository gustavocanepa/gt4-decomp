typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_003A83C8(void *arg0, s32 arg1) {
    Obj *obj = (Obj *)((char *)arg0 + 0x124);
    obj->unk54 = (obj->unk54 & 0xFFFFFF) | (arg1 << 24);
}

typedef int s32;

struct Obj {
    char pad[0xEC];
    s32 unkEC;
};

extern "C" s32 func_00192E90(Obj *arg0) {
    return *(s32 *)(0x618A70 + (arg0->unkEC * 4));
}

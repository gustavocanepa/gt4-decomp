typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_00438CB8(s32 arg0);

extern "C" s32 func_005CD018(struct Obj *arg0) {
    return func_00438CB8(arg0->unk10 + 0x1344);
}

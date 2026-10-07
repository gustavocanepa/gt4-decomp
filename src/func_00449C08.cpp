typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_004AE230(void *buf, s32 arg1, s32 arg2);
extern "C" s32 func_00449CB8(struct Obj *obj);

extern "C" s32 func_00449C08(struct Obj *arg0, s32 arg1) {
    char buf[0x20] __attribute__((aligned(8)));

    func_004AE230(buf, arg1, 1);
    arg0->unk0 = *(s32 *) (buf + 0x10);
    arg0->unk4 = *(s32 *) (buf + 0x8);
    if (func_00449CB8(arg0) == 0) {
        return -1;
    }
    return arg0->unk4;
}

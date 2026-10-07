typedef int s32;
typedef unsigned int u32;

struct S004498E8 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_004AE268(void *buf, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" s32 func_00449CB8(struct S004498E8 *obj);

extern "C" s32 func_00449C58(struct S004498E8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x20] __attribute__((aligned(8)));

    func_004AE268(buf, arg1, arg2, arg3, 1);
    arg0->unk0 = arg2;
    arg0->unk4 = arg3;
    if (func_00449CB8(arg0) == 0) {
        return -1;
    }
    return arg0->unk4;
}

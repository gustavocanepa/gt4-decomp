typedef int s32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" s32 func_00538BF8(void *arg0, s32 arg1);
extern "C" void func_00538C68(void *arg0);

extern "C" s32 func_0050A0E8(Obj **arg0, s32 arg1) {
    s32 temp_v0;

    if (func_00538BF8(arg0, 0x74) != 0) {
        return -4;
    }
    temp_v0 = func_00538BF8((char *) (*arg0) + 0x6C, arg1);
    if (temp_v0 != 0) {
        func_00538C68(arg0);
        return -4;
    }
    (*arg0)->unk70 = arg1;
    return temp_v0;
}

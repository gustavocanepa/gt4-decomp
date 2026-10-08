typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_003A1E10(const char *arg0);

extern "C" void func_003A6D30(struct Obj *arg0) {
    arg0->unk10 = func_003A1E10("gear_base");
}

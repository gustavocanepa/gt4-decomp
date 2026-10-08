typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_004B67A0(Obj *arg0);

extern "C" void func_004B6778(Obj *arg0) {
    s32 result = func_004B67A0(arg0);
    arg0->unk10 = result;
}

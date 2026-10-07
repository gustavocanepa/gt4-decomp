typedef unsigned char u8;
typedef int s32;

extern "C" s32 func_00345CF0(s32 arg0);

extern "C" void func_005F4918(s32 arg0, u8 *arg1) {
    *arg1 += func_00345CF0(arg0);
}

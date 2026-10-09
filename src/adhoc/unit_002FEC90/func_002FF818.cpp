typedef unsigned char u8;
typedef int s32;

extern "C" void func_002FF7E8(void *arg0, u8 *arg1, s32 arg2);

extern "C" u8 func_002FF818(void *arg0) {
    u8 local;
    func_002FF7E8(arg0, &local, 1);
    return local;
}

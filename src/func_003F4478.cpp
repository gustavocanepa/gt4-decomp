typedef int s32;
typedef unsigned int u32;

extern "C" void * func_005A48D8(void *arg0, s32 arg1, u32 arg2);

extern "C" void * func_003F4478(char *arg0) {
    return func_005A48D8(arg0 + 0xCC14, 0, 0x90);
}

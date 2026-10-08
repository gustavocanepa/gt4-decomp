typedef int s32;

struct B { char pad[0x10148]; s32 arr[1]; };

extern "C" void func_003F5768(char *arg0, s32 arg1, s32 arg2) {
    ((B *)(arg0 + arg1 * 4))->arr[0] = arg2;
}

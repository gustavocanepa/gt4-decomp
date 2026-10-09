typedef int s32;
typedef unsigned char u8;

struct S003A9738;

extern "C" void func_003A96F8(struct S003A9738 *arg0, s32 arg1, s32 arg2);

extern "C" void func_005F8498(char *arg0, s32 arg1, s32 arg2) {
    func_003A96F8((struct S003A9738 *)(arg0 + 0x34), arg1, arg2);
}

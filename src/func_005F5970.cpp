typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x30];
    f32 unk30;
};

extern "C" void func_005F5970(char *arg0, s32 arg1, f32 arg2) {
    arg0 = arg0 + arg1 * 0x6C;
    ((Elem *)arg0)->unk30 = arg2;
}

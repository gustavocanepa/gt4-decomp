typedef short s16;
typedef int s32;

struct Elem {
    char pad[0x1C];
    s16 unk1C;
};

extern "C" s16 func_005F5418(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x19C))->unk1C;
}

typedef int s32;

struct Elem {
    char pad[0x198];
    s32 unk198;
};

extern "C" void func_005F5398(char *arg0, s32 arg1, s32 *arg2) {
    ((Elem *)(arg0 + arg1 * 0x19C))->unk198 = *arg2;
}

typedef int s32;

struct S005F38D0 {
    char pad0[0xE10];
    s32 unkE10;
};

extern "C" char *func_005F38D0(struct S005F38D0 *arg0) {
    return (char *)arg0 + (arg0->unkE10 * 0x700) + 0x10;
}

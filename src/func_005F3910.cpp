typedef int s32;

struct Obj {
    char pad[0xE10];
    s32 unkE10;
};

extern "C" char *func_005F3910(struct Obj *arg0) {
    return (char *)arg0 + ((1 - arg0->unkE10) * 0x700) + 0x10;
}

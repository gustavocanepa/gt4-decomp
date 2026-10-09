typedef int s32;

struct Obj00233D28 {
    char pad[0xE8];
    s32 unkE8;
};

extern "C" s32 func_00233D28(Obj00233D28 *arg0) {
    return (arg0->unkE8 >> 3) & 1;
}

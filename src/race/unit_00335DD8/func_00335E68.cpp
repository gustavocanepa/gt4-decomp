typedef int s32;

struct Obj {
    char pad[0x1E0];
    s32 unk1E0;
};

extern "C" void *func_00335E68(struct Obj *arg0) {
    if (arg0->unk1E0 != 0) {
        arg0->unk1E0 = 0;
        return (char *)arg0 + 0x1E4;
    }
    return 0;
}

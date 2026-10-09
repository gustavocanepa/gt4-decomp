typedef int s32;

struct Obj {
    char pad[0x128];
    s32 unk128;
    s32 unk12C;
};

extern "C" s32 func_004CF908(struct Obj *arg0) {
    s32 a = arg0->unk12C;
    if (a != 0) {
        s32 b = arg0->unk128;
        if (b != 0) {
            return a - b;
        }
    }
    return 0;
}

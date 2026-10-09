typedef int s32;

struct Obj001FD5E8 {
    char pad[0xD8];
    s32 unkD8;
};

extern "C" void func_00575DA0(s32 arg0);

extern "C" void func_001FD5E8(struct Obj001FD5E8 *arg0) {
    s32 temp_v0 = arg0->unkD8;

    if (temp_v0 != 0) {
        arg0->unkD8 = 0;
        func_00575DA0(temp_v0);
    }
}

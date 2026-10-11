typedef int s32;

struct Obj003E1BC0 {
    char pad[0x578];
    s32 unk578;
};

extern "C" void free(s32 arg0);

extern "C" void func_003E1BC0(struct Obj003E1BC0 *arg0) {
    s32 temp_v0 = arg0->unk578;

    if (temp_v0 != 0) {
        free(temp_v0);
        arg0->unk578 = 0;
    }
}

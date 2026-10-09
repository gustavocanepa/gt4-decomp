typedef int s32;

struct Obj003AAF70 {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void func_003AAFA0(struct Obj003AAF70 *arg0);

extern "C" void func_003AAF70(struct Obj003AAF70 *arg0, s32 arg1) {
    struct Obj003AAF70 *temp_v1 = arg0;

    if (temp_v1->unk6C != arg1) {
        temp_v1->unk6C = arg1;
        func_003AAFA0(temp_v1);
    }
}

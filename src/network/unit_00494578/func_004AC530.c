typedef int s32;
void func_0057CA38(void *, s32);
void func_004AD240(void *, s32);
void func_005C1628(void *);
extern char D_00688B70[];
extern char D_00688C40[];
struct func_004AC530_temp_a0 {
    char pad0[0x8];
    void *unk8;
};

struct func_004AC530_arg0 {
    char pad0[0xA4];
    void *unkA4;
};

void func_004AC530(void *arg0, s32 arg1) {
    struct func_004AC530_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0xA8;
    ((struct func_004AC530_arg0 *)arg0)->unkA4 = D_00688B70;
    temp_a0->unk8 = D_00688C40;
    func_0057CA38(temp_a0, 0);
    func_004AD240(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

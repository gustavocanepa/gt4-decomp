typedef int s32;
void func_0057CA38(void *, s32);
void func_0055FA30(void *, s32);
void func_005C1628(void *);
extern char D_00689B28[];
extern char D_00689B70[];
struct func_0055ED40_temp_a0 {
    char pad0[0x8];
    void *unk8;
};

struct func_0055ED40_arg0 {
    char pad0[0x3C];
    void *unk3C;
};

void func_0055ED40(void *arg0, s32 arg1) {
    struct func_0055ED40_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0x40;
    ((struct func_0055ED40_arg0 *)arg0)->unk3C = D_00689B28;
    temp_a0->unk8 = D_00689B70;
    func_0057CA38(temp_a0, 0);
    func_0055FA30(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

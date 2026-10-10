typedef int s32;
void func_0057CA38(void *, s32);
void func_00574DA8(void *, s32);
void func_005C1628(void *);
extern char D_00689B88[];
extern char D_00689B70[];
struct func_0055FA30_temp_a0 {
    char pad0[0x8];
    void *unk8;
};

struct func_0055FA30_arg0 {
    char pad0[0x3C];
    void *unk3C;
};

void func_0055FA30(void *arg0, s32 arg1) {
    struct func_0055FA30_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0x30;
    ((struct func_0055FA30_arg0 *)arg0)->unk3C = D_00689B88;
    temp_a0->unk8 = D_00689B70;
    func_0057CA38(temp_a0, 0);
    func_00574DA8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

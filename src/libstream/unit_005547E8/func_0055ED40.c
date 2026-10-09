typedef int s32;
void func_0057CA38(void *, s32);
void func_0055FA30(void *, s32);
void func_005C1628(void *);
extern char D_00689B28[];
extern char D_00689B70[];
void func_0055ED40(void *arg0, s32 arg1) {
    void *temp_a0;
    temp_a0 = (char *)arg0 + 0x40;
    *(void **)((char *)arg0 + 0x3C) = D_00689B28;
    *(void **)((char *)temp_a0 + 8) = D_00689B70;
    func_0057CA38(temp_a0, 0);
    func_0055FA30(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}

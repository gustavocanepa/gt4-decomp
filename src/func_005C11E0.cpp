typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599C0;
extern char D_006D30B0[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C11E0(void) {
    if (D_006599C0.unk0 == 0) {
        D_006599C0.unk0 = D_006D30B0;
        D_006599C0.unk4 = D_0068A370;
    }
    return &D_006599C0;
}

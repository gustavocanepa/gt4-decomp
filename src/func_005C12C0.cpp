typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599E0;
extern char D_006D30D0[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C12C0(void) {
    if (D_006599E0.unk0 == 0) {
        D_006599E0.unk0 = D_006D30D0;
        D_006599E0.unk4 = D_0068A370;
    }
    return &D_006599E0;
}

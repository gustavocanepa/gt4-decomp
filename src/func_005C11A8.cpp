typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599B8;
extern char D_006D30A8[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C11A8(void) {
    if (D_006599B8.unk0 == 0) {
        D_006599B8.unk0 = D_006D30A8;
        D_006599B8.unk4 = D_0068A370;
    }
    return &D_006599B8;
}

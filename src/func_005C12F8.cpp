typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599E8;
extern char D_006D30D8[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C12F8(void) {
    if (D_006599E8.unk0 == 0) {
        D_006599E8.unk0 = D_006D30D8;
        D_006599E8.unk4 = D_0068A370;
    }
    return &D_006599E8;
}

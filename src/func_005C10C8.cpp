typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_00659998;
extern char D_006D3088[];
extern char D_0068A370[];

extern "C" struct S00659988 *func_005C10C8(void) {
    if (D_00659998.unk0 == 0) {
        D_00659998.unk0 = D_006D3088;
        D_00659998.unk4 = D_0068A370;
    }
    return &D_00659998;
}

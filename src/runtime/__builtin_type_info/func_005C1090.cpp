typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_00659990;
extern char D_006D3080[];
extern char __builtin_type_info__vtable[];

extern "C" struct S00659988 *func_005C1090(void) {
    if (D_00659990.unk0 == 0) {
        D_00659990.unk0 = D_006D3080;
        D_00659990.unk4 = __builtin_type_info__vtable;
    }
    return &D_00659990;
}

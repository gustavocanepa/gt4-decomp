typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_006599D0;
extern char D_006D30C0[];
extern char __builtin_type_info__vtable[];

extern "C" struct S00659988 *func_005C1250(void) {
    if (D_006599D0.unk0 == 0) {
        D_006599D0.unk0 = D_006D30C0;
        D_006599D0.unk4 = __builtin_type_info__vtable;
    }
    return &D_006599D0;
}

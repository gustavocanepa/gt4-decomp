typedef int s32;
typedef long long s64;

extern char D_00688338[];

struct Struct_00449D58 {
    s64 unk0;
    s32 unk8;
    s32 unkC;
    void *unk10;
} __attribute__((aligned(8)));

extern "C" void func_00449D58(Struct_00449D58 *arg0) {
    arg0->unk10 = D_00688338;
    arg0->unk0 = -1;
    arg0->unk8 = 0;
    arg0->unkC = 0;
}

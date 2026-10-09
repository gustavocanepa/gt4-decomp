typedef int s32;
typedef long long s64;

struct Obj {
    s64 unk0;
    s64 unk8;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} __attribute__((aligned(8)));

extern "C" void func_001D3AD0(Obj *arg0) {
    arg0->unk18 = -1;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
}

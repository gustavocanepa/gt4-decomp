typedef int s32;
typedef float f32;

struct S { char pad[0x74]; f32 unk74; char pad2[0x98-0x74-4]; s32 unk98; };

extern "C" void mWidget__setRotate(S *arg0, f32 fparg0) {
    arg0->unk74 = fparg0;
    arg0->unk98 = arg0->unk98 | 0x200000;
}

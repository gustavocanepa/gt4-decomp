typedef float f32;

struct S { char pad[0x44]; f32 unk44; };

extern "C" void func_004513F8(S *arg0, f32 arg1) {
    arg0->unk44 = arg1;
}

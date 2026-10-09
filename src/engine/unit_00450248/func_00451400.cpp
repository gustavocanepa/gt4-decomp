typedef float f32;

struct S { char pad[0x48]; f32 unk48; };

extern "C" void func_00451400(S *arg0, f32 arg1) {
    arg0->unk48 = arg1;
}

typedef float f32;

struct S { char pad[0x10]; f32 unk10; };

extern "C" void func_002F9160(S *arg0, f32 arg1) {
    arg0->unk10 = arg1;
}

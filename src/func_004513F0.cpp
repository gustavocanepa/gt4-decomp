typedef float f32;

struct S_004513F0 { char pad[0x40]; f32 unk40; };

extern "C" void func_004513F0(S_004513F0 *arg0, f32 arg1) {
    arg0->unk40 = arg1;
}

typedef unsigned char u8;

struct Struct_00343900 {
    char pad0[0x14];
    u8 unk14;
};

extern "C" void func_00343658(Struct_00343900 *arg0);

extern "C" void func_00343900(Struct_00343900 *arg0) {
    if (arg0->unk14 == 0) {
        return func_00343658(arg0);
    }
}

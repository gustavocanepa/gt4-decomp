typedef int s32;

struct Buf {
    char data[0x40];
};

extern s32 D_00620210;
extern Buf D_0069F3F0[2];

extern "C" void func_004A13C8(Buf *buf);

extern "C" void func_0033DC48(void) {
    D_00620210 ^= 1;
    func_004A13C8(&D_0069F3F0[D_00620210]);
}

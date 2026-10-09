typedef float f32;
typedef unsigned char u8;

struct Obj {
    char pad[0x514];
    f32 unk514;
    char pad2[0x522 - 0x518];
    u8 unk522;
};

extern "C" void func_00351178(struct Obj *arg0) {
    if (arg0->unk514 == 0.0f) {
        arg0->unk522 = 0;
        return;
    }
    arg0->unk522 = 1;
}

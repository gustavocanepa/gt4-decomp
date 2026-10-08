typedef unsigned char u8;

struct Sub {
    char pad[0x5FB];
    u8 unk5FB;
};

extern "C" void func_0035ACB0(void *arg0) {
    struct Sub *temp_a0 = (struct Sub *)((char *)arg0 + 0x104);

    if (temp_a0->unk5FB != 0 && temp_a0->unk5FB != 0xFF) {
        temp_a0->unk5FB = temp_a0->unk5FB + 0xFF;
    }
}

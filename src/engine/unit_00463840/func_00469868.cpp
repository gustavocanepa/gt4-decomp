typedef signed char s8;
typedef unsigned char u8;

struct SubStruct {
    char pad[0x51];
    s8 unk51;
};

struct Struct544 {
    char pad[0x544];
    u8 unk544;
};

extern "C" void func_00469868(void *arg0, struct Struct544 *arg1) {
    struct SubStruct *temp_a0 = (struct SubStruct *)((char *)arg0 + 0x14);

    if (temp_a0->unk51 == arg1->unk544) {
        temp_a0->unk51 = -1;
    }
}

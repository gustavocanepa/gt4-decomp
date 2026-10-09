typedef unsigned char u8;
typedef int s32;

struct Inner00355840 {
    char pad[0x32];
    u8 unk32;
};

struct Obj00355840 {
    char pad0[0x10];
    struct Inner00355840 *unk10;
};

struct Tail00355840 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00355840(struct Obj00355840 *arg0) {
    if (arg0->unk10->unk32 == 3) {
        struct Tail00355840 *tail = (struct Tail00355840 *)((char *)arg0 + 0x788);
        tail->unk0 = 0;
        tail->unk4 = 0;
    }
}

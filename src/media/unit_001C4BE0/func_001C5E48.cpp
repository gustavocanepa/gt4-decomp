typedef int s32;

struct Obj001C5E48 {
    s32 unk0;
    char pad4[0x34 - 0x0 - 4];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
};

extern "C" void func_001C5E48(Obj001C5E48 *arg0) {
    arg0->unk0 = 5;
    arg0->unk3C = 1;
    arg0->unk38 = 0;
    arg0->unk40 = 0;
    arg0->unk34 = 0;
}

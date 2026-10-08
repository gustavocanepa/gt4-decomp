typedef int s32;
typedef unsigned char u8;

struct Obj003FA980 {
    char pad0[1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    char pad4[4];
    u8 unk8;
    char pad9[7];
    u8 unk10;
    char pad11[7];
    u8 unk18;
    char pad19[8];
    u8 unk21;
};

extern "C" void func_003FA980(struct Obj003FA980 *arg0, s32 arg1) {
    arg0->unk1 = 4;
    arg0->unk2 = 4;
    arg0->unk3 = 4;

    if (arg1 != 0) {
        arg0->unk8 = 0;
        arg0->unk10 = 0;
        arg0->unk18 = 0;
    }

    if (arg0->unk21 >= 0x33) {
        arg0->unk21 = 0x32;
    }
}

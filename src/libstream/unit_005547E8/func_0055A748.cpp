typedef int s32;
typedef short s16;

/* Default settings block; field roles are not known yet, names follow the offsets. */
struct Settings {
    s32 unk0;
    s32 pad4;
    long unk8;      /* 64-bit value copied from a read-only default */
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern long D_006C8BD0;

extern "C" void func_0055A748(Settings *s) {
    s->unk8 = D_006C8BD0;
    s->unk10 = -1;
    s->unk0 = 0;
    s->unk24 = 0;
    s->unk14 = 0x3FFF;
    s->unk16 = 0x3FFF;
    s->unk18 = 0x3FFF;
    s->unk1C = 0x40;
    s->unk20 = 0x1000;
}

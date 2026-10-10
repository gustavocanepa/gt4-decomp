typedef int s32;

struct E {
    s32 unk0;
    s32 unk4;
};

struct Big {
    char pad[0x14];
    s32 unk14;
};

extern "C" E D_00623A7C[];
extern "C" char *D_00623A74;

extern "C" s32 getNumber(s32 arg0) {
    s32 idx = D_00623A7C[arg0].unk0;
    return *(s32 *)(D_00623A74 + idx * 8 + 0x14);
}

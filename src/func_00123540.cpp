typedef int s32;

struct Inner00123540 {
    char pad[0x8];
    char **unk8;
};

struct Mid00123540 {
    char pad[0x60];
    Inner00123540 *unk60;
};

struct Top00123540 {
    char pad[0x6C];
    Mid00123540 *unk6C;
};

extern Top00123540 *D_00618710;

extern "C" char *func_00123540(s32 arg0) {
    return D_00618710->unk6C->unk60->unk8[arg0] + 0x20;
}

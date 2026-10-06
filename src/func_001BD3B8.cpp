struct UnkStruct1 {
    char pad[0x10];
    void *unk10;
};

struct UnkStruct2 {
    char pad[0xD4];
    int unkD4;
};

int func_001BD3B8(struct UnkStruct1 *arg0) {
    return ((struct UnkStruct2 *)arg0->unk10)->unkD4;
}

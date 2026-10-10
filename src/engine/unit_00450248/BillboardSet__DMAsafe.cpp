typedef int s32;

struct SomeStruct {
    char pad[0x1C];
    s32 unk1C;
};

extern void func_00498F18(s32);

void BillboardSet__DMAsafe(struct SomeStruct *arg0) {
    s32 temp_v0;

    if (arg0 != 0) {
        temp_v0 = arg0->unk1C;
        if (temp_v0 != 0) {
            func_00498F18(temp_v0);
        }
    }
}

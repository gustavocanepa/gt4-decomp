typedef int s32;

struct Table {
    s32 key;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 slots[1000];
};

extern "C" void func_003BBA30(Table *t, s32 key) {
    t->key = key;
    t->unk4 = 0;
    if (key == 0) {
        t->unk8 = 0;
        t->unkC = 0;
        t->unk10 = 0;
        s32 v = 0x157529FF;
        for (s32 i = 999; i >= 0; i--)
            t->slots[i] = v;
    }
}

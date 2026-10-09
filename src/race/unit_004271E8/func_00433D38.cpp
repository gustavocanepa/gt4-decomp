typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    struct VEntry *unk0;
    char *unk4;
    s32 unk8;
};

extern "C" s32 func_00433818(void *arg0, s32 arg1);

extern "C" void func_00433D38(struct Obj *arg0, s32 arg1)
{
    s32 a1 = arg1;
    s32 s2 = 0;
    s32 s3 = a1;

    if (arg0->unk8 > 0) {
        s32 s1 = 0;

        do {
            s2 += 1;
            void *a0 = arg0->unk4 + s1;
            s1 += 0x238;
            a1 = func_00433818(a0, a1);
        } while (s2 < arg0->unk8);
    }

    struct VEntry *entry = arg0->unk0 + 4;
    entry->fn((char *)arg0 + entry->delta, s3);
}

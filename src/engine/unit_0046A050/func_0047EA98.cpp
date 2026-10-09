typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0047EC10(s32 arg0, s32 arg1);

extern "C" void func_0047EA98(Obj *arg0, s32 arg1)
{
    s32 s3 = arg1;

    if (arg0->unk0 != 0) {
        arg0->unk0 = arg0->unk0 + s3;
    }

    u32 s2 = 0;

    if (arg0->unk4 != 0) {
        s32 s1 = 0;

        do {
            s2 += 1;
            s32 a0 = arg0->unk0 + s1;
            s1 += 0xC;
            func_0047EC10(a0, s3);
        } while (s2 < (u32)arg0->unk4);
    }
}

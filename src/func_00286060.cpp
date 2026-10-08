typedef int s32;

struct S_Vec {
    char pad0[4];
    char *unk4;
    char *unk8;
};

extern "C" s32 func_00286060(void *arg0) {
    struct S_Vec *v = (struct S_Vec *)((char *)arg0 + 0xA0);
    return (s32)(v->unk8 - v->unk4) >> 4;
}

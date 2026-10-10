typedef int s32;

struct Inner {
    char pad0[0x70];
    s32 id;
    char pad74[0x80 - 0x74];
    void *target;
};

struct Obj {
    char pad0[0x6C];
    Inner *inner;
};

extern char D_006A2790[]; /* "crs/bestline/%s" */
extern "C" const char *SPEC_DATABASE__RaceSpec__getRaceLabel(s32 id);
extern "C" int func_0057DA20(char *buf, const char *fmt, ...);
extern "C" s32 func_00395140(void *target, char *name);

extern "C" void func_003BCAE0(Obj *self) {
    char buf[0x80];
    const char *name = SPEC_DATABASE__RaceSpec__getRaceLabel(self->inner->id);
    if (name) {
        func_0057DA20(buf, D_006A2790, name);
        func_00395140(self->inner->target, buf);
    }
}

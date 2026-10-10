typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern char D_006A4CD8[];

extern "C" s32 func_0057F238(const char *a, const char *b);

extern "C" void func_0042AD48(Obj *self, const char *name) {
    if (func_0057F238(name, D_006A4CD8) == 0) {
        self->unk8 = 1;
        self->unk0 = 1;
    }
}

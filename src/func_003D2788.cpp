struct Sub {
    char pad0[0x28];
    int active;
};

struct Obj {
    int unk0;
    Sub sub;
};

extern "C" int func_003CC7B0(Obj *self);
extern "C" int func_003CBCB0(Sub *sub, int arg);

extern "C" int func_003D2788(Obj *self, int arg) {
    if (!func_003CC7B0(self))
        return 0;
    Sub *s = &self->sub;
    if (!s->active)
        return 0;
    return func_003CBCB0(s, arg);
}

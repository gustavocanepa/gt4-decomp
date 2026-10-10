typedef int s32;

struct Sub {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
};

struct Obj {
    s32 a;
    s32 b;
    char pad[0x400];
    Sub s;
};

extern "C" void func_005D6130(void *, s32, s32);

extern "C" void func_0026CAA0(Obj *self, s32 arg1) {
    Sub *s = &self->s;
    s32 unused[4];
    self->b = 0;
    self->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    func_005D6130(s, 0, arg1);
}

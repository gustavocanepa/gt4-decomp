struct Obj { char pad[0xB4]; int count[8]; };
extern "C" int func_003CC7B0(Obj *self, int i);
extern "C" int func_003D2788(Obj *self, int i);

extern "C" int func_003D2840(Obj *self, int i)
{
    if (!func_003CC7B0(self, i))
        return 0;
    if (!func_003D2788(self, i))
        return 0;
    int *c = self->count; if (c[i] < 5) return 0; return 1;
}

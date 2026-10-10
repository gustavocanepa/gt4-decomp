struct Obj { char pad[0x3C]; int slots[8]; };
extern "C" int func_003CC7B0(Obj *self, int i);
extern "C" int func_003D2840(Obj *self, int i);

extern "C" int func_003D27E8(Obj *self, int i)
{
    if (!func_003CC7B0(self, i)) return 0; if (!func_003D2840(self, i)) return 0; return self->slots[i] == 0;
}

typedef int s32;

struct Obj {
    char pad[8];
    float unk8;
    float rate;
    char pad10[8];
    s32 unk18;
};

extern float D_006A1628;

extern "C" void func_003A9850(Obj *o, float t) {
    if (t <= 0.0f)
        o->rate = D_006A1628;
    else
        o->rate = 1.0f / t;
    o->unk18 = 1;
    o->unk8 = -1.0f;
}

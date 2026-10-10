typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

struct State {
    Pair p0;
    Pair p8;
    Pair p10;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern Pair D_00655878;
extern Pair D_00655880;

extern "C" void func_00577290(State *s, const Pair *p) {
    s->p0 = D_00655878;
    s->p8 = *p;
    s->p10 = D_00655880;
    s->unk18 = 0;
    s->unk1C = 0;
    s->unk20 = 0;
    s->unk24 = 0;
}

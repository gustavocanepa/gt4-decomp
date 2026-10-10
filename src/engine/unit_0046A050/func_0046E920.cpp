typedef int s32;

struct Timer {
    s32 unk0;
    s32 end;
    s32 pos;
    s32 unkC;
    s32 total;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 done;
};

extern "C" void func_0046E920(Timer *t, s32 step) {
    if (t->done)
        return;
    t->pos += step;
    t->total += step;
    if (t->pos > t->end) {
        t->unk1C = 1;
        t->done = 1;
    } else if (t->pos >= t->end) {
        t->unk14 = 0;
    }
}

struct Timer {
    int pad0;
    float time;
    char pad8[0xC];
    unsigned char paused;
};

extern char D_00620320[];
extern "C" float func_003507A8(void *clock);

extern "C" void func_003435E8(Timer *t, float dt)
{
    if (t->paused == 0) {
        void *clock = D_00620320;
        t->time += dt;
        if (t->time > func_003507A8(clock))
            t->time = func_003507A8(clock);
    }
}

struct Timer {
    int pad0[4];
    float time;
    unsigned char paused;
};

extern char D_00620B00[];
extern "C" float func_003662F8(void *clock);

extern "C" void func_003439E8(Timer *t, float dt)
{
    if (t->paused == 0) {
        void *clock = D_00620B00;
        t->time += dt;
        if (t->time > func_003662F8(clock))
            t->time = func_003662F8(clock);
    }
}

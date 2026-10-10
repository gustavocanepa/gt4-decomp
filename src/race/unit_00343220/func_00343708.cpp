struct Timer {
    int f0;
    int f4;
    float t;
    int fC;
    int f10;
    unsigned char paused;
};

extern char D_00620320[];
extern "C" float func_003507D0(void *g);
extern "C" float func_00350808(void *g);

extern "C" void func_00343708(Timer *tm, float dt)
{
    if (tm->paused) {
        return;
    }
    if (tm->t < 0.0f) {
        tm->t += dt;
        if (tm->t >= 0.0f) {
            tm->t = -func_003507D0(D_00620320);
        }
    } else {
        tm->t += dt;
    }
    if (func_00350808(D_00620320) < tm->t) {
        tm->t = func_00350808(D_00620320);
    }
}

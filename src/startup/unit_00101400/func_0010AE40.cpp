struct Fade { float rate; float t; };

extern "C" int func_0010AE40(Fade *f, float dt)
{
    if (f->rate != 0.0f) {
        f->t += dt / f->rate;
        if (f->rate > 0.0f) {
            if (f->t >= 1.0f) {
                f->t = 1.0f;
                f->rate = 0.0f;
                return 1;
            }
        } else if (f->t <= 0.0f) {
            f->t = 0.0f;
            f->rate = 0.0f;
            return 1;
        }
    }
    return 0;
}

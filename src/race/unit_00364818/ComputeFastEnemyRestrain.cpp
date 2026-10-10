struct Fade { float amount; float start; float end; };

extern "C" float ComputeFastEnemyRestrain(Fade *f, float x, int unused, int flag)
{
    float r;
    if (flag > 0 || f->end <= x)
        r = 1.0f - f->amount;
    else if (f->start < x)
        r = 1.0f - f->amount * ((x - f->start) / (f->end - f->start));
    else
        r = 1.0f;
    return r;
}

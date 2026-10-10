struct Blink { float period; int count; float interval; float width; };

extern "C" float func_003916E0(Blink *b, float t, float off)
{
    t += off;
    if (b->period < t) t -= b->period;
    int n = (int)(t / b->interval);
    if (n >= b->count) return 0.0f;
    t -= n * b->interval;
    if (b->width < t) return 0.0f;
    t /= b->width * 0.5f;
    t -= 1.0f;
    return 1.0f - t * t;
}

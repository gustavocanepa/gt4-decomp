/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {
    short delta, index;
    void (*fn)(void *, int, float);
};

struct Widget {
    int pad;
    char *vt;
};

struct mFadeActor {
    char pad[0x14];
    Widget *widget;
    float value;
    float from;
    float to;
    float speed;
    float spread;
    float overshootFrom;
    float overshootTo;
    int forward;
    int loop;
    int done;
};

extern char mColorFace__tf[], mWidget__tf[];
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void mWidget__setOpacity(Widget *, float);

#define ABS(x) ((x) >= 0.0f ? (x) : -(x))
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((hi) < (x) ? (hi) : (x)))

static inline Widget *castColored(Widget *w)
{
    if (!w)
        return 0;
    Entry *e = (Entry *)w->vt;
    return (Widget *)__dynamic_cast_2((void *)e->fn, mColorFace__tf, 0, (char *)w + e->delta, mWidget__tf, w);
}

#define SET_COLOR(w, i, v) { Entry *e = (Entry *)((w)->vt + 0x1D8); e->fn((char *)(w) + e->delta, i, v); }

extern "C" void mFadeActor__update(mFadeActor *self)
{
    if (self->done)
        return;

    float target, step;
    if (self->forward) {
        target = self->from < self->to ? self->to + ABS(self->overshootTo) : self->to - ABS(self->overshootTo);
        step = self->from < self->to ? self->speed : -self->speed;
    } else {
        target = self->from < self->to ? self->from - ABS(self->overshootFrom) : self->from + ABS(self->overshootFrom);
        step = self->from < self->to ? -self->speed : self->speed;
    }
    int passed = 0;
    self->value += step;
    if (step < 0.0f) {
        if (self->value < target)
            passed = 1;
    } else {
        if (target < self->value)
            passed = 1;
    }
    if (passed) {
        self->value = target;
        if (self->loop)
            self->forward ^= 1;
        else
            self->done = 1;
    }

    float lo, hi;
    if (self->from < self->to) {
        lo = self->from;
        hi = self->to;
    } else {
        lo = self->to;
        hi = self->from;
    }

    Widget *colored;
    if (self->spread == 0.0f || !(colored = castColored(self->widget))) {
        mWidget__setOpacity(self->widget, CLAMP(self->value, lo, hi));
    } else if (step < 0.0f) {
        SET_COLOR(colored, 0, CLAMP(self->value, lo, hi))
        SET_COLOR(colored, 1, CLAMP(self->value + ABS(self->spread), lo, hi))
        SET_COLOR(colored, 2, CLAMP(self->value + ABS(self->spread), lo, hi))
        SET_COLOR(colored, 3, CLAMP(self->value, lo, hi))
    } else {
        SET_COLOR(colored, 0, CLAMP(self->value, lo, hi))
        SET_COLOR(colored, 1, CLAMP(self->value - ABS(self->spread), lo, hi))
        SET_COLOR(colored, 2, CLAMP(self->value - ABS(self->spread), lo, hi))
        SET_COLOR(colored, 3, CLAMP(self->value, lo, hi))
    }
}

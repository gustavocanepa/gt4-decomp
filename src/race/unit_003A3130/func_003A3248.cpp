class Mode {
public:
    int state;
    virtual int id();
    virtual void v2();
    virtual void apply(int value);
};

extern "C" int RaceEventQueue__check(void *table, int id, int *out, int key);

extern "C" int func_003A3248(Mode *m, char *ctx, int key)
{
    int value;
    if (RaceEventQueue__check(ctx + 0xF4, m->id(), &value, key) == 0) {
        return 0;
    }
    int old = m->state;
    m->apply(value);
    if (old >= 0 && m->state != old) {
        m->state = old;
        return 0;
    }
    return 1;
}

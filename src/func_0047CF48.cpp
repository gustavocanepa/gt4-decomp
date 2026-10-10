struct State {
    int id;
    int count;
    int active;
    float a, b, c, d;
    char buf[128];
    char pad[0x80];
    int m11C;
    int m120;
    void setV(float x, float y, float z, float w) {
        b = y;
        a = x;
        d = w;
        c = z;
    }
};

extern "C" void func_0047CF48(State *s)
{
    s->id = -1;
    s->count = 0;
    s->active = 1;
    s->setV(0.0f, 0.0f, 0.0f, 0.0f);
    for (int i = 127; i >= 0; i--)
        s->buf[i] = 0;
    s->m11C = 0;
    s->m120 = 0;
}

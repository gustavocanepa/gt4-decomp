struct View {
    char pad[0x18];
    float cx;
    float cy;
    float scale;
    float angle;
};

extern "C" void func_004A5F00(float *s, float *c, float angle);

extern "C" void func_003BEBA0(View *v, float *ox, float *oy, float x, float y)
{
    float sc[2];
    *ox = x - v->cx;
    *oy = y - v->cy;
    func_004A5F00(&sc[0], &sc[1], v->angle);
    float a = sc[0] * v->scale;
    float b = sc[1] * v->scale;
    float px = *ox;
    float py = *oy;
    *ox = px * b - py * a;
    *oy = px * a + py * b;
}

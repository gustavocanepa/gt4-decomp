struct Quat { float x, y, z, w; };

extern "C" void func_0057D8A0(float *s, float *c, float a);

extern "C" void func_00487D28(Quat *q, float a, float b) {
    float sc[4];
    float hb = b * 0.5f;
    func_0057D8A0(&sc[0], &sc[1], a * 0.5f);
    func_0057D8A0(&sc[2], &sc[3], hb);
    q->x = sc[0] * sc[3];
    q->y = sc[1] * sc[2];
    q->z = sc[0] * sc[2];
    q->w = sc[1] * sc[3];
}

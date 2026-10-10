struct Vec3 { float x, y, z; };
extern "C" void func_0057D8A0(float a, float *s, float *c);
extern "C" void func_00415240(void *o, Vec3 *v);

extern "C" void func_004152D0(void *o, float *angle)
{
    float sc[4];
    Vec3 v;
    int spare[4];
    *angle -= 1.5707963f;
    Vec3 *pv = &v;
    pv->x = *angle;
    func_0057D8A0(pv->x, &sc[0], &sc[1]);
    float c = sc[1], sn = sc[0];
    pv->x = 0.0f;
    v.y = c;
    v.z = sn;
    func_00415240(o, &v);
    spare[0] = 0;
}

struct Light {
    float a, b, c, d, e, f;
    float pad0;
    float g, h, i, j, k;
    float pad1[2];
    float l;
};
struct Scene { char pad[0x21F0]; Light light; };

extern "C" void func_003B8270(Scene *s, float a, float b, float c, float d, float e, float f,
                              float g, float h, float i, float j, float k, float l)
{
    s->light.a = a;
    s->light.b = b;
    s->light.c = c;
    s->light.d = d * 8.0f;
    s->light.e = e;
    s->light.f = f;
    s->light.g = g;
    s->light.h = h;
    s->light.i = i;
    s->light.j = j;
    s->light.k = k * 128.0f;
    s->light.l = l;
}

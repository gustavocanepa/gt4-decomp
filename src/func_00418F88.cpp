typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec4 {
    union {
        u128 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec4() {}
    Vec4(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
    Vec4 &operator=(const Vec4 &o)
    {
        q = o.q;
        return *this;
    }
};

extern "C" Vec4 D_00622AF0;
extern "C" Vec4 D_00622B20;
extern "C" Vec4 D_00622B50;

struct Frame {
    Vec4 origin;
    char pad[0x60];
    Vec4 a;
    Vec4 b;
    Vec4 c;
    Vec4 d;
    Vec4 e;
};

extern "C" void func_00418F88(Frame *fr)
{
    fr->origin = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    fr->a = D_00622B20;
    fr->b = D_00622B50;
    fr->c = D_00622AF0;
    fr->d = D_00622AF0;
    fr->e = D_00622B50;
}

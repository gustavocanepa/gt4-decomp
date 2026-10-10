class Drawable {
public:
    virtual void v1();
    virtual void v2();
    virtual void draw(float t);
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A5400(void);
extern "C" void func_0044EF18(void *self, float x, float y, float z);

extern "C" void func_0044F058(void *self, Drawable *d, float x, float y, float z, float t)
{
    func_004A53F8();
    func_004A7454();
    d->draw(t);
    func_0044EF18(self, x, y, z);
    func_004A5400();
}

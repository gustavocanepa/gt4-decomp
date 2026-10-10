struct Vec3 { float x, y, z; };
struct Cam { char pad[0x100]; char mtx[0xC0]; Vec3 pos; Vec3 rot; };
extern "C" void func_004A0690(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A79D8(float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7550(void *);
extern "C" void func_004A5400(void);
extern "C" void func_004A06F0(void);

extern "C" void func_00384440(Cam *c)
{
    const float &rx = c->rot.x;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    func_004A79D8(c->rot.z);
    func_004A7988(rx);
    func_004A79B0(c->rot.y);
    func_004A7844(-c->pos.x, -c->pos.y, -c->pos.z);
    func_004A7550(c->mtx);
    func_004A5400();
    func_004A06F0();
}

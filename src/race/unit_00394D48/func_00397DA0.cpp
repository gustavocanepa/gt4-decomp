struct Vec3 { float x, y, z; };
struct Cam { Vec3 pos; float pad; float fov; float aspect; };

extern "C" Vec3 D_00621500;
extern "C" void func_004A40B0(float fov, float aspect);
extern "C" void func_00397E98(void);

extern "C" void func_00397DA0(Cam *c, float scale)
{
    func_004A40B0(c->fov * scale, c->aspect);
    D_00621500.x = c->pos.x;
    D_00621500.y = c->pos.y;
    D_00621500.z = c->pos.z;
    func_00397E98();
}

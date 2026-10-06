struct View { float scale; float rest[15]; } __attribute__((aligned(8)));
struct Cam { struct View view; float fov; };
struct Obj { char pad[0xC80]; struct Cam cam; };
extern struct View D_006211A8;
void func_00377BE0(struct Obj *o, float a, float b, float c, float d)
{
    if (b != 0.0f)
        D_006211A8.scale = b / (c * a);
    struct Cam *cam = &o->cam;
    cam->view = D_006211A8;
    cam->fov = d;
}

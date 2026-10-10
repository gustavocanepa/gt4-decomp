struct func_0049B4C0_Vec4 {
    float x, y, z, w;
};

struct func_0049B4C0_State {
    char pad[0x20];
    func_0049B4C0_Vec4 v[4];
};

extern func_0049B4C0_State D_00624CC0;

extern "C" void func_0049B4C0(unsigned int which, float x, float y, float z, float w) {
    func_0049B4C0_State *s = &D_00624CC0;
    switch (which) {
    case 0:
    case 2:
        s->v[0].x = x;
        s->v[0].y = y;
        s->v[0].z = z;
        s->v[0].w = w;
        if (which == 0)
            break;
    case 1:
        s->v[1].x = x;
        s->v[1].y = y;
        s->v[1].z = z;
        s->v[1].w = w;
        break;
    case 3:
        s->v[3].x = x;
        s->v[3].y = y;
        s->v[3].z = z;
        s->v[3].w = w;
        break;
    case 4:
        s->v[2].x = x;
        s->v[2].y = y;
        s->v[2].z = z;
        s->v[2].w = w;
        break;
    }
}

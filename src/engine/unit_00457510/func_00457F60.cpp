struct V3 {
    float x, y, z;
};

struct Group {
    char pad[0x14];
    void *parts[5];
};

extern "C" void func_00457700(V3 *v);
extern "C" void func_00457D90(void *part, V3 *v, int a, int b, int c, int d);

extern "C" void func_00457F60(Group *g, V3 *v, int a, int b, int c, int d)
{
    func_00457700(v);
    for (int i = 0; i < 5; i++) {
        func_00457D90(g->parts[i], &v[i], a, b, c, d);
    }
}

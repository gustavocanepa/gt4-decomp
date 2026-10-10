struct func_00350DA0_Info {
    unsigned char mode;
    char pad[3];
    float t;
};

struct func_00350DA0_Data {
    char pad[0x234];
    func_00350DA0_Info info;
};

struct func_00350DA0_Range {
    char pad[0x52C];
    float a;
    float b;
};

struct func_00350DA0_Obj {
    char pad0[0x10];
    func_00350DA0_Data *data;
    char pad1[0x104 - 0x14];
    func_00350DA0_Range range;
};

extern "C" float func_00350DA0(func_00350DA0_Obj *self) {
    func_00350DA0_Info *info = &self->data->info;
    func_00350DA0_Range *r = &self->range;
    float v = 0.0f;
    switch (info->mode) {
    case 0: case 4: case 5: case 6: case 7:
        v = r->b;
        break;
    case 1: case 2: case 9:
        v = r->a;
        break;
    case 3: case 10:
        v = (r->a + r->b) * 0.5f;
        break;
    case 8:
        v = r->b + info->t * (r->a - r->b);
        break;
    }
    return v;
}

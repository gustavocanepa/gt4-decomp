struct func_003F2E10_Data {
    char pad[0x1077];
    unsigned char type;
};

struct func_003F2E10_Sub {
    char pad[0x594];
    float v[4];
};

struct func_003F2E10_Obj {
    char pad0[0x10];
    func_003F2E10_Data *data;
    char pad1[0x104 - 0x14];
    func_003F2E10_Sub sub;
};

extern "C" float func_003F2E10(func_003F2E10_Obj *self, int idx) {
    unsigned char type = self->data->type;
    int n = 0;
    switch (type) {
    case 1: case 2: case 5: case 6:
        n = 1;
        break;
    case 3:
        n = 2;
        break;
    case 4:
        n = 4;
        break;
    }
    if (idx >= n)
        return -1.0f;
    func_003F2E10_Sub *s = &self->sub;
    if (type == 4) {
        switch (idx) {
        case 0:
            if (s->v[1] < 0.0f)
                return -s->v[1];
            break;
        case 1:
            if (s->v[1] > 0.0f)
                return s->v[1];
            break;
        case 2: {
            float d = s->v[1];
            float r = s->v[0];
            if (d < 0.0f)
                r -= d;
            if (r > 1.0f)
                r = 1.0f;
            return r;
        }
        case 3: {
            float d = s->v[1];
            float r = s->v[0];
            if (d > 0.0f)
                r += d;
            if (r > 1.0f)
                r = 1.0f;
            return r;
        }
        }
        return 0.0f;
    }
    return self->sub.v[idx];
}

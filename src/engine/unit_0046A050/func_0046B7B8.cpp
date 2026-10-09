typedef int s32;
typedef short s16;
typedef float f32;

struct PathView {
    char unk0;
    char pad1[3];
    s32 count;
    char *points;
    s32 padC;
};

struct PathPoint {
    char pad0[0x4];
    f32 x;
    f32 y;
    f32 z;
    s16 id;
    char pad12[0x2];
    f32 dist;
};

extern "C" f32 func_0046A0B0(void *, void *, s32);
extern "C" void func_00469F08(PathView *, void *, void *);
extern "C" PathPoint *func_00469FC8(PathView *, s32);

extern "C" s32 func_0046B7B8(void *arg0, void *arg1, s32 arg2, f32 d, f32 *ox, f32 *oy, f32 *oz,
                             s32 *oid0, s32 *oid1) {
    PathView view;
    f32 len;
    f32 t;
    s32 i;
    s32 j;
    s32 k;
    s32 last;
    PathPoint *a;
    PathPoint *b;

    i = 0;
    j = 0;
    len = func_0046A0B0(arg0, arg1, arg2);
    t = 0.0f;
    if (oid0 != 0) {
        *oid0 = 0;
    }
    if (oid1 != 0) {
        *oid1 = 0;
    }
    if (d < 0.0f) {
        d += len;
    } else if (len <= d) {
        d -= len;
    }
    if (d < len * 0.5f) {
        d += len;
    }
    func_00469F08(&view, arg0, arg1);
    {
        s32 n = view.count;
        if (d < func_00469FC8(&view, 0)->dist) {
            goto fail;
        }
        last = n - 1;
    }
    if (func_00469FC8(&view, last)->dist <= d) {
    fail:
        return -1;
    }
    k = 0;
    goto test;
    do {
        PathPoint *p0;
        PathPoint *p1;
        i = k;
        p0 = func_00469FC8(&view, i);
        j = i + 1;
        p1 = func_00469FC8(&view, j);
        k = j;
        if (p0->dist <= d && d < p1->dist) {
            t = (d - p0->dist) / (p1->dist - p0->dist);
            break;
        }
    test:;
    } while (k < last);
    a = func_00469FC8(&view, i);
    b = func_00469FC8(&view, j);
    {
        f32 x = t * (b->x - a->x) + a->x;
        f32 y = t * (b->y - a->y) + a->y;
        *ox = x;
        *oy = y;
    }
    *oz = t * (b->z - a->z) + a->z;
    if (oid0 != 0) {
        *oid0 = a->id;
    }
    if (oid1 != 0) {
        *oid1 = b->id;
    }
    return i;
}

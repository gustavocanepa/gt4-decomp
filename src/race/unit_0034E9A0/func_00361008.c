/* Builds two curves from 6 byte tables: the first n points mirrored (index n - i), the next m
 * appended; tracks the x of the largest y. The second loop is a do-while (not reversed by gcc). */
typedef unsigned char u8; typedef int s32; typedef float f32;

typedef struct Src {
    char pad0[9];
    u8 n;
    u8 m;
    char padB[0x20 - 0xB];
    u8 a[8];
    u8 b[8];
    u8 c[8];
    u8 d[8];
    u8 e[8];
    u8 f[8];
} Src;

typedef struct CurveA {
    char hdr[8];
    f32 x[12];
    f32 y[13];
} CurveA;

typedef struct CurveB {
    char hdr[8];
    f32 z[12];
} CurveB;

typedef struct Dst {
    char pad0[0xF8];
    CurveA a;
    f32 f164;
    f32 f168;
    f32 f16C;
    CurveB b;
} Dst;

void func_00359A38(void *, s32, void *, void *, s32, s32);

void func_00361008(s32 arg0, Dst *d, Src *s) {
    f32 max;
    s32 n, m, i;
    f32 t0, t1;

    max = 0.0f;
    s->a[0] = 0;
    n = s->n;
    s->e[0] = s->f[0];
    s->c[0] = 0;
    s->b[0] = 0;
    s->d[0] = 0;
    m = s->m;
    d->f164 = max;
    for (i = 0; i < n; i++) {
        t1 = -(f32)s->a[i] / 255.0f;
        d->a.x[n - i] = t1;
        t0 = (f32)s->c[i] / 200.0f;
        d->a.y[n - i] = t0;
        if (max < t0) {
            d->f164 = d->a.x[n - i];
            max = t0;
        }
        d->b.z[n - i] = (f32)s->e[i] / 200.0f;
    }
    max = 0.0f;
    d->f168 = max;
    d->f16C = 1.0f;
    i = 0;
    if (m != 0) do {
        t1 = (f32)s->b[i] / 255.0f;
        d->a.x[n + i] = t1;
        t0 = (f32)s->d[i] / 200.0f;
        d->a.y[n + i] = t0;
        if (max < t0) {
            max = t0;
            d->f168 = d->a.x[n + i];
            d->f16C = max;
        }
        d->b.z[n + i] = (f32)s->f[i] / 200.0f;
    } while (++i < m);

    func_00359A38(&d->a, n + m - 1, &d->a.x[1], &d->a.y[1], 0, 0);
    func_00359A38(&d->b, n + m - 1, &d->a.x[1], &d->b.z[1], 0, 0);
}

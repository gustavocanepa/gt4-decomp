typedef unsigned char u8;

struct S {
    char pad0[0xC];
    float x[2];         /* 0x0C */
    char pad14[0x4];
    float y[2];         /* 0x18 */
    char pad20[0x466 - 0x20];
    signed char m466;   /* 0x466 */
    u8 m467;            /* 0x467 */
    char pad468[0x48C - 0x468];
    float m48C;         /* 0x48C */
    float m490;         /* 0x490 */
    char pad494[0x4BA - 0x494];
    unsigned short m4BA; /* 0x4BA */
    u8 m4BC;            /* 0x4BC */
    char pad4BD[0x53C - 0x4BD];
    float m53C;         /* 0x53C */
    int m540;           /* 0x540 */
    float v[2];         /* 0x544 */
    char pad54C[0x550 - 0x54C];
    float m550;         /* 0x550 */
    float m554;         /* 0x554 */
    char pad558[0x564 - 0x558];
    int m564;           /* 0x564 */
    char pad568[0x57C - 0x568];
    int m57C;           /* 0x57C */
    char pad580[0x58C - 0x580];
    int m58C;           /* 0x58C */
};

extern "C" u8 *func_00359510(int);

extern "C" void func_00352C90(u8 *p, int arg1)
{
    struct S *s = (struct S *)(p + 0x104);
    u8 *info = func_00359510(*(int *)(p + 0x10));
    float dt = *(float *)(p + 0x54C);
    bool stop;

    if (s->m4BA != 0) {
        s->m564 = 0;
        s->m57C = 0;
        s->v[0] = 0.0f;
        s->v[1] = 0.0f;
        return;
    }
    if (arg1 != 0)
        return;

    stop = false;
    if (s->m4BC != 0 || s->m467 == 8) {
        stop = true;
    } else if (s->m467 != 1 && s->m467 != 2 && s->m467 != 4 && s->m466 != 1 && s->m466 != 2) {
        float a = s->m53C;
        if (a > -0x1.1c71c6p-2f && a < 0x1.1c71c6p-2f) {
            bool still = true;
            int n = info[1];
            int moving = 0;
            int i;
            for (i = 0; i < n; i++) {
                float *e = (float *)(p + 0x1C4 + i * 0xEC);
                if (*e != 0.0f) {
                    still = false;
                    break;
                }
            }
            if (s->m48C > 0.0f || s->m490 > 0.0f)
                moving = 1;
            if (still && moving)
                stop = true;
        }
    }

    if (stop) {
        s->m57C = 0;
        s->v[0] = 0.0f;
        s->v[1] = 0.0f;
        s->m564 = 0;
        s->m550 = 0.0f;
        s->m554 = 0.0f;
        s->m58C = 0;
        s->m53C = 0.0f;
        s->m540 = 0;
    } else {
        float a = s->m550 * dt;
        float b = s->m554 * dt;
        int i;
        for (i = 0; i < 2; i++)
            s->v[i] += a * s->x[i] + b * s->y[i];
    }
}

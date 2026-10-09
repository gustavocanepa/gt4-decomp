typedef unsigned char u8;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

extern "C" u8 *func_00359510(int);
extern "C" int func_00343C20(u8 *);
extern "C" int func_00354E38(u8 *);
extern "C" float func_0034C780(u8 *, int);
extern "C" float func_0034C230(u8 *);
extern "C" float func_00354E60(u8 *);
extern "C" int func_00367D20(u8 *);
extern "C" int func_0035FA50(u8 *);

extern "C" void func_00353218(u8 *p)
{
    u8 *s = p + 0x104;
    int flags = 0;
    u8 *dc = *(u8 **)(p + 4);
    u8 *info = func_00359510(*(int *)(p + 0x10));
    u8 *sub;
    VEntry *e;
    int i;

    s[0x5C2] = 0;
    sub = dc + 4;
    e = (VEntry *)(*(char **)(dc + 0x10140) + 0x180);
    if (e->fn(dc + e->delta) == 0)
        return;
    if (s[0x4B1] & 8)
        return;
    if (s[0x4B2] != 0)
        return;
    if (func_00343C20(p) != 0)
        return;

    if (func_00354E38(p) != 0 && *(float *)(s + 0x4C8) > 500.0f) {
        float limit = func_0034C780(dc, 1);
        if (*(float *)(s + 0x4A4) < limit) {
            float t = func_0034C230(dc);
            t = (limit - *(float *)(s + 0x4A4) + t)
                / (*(float *)(s + 0x4C8) / *(float *)(s + 0x4C4)) * 1.05f;
            if (func_00354E60(p) < t)
                flags = 1;
        }
    }

    if (func_00367D20(sub) != 0) {
        int j = 0;
        if (j < info[1]) {
            do {
                u8 *w = p + 0x164 + j * 0xEC;
                if (*(float *)(w + 0xAC) < 0.0f) {
                    s[0x5C2] = 1;
                } else if (*(float *)(w + 0x50) < *(float *)(sub + 0x20)) {
                    flags |= 1;
                    s[0x5C2] = 1;
                    break;
                }
                j++;
            } while (j < info[1]);
        }
    }

    if (func_0035FA50(p) == 4) {
        for (i = 0; i < info[1]; i++) {
            u8 *q = p + 0x1AB + i * 0xEC;
            if (*q != 0) {
                flags |= 2;
                break;
            }
        }
    }

    if (flags != 0) {
        s[0x4B1] |= 4;
        if (*(signed char *)(s + 0x466) == 2) {
            s[0x4B1] |= 8;
        } else if (*(signed char *)(s + 0x466) == 1 && s[0x5C1] == 0) {
            s[0x4B1] |= 8;
        }
    }
}

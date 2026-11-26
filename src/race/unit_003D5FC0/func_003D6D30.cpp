/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame update of the four sparks of an emitter (names inferred from the arithmetic).
 * A spark is started when the source level rises above 0.1 and a random draw stays below it;
 * a running spark advances by dt * speed and is retired once its position passes 1.
 *
 * The loop both steps `s` in its header and re-derives it from the index at the top of the body.
 * That leftover is what the object code shows: `s` is set twice per iteration, so the loop pass
 * does not treat it as an induction variable and keeps `s = base + 0x10` in the loop, while the
 * indexed address `self + i * sizeof(Spark)` is strength-reduced into its own register. */
struct Spark {
    float pos;      /* 0x00: 0..1 along its path, negative while delayed */
    float size;     /* 0x04 */
    float angle;    /* 0x08: degrees */
    float speed;    /* 0x0C: position units per second */
    int active;     /* 0x10 */
};

struct Emitter {
    int unk0;
    void *source;       /* 0x04 */
    int unk8;
    signed char unkC[4];
    Spark sparks[4];    /* 0x10 */
    int loud;           /* 0x60: level was above the threshold last frame */
    int spawned;        /* 0x64: a spark was started (cleared by the reader) */
    int seed;           /* 0x68 */
};

extern "C" float func_003F33A8(void *source, int *out);
extern "C" float func_003D6D18(Emitter *self); /* random float from self->seed */

extern "C" void func_003D6D30(Emitter *self, float dt)
{
    int unused;
    float level;
    int loud;
    int trigger;
    int i;

    if (self->source == 0)
        return;
    unused = 0;
    level = func_003F33A8(self->source, &unused);
    loud = level > 0.1f;
    trigger = 0;
    if (loud)
        trigger = self->loud == 0;
    self->loud = loud;
    if (trigger && level < func_003D6D18(self))
        trigger = 0;

    Spark *s = self->sparks;
    for (i = 0; i < 4; i++, s++) {
        s = &self->sparks[i];
        if (s->active) {
            s->pos += dt * s->speed;
            if (1.0f < s->pos) {
                s->active = 0;
                s->pos = 0.0f;
            }
        } else if (trigger) {
            s->active = 1;
            s->speed = 1.0f / (func_003D6D18(self) * 0.1f + 0.1f);
            s->pos = -s->speed * (func_003D6D18(self) * 0.02f + 0.01f);
            s->angle = func_003D6D18(self) * 360.0f;
            s->size = func_003D6D18(self) * 0.4f + 0.8f;
            self->spawned = 1;
        }
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj { s32 base; char *vtable; };

/* gcc 2.9x virtual table entry: this-adjustment, index, function. */
struct SlotInt { short delta, index; s32 (*fn)(void *); };
struct SlotFloat { short delta, index; f32 (*fn)(void *); };
struct SlotVoid { short delta, index; void (*fn)(void *); };
struct SlotArg { short delta, index; void (*fn)(void *, void *); };
struct SlotDraw { short delta, index; void (*fn)(void *, s32, void *, void *, void *); };

static inline s32 callInt(Obj *o, s32 slot) { SlotInt *e = (SlotInt *)(o->vtable + slot); return e->fn((char *)o + e->delta); }
static inline f32 callFloat(Obj *o, s32 slot) { SlotFloat *e = (SlotFloat *)(o->vtable + slot); return e->fn((char *)o + e->delta); }
static inline void callVoid(Obj *o, s32 slot) { SlotVoid *e = (SlotVoid *)(o->vtable + slot); e->fn((char *)o + e->delta); }
static inline void callArg(Obj *o, s32 slot, void *arg) { SlotArg *e = (SlotArg *)(o->vtable + slot); e->fn((char *)o + e->delta, arg); }

struct Handle { Obj *p; };

struct mMovieFace {
    char pad0[0xB4];
    void *texture;
    char padB8[0x5C];
    Handle movie;
};

extern "C" void func_002030A0(void *);
extern "C" void func_002030E8(void *, void *);
extern "C" void func_00203118(void *, s32);
extern "C" void mWidget__getWindowSize(mMovieFace *, f32 *, f32 *);
extern "C" s32 func_00286060(mMovieFace *);
extern "C" void *func_002861D8(mMovieFace *, s32);
extern "C" void mImageFace__virtual_70(mMovieFace *, Obj *, s32);

struct Color {
    f32 v[4];
    Color() { func_002030A0(this); }
    ~Color() { func_00203118(this, 2); }
};
struct Point { f32 x, y; };

/* mMovieFace::render (virtual slot 70): while the movie is playing, the still image is drawn
   inactive and the current movie frame is drawn as one textured quad over the widget, with the
   face's colour(s) when it has one or four.
   The two quads are filled through a cursor (`p->x = ...; p++`): the `.x` stores then go
   through a register address, which cse cannot tell from the `w`/`h` stack slots, so each
   corner reloads them (reload turns the second pair into retail's `mov.s $f2,$f0` /
   `mov.s $f3,$f1`). Indexed stores (`pos[3].x = w`) share one load and lose the copies. */
extern "C" void mMovieFace__virtual_70(mMovieFace *self, Obj *ctx, s32 active) {
    Handle *movie = &self->movie;
    s32 playing = 0;
    if (movie->p != 0) playing = callInt(movie->p, 0x48) != 0;
    mImageFace__virtual_70(self, ctx, !playing);
    if (active && playing) {
        callVoid(movie->p, 0x68);
        callVoid(ctx, 0x1D0);
        callArg(ctx, 0x1C0, self->texture);
        callVoid(movie->p, 0x78);
        f32 w, h;
        mWidget__getWindowSize(self, &w, &h);
        Point posData[4];
        Point *pos = posData;
        Point *p = pos;
        p->x = 0.0f; p->y = 0.0f; p++;
        p->x = w;    p->y = 0.0f; p++;
        p->x = 0.0f; p->y = h;    p++;
        p->x = w;    p->y = h;
        f32 u = callFloat(movie->p, 0x80);
        f32 v = callFloat(movie->p, 0x88);
        Point uvData[4];
        Point *uv = uvData;
        Point *q = uv;
        q->x = 0.0f; q->y = 0.0f; q++;
        q->x = u;    q->y = 0.0f; q++;
        q->x = 0.0f; q->y = v;    q++;
        q->x = u;    q->y = v;
        Color colors[4];
        void *colorArg;
        if (func_00286060(self) == 1) {
            callArg(ctx, 0x198, func_002861D8(self, 0));
            colorArg = 0;
        } else if (func_00286060(self) == 4) {
            func_002030E8(&colors[0], func_002861D8(self, 0));
            func_002030E8(&colors[1], func_002861D8(self, 1));
            func_002030E8(&colors[2], func_002861D8(self, 3));
            func_002030E8(&colors[3], func_002861D8(self, 2));
            colorArg = colors;
        } else {
            colorArg = 0;
        }
        SlotDraw *e = (SlotDraw *)(ctx->vtable + 0x1B0);
        e->fn((char *)ctx + e->delta, 4, pos, uv, colorArg);
        callVoid(ctx, 0x1C8);
        callVoid(ctx, 0x1D8);
        callVoid(movie->p, 0x70);
    }
}

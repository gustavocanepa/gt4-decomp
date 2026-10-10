typedef int s32;
typedef unsigned short u16;
typedef short s16;

struct Arr { u16 n; u16 data[1]; };
struct Self { char pad[0x14]; Arr *m14; };
extern "C" s32 func_006002A0(u16 *, u16 *, s16 *);

extern "C" s32 func_0042A828(Self *self, s16 v) {
    s16 key = v;
    Arr *a = self->m14;
    if (a == 0) return 1;
    {
        u16 *b = a->data;
        return func_006002A0(b, b + a->n, &key);
    }
}

typedef short s16;
typedef unsigned char u8;
typedef int s32;

struct Self { char pad[0xF85E]; u8 max; char pad2[0x7DD]; s16 cur; };

extern "C" s16 func_0035DF28(Self *self) {
    if (self->cur < self->max) self->cur++;
    return self->cur;
}

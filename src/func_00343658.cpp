typedef unsigned char u8;
typedef float f32;

struct Self { char pad[4]; f32 m4; char pad2[0xC]; u8 m14; };
extern char D_00620320[];
extern "C" f32 func_00350780(char *);

extern "C" void func_00343658(Self *self) {
    if (self->m14 == 0) {
        self->m4 = func_00350780(D_00620320);
    }
}

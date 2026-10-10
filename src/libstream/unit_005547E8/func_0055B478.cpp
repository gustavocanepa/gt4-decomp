/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Stream { u8 *p; };
struct Self { char pad[0x28]; s64 m28; char pad2[4]; s32 m34; char pad3[0x20]; Stream s; };
extern "C" void func_0055AA28(Self *, s64, s32, s32, s32);

static inline s32 getbyte(Stream *s) { return *s->p++; }

// Without strict aliasing the stream store pins the loads around it: mode is func_005AE2E8 before the
// byte, m28 after it (arguments are expanded right to left), which leaves $a1 func_00575DA0 for &self->s.
extern "C" void func_0055B478(Self *self) {
    s32 mode = self->m34 & 0xF;
    func_0055AA28(self, self->m28, mode, getbyte(&self->s), 0);
}

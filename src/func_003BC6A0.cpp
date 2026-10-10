typedef int s32;

struct Sub { s32 m0; };
struct Self { char pad[0x24E5C]; Sub sub; };
extern "C" void *func_004080F8(Sub *);
extern "C" void func_003EDA10(void *);

extern "C" void func_003BC6A0(Self *self) {
    Sub *p = &self->sub;
    if (p->m0 != 0) {
        func_003EDA10(func_004080F8(p));
    }
}

typedef int s32;

struct Cb { void (*fn)(void); s32 arg; };
struct Self { char pad[0x18]; Cb cb; };
extern "C" void func_004AFDC8(Self *);
extern "C" void func_0044D540(void);

extern "C" void FileInstrumentStream__reset(Self *self) {
    Cb t;
    func_004AFDC8(self);
    t.fn = func_0044D540;
    t.arg = 0;
    self->cb = t;
}

typedef int s32;

struct Self { char pad[0x18]; s32 m18; };
extern char D_006A16C8[];
extern char D_006A16D8[];
extern "C" void RaceDisplayObjectBase__selectTexture(Self *, char *);
extern "C" s32 func_003A1E10(char *);

extern "C" void func_003AB3B8(Self *self) {
    RaceDisplayObjectBase__selectTexture(self, D_006A16C8);
    self->m18 = func_003A1E10(D_006A16D8);
}

typedef int s32;

struct Self { char pad[0x18]; s32 m18; };
extern "C" void mUpdateContext__Sync(s32);

extern "C" void mTransition__syncIn(Self *self) {
    while (self->m18 == 1 || self->m18 == 2) {
        mUpdateContext__Sync(1);
    }
}

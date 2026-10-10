typedef int s32;

extern "C" void SePlayer__Stop(void *, s32);
extern "C" void SePlayer__Initialize(void *, s32, s32);

extern "C" void func_00462A40(void *self, s32 a) {
    SePlayer__Stop(self, 0);
    SePlayer__Initialize(self, a, 0);
}

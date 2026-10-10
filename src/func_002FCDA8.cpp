typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline s32 vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" float func_0057D6C0(float, float);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct Self {
    char pad0[0x10];
    s32 value;
};

extern "C" void func_002FCDA8(Self *self, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    s32 v = vcall(*other);
    func_002FE278(buf, (s32)func_0057D6C0((float)self->value, (float)v));
    if (result != buf) {
        s32 newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        s32 oldVal = *result;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *result = newVal;
    }
    func_002FC870(buf, 2);
}

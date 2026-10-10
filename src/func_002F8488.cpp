typedef int s32;
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct HFloat {
    char pad0[0x10];
    float value;
};

extern "C" void func_002F8488(HFloat *self, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    float f = vcall_60(*other);
    func_002FE278(buf, self->value <= f);
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

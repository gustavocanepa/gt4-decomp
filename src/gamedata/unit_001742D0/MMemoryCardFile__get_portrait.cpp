/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef s32 (*Fn)(char *);
struct Entry { s16 delta; s16 index; Fn fn; };
struct Obj { char pad[0x4c]; Entry *vt; };
struct Holder { char pad[0x10]; Obj *obj; };
extern "C" void func_00174148(void *) throw();
extern "C" void func_001740F0(void *, int) throw();
extern "C" void func_002FE278(void *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_005D15A8(char *);
extern "C" s32 func_005D1260(char *);
extern "C" Obj *__dynamic_cast_2(Fn, Fn, int, char *, Fn, Obj *);
static inline s32 invoke(Obj *self) {
    Entry *e = (Entry *)((char *)self->vt + 0xb8);
    return e->fn((char *)self + e->delta);
}
extern "C" void MMemoryCardFile__get_portrait(s32 *arg0) {
    s32 buf[4];
    Obj *object;
    s32 newVal, oldVal;
    func_00174148(buf);
    Obj *base = ((Holder *)buf[0])->obj;
    object = 0;
    if (base) {
        Entry *e = base->vt;
        object = __dynamic_cast_2(e->fn, func_005D15A8, 0, (char *)base + e->delta, func_005D1260, base);
    }
    func_001740F0(buf, 2);
    s32 flag;
    if (object == 0 || invoke(object) == 0) flag = 0;
    else flag = 1;
    func_002FE278(buf, flag);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal) func_003285A8(newVal);
        oldVal = *arg0;
        if (oldVal) func_003285F8(oldVal);
        *arg0 = newVal;
    }
    func_002FC870(buf, 2);
}

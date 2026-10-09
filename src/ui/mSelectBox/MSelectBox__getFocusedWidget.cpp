typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_002D8B08(void *);
extern "C" s32 func_002DB130(s32);
extern "C" void func_00309348(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_002D8AB0(void *, s32);

extern "C" void MSelectBox__getFocusedWidget(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_002D8B08(buf0);
    t1 = func_002DB130(buf0[0]);
    p_s2 = buf1;
    if (t1 != 0) {
        buf2[0] = t1;
        func_00309348(p_s2, buf2);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00309378(p_s2, 0x2);
    }
    func_002D8AB0(buf0, 0x2);
}

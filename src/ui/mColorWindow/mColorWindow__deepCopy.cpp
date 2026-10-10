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

extern char mColorWindow__tf[];
extern char hObject__tf[];
extern "C" void mComposite__deepCopy(void);
extern "C" s32 GT4MC__FileGT4GameData__loadInstance(s32, void *, s32, void *, void *, void *);
extern "C" void func_005E49B0(void *, s32);

struct mColorWindow__virtual_08_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct mColorWindow__virtual_08_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};
struct mColorWindow__virtual_08_v_s1 {
    char pad0[0xC0];
    s32 unkC0;
};

extern "C" void mColorWindow__deepCopy(s32 *arg0, void *arg1) {
    s32 v_s1;
    v_s1 = 0;
    mComposite__deepCopy();
    if (arg1 != 0) {
        v_s1 = GT4MC__FileGT4GameData__loadInstance(*(s32 *)((char *)(((struct mColorWindow__virtual_08_arg1 *)arg1)->unk4) + 0x4), &mColorWindow__tf, 0, (char *)arg1 + (s32)*(s16 *)(char *)(((struct mColorWindow__virtual_08_arg1 *)arg1)->unk4), &hObject__tf, arg1);
    }
    if (v_s1 != 0) {
        if ((char *)arg0 + 0xb0 != (char *)(v_s1 + 0xb0)) {
            func_005E49B0((char *)arg0 + 0xb0, v_s1 + 0xb0);
        }
        ((struct mColorWindow__virtual_08_arg0 *)arg0)->unkC0 = ((struct mColorWindow__virtual_08_v_s1 *)v_s1)->unkC0;
    }
}

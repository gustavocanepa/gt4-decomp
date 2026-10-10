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

extern "C" void mWidget__getWindowSize(s32, void *, void *);
extern "C" void func_00263C40(s32);
extern "C" void func_0025B500(s32, void *, void *, void *, void *);
extern "C" void func_002D21E0(void *, f32, f32, f32);
extern "C" void mBox__virtual_92(void *, void *);

struct mScrollWindow__virtual_92_arg0 {
    char pad0[0xBC];
    s32 unkBC;
    s32 unkC0;
};
struct mScrollWindow__virtual_92_buf0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct mScrollWindow__virtual_92_buf1 {
    f32 unk0;
    f32 unk4;
};

extern "C" void mScrollWindow__virtual_92(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    mWidget__getWindowSize(((struct mScrollWindow__virtual_92_arg0 *)arg0)->unkBC, buf0, (char *)buf0 + 0x4);
    func_00263C40(((struct mScrollWindow__virtual_92_arg0 *)arg0)->unkC0);
    func_0025B500(((struct mScrollWindow__virtual_92_arg0 *)arg0)->unkC0, (char *)buf0 + 0x8, (char *)buf0 + 0xc, buf1, (char *)buf1 + 0x4);
    func_002D21E0((char *)arg0 + 0xc4, ((struct mScrollWindow__virtual_92_buf0 *)buf0)->unk0, ((struct mScrollWindow__virtual_92_buf0 *)buf0)->unk8, ((struct mScrollWindow__virtual_92_buf1 *)buf1)->unk0);
    func_002D21E0((char *)arg0 + 0xfc, ((struct mScrollWindow__virtual_92_buf0 *)buf0)->unk4, ((struct mScrollWindow__virtual_92_buf0 *)buf0)->unkC, ((struct mScrollWindow__virtual_92_buf1 *)buf1)->unk4);
    mBox__virtual_92(arg0, arg1);
}

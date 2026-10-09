typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

struct Out {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_0015AA68(void *arg0, int arg1);
extern "C" void func_0015AAC0(void *arg0, void *arg1);
extern "C" void func_004336D0(s32 arg0, s32 arg1);

extern "C" void MCourseRecordUnit__updateBestScore(s32 arg0, void *arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    ObjA *obj;
    VEntry *entry;
    s32 result;
    Out *outp;

    if (arg2 > 0) {
        obj = arg3->obj;
        entry = obj->vtbl + 11;
        result = entry->fn((char *)obj + entry->delta);
        func_0015AAC0(buf, arg1);
        outp = (Out *)buf[0];
        func_004336D0(outp->unk10, result);
        func_0015AA68(buf, 2);
    }
}

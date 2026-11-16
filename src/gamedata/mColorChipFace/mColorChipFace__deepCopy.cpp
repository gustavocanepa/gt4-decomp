#include "types.h"

struct Entry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[4];
    Entry *vtable;
};

struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; };

extern char mColorChipFace__tf[];
extern char hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(s32, void *, s32, void *, void *, void *);
extern "C" void func_0015A220(char *, Str *, s32);

struct mColorChipFaceLayout {
    void *ref_count;
    void *vtable;
    char widget_body[0x98];
    Str strings[2];
};

extern "C" void mColorChipFace__deepCopy(void *self, void *src) {
    mWidget__deepCopy(self, src);
    mColorChipFaceLayout *copy = 0;
    if (src != 0) {
        Obj *source = (Obj *)src;
        Entry *entry = source->vtable;
        copy = (mColorChipFaceLayout *)__dynamic_cast_2((s32)entry->fn, mColorChipFace__tf, 0,
                             (char *)src + entry->delta, hObject__tf, src);
    }
    if (copy != 0) {
        for (s32 i = 0; i < 2; ++i) {
            func_0015A220((char *)self, &copy->strings[i], i);
        }
    }
}

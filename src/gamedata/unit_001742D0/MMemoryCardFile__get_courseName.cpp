/* Script property getter on a memory-card file object: resolves the file handle arg1, asks its file object (+0x10 -> tab) to load the GT4 game-data instance (GT4MC::FileGT4GameData::loadInstance), and when that succeeds calls its virtual slot +0x98 to get a C string, wrapped into a script string and assigned (retain/release) into *out. Without an instance a fixed default string (D_00690D18) is returned instead. The course-name string is inferred from the accessor name; the exact slot meaning is not otherwise documented. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Obj {
    void *p;
    char pad[0xC];
};

struct Handle {
    s32 v;
    char pad[0xC];
};

struct Vt {
    short delta;
    short index;
    void *fn;
};

struct Inner {
    char pad0[0x4C];
    Vt *tab;
};

struct Outer {
    char pad0[0x10];
    Inner *in;
};

extern Rep D_00659FA8;
extern char D_005D15A8[];
extern char D_005D1260[];
extern char D_00690D18[];

extern "C" void func_00174148(void *arg0, void *arg1);
extern "C" void func_001740F0(void *arg0, int arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" Inner *__dynamic_cast_2(void *arg0, const char *arg1, int arg2, void *arg3, const char *arg4, Inner *arg5);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

static inline void release(Str *ps)
{
    Rep *q = (Rep *)(ps->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline void assign(s32 *dst, Handle *h)
{
    if (dst != &h->v) {
        s32 newVal = h->v;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *dst;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *dst = newVal;
    }
}

extern "C" void MMemoryCardFile__get_courseName(s32 *out, void *fileHandle) {
    Obj file;
    Handle result;
    Str nameText;
    Str defaultText;
    Inner *fileObject;
    Inner *gameData;

    func_00174148(&file, fileHandle);
    fileObject = ((Outer *)file.p)->in;
    gameData = 0;
    if (fileObject != 0) {
        gameData = __dynamic_cast_2(fileObject->tab->fn, D_005D15A8, 0, (char *)fileObject + fileObject->tab->delta, D_005D1260, fileObject);
    }
    if (gameData != 0) {
        Str *textPtr = &nameText;
        const char *name;
        Vt *nameSlot = (Vt *)((char *)gameData->tab + 0x98);
        name = ((char *(*)(void *))nameSlot->fn)((char *)gameData + nameSlot->delta);
        {
            Rep *emptyRep = &D_00659FA8;
            char *chars;
            if (emptyRep->sel != 0) {
                chars = func_005C2560(emptyRep);
            } else {
                chars = (char *)(emptyRep + 1);
                emptyRep->ref++;
            }
            *(s32 *)&textPtr->p = (s32)chars;
        }
        func_005C2630(textPtr, 0, -1, name, func_0057F260(name));
        Handle *resultPtr = &result;
        func_00314B20(resultPtr, textPtr);
        assign(out, resultPtr);
        func_00312318(resultPtr, 2);
        release(textPtr);
    } else {
        const char *defaultLiteral = D_00690D18;
        Str *textPtr = &defaultText;
        {
            Rep *emptyRep = &D_00659FA8;
            char *chars;
            if (emptyRep->sel != 0) {
                chars = func_005C2560(emptyRep);
            } else {
                chars = (char *)(emptyRep + 1);
                emptyRep->ref++;
            }
            textPtr->p = chars;
        }
        func_005C2630(textPtr, 0, -1, defaultLiteral, func_0057F260(defaultLiteral));
        Handle *resultPtr = &result;
        func_00314B20(resultPtr, textPtr);
        assign(out, resultPtr);
        func_00312318(resultPtr, 2);
        release(textPtr);
    }
    func_001740F0(&file, 2);
}

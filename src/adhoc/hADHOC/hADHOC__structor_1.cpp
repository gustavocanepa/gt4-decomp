#include "gt4/hADHOC.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *hADHOC__vtable;
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_005EB300(void *, void *);
extern "C" void *func_005EC198(void);
extern "C" void func_005EB3D0(void *);
extern "C" void *func_005EC1E8(void);
extern "C" void func_005EB520(void *);
extern "C" void *func_005EC158(void);
extern "C" void func_005EB460(void *, void *);
extern "C" void *func_005EC228(void);
extern "C" void RefCounter__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005EB300(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
    void *p0 = *(void **)(m + 0x4);
    void *r5 = func_005EC198();
    func_00326798(p0, 0x18, 0x4, *(void **)(r5));
}
static inline void member_1(char *m) {
    func_005EB3D0(m);
    void *p1 = *(void **)(m + 0x4);
    void *r8 = func_005EC1E8();
    func_00326798(p1, 0xc, 0x4, *(void **)(r8));
}
static inline void member_2(char *m) {
    func_005EB520(m);
    void *p2 = *(void **)(m + 0x4);
    void *r11 = func_005EC158();
    func_00326798(p2, 0xc, 0x4, *(void **)(r11));
}
static inline void member_3(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005EB460(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
    void *p3 = *(void **)(m + 0x4);
    void *r14 = func_005EC228();
    func_00326798(p3, 0x18, 0x4, *(void **)(r14));
}

extern "C" void hADHOC__structor_1(void *arg0, s32 arg1) {
    ((struct hADHOC *)arg0)->unk4 = &hADHOC__vtable;
    func_002ED5C0((char *)arg0 + 0x74, 0x2);
    func_00574DA8((char *)arg0 + 0x44, 0x2);
    str_release((Str *)((char *)arg0 + 0x40));
    func_003041B8((char *)arg0 + 0x3c, 0x2);
    func_003041B8((char *)arg0 + 0x38, 0x2);
    member_0((char *)arg0 + 0x28);
    member_1((char *)arg0 + 0x20);
    member_2((char *)arg0 + 0x18);
    member_3((char *)arg0 + 0x8);
    RefCounter__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x78, 0x4, "RefCounter");
    }
}

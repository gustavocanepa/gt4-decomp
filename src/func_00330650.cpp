typedef int s32;
typedef unsigned char u8;

struct Sub {
    char pad0[0x160];
    u8 c1;
    u8 c2;
    char pad162[3];
    char dirty;
};

struct Car {
    char pad0[0x20];
    Sub sub;
};

struct List {
    s32 count;
    char pad4[4];
    Car **items;
};

struct Mgr {
    char pad0[0x60];
    List *list;
    char pad64[0xC];
    s32 id;
};

struct Self {
    char pad0[0x6C];
    Mgr *mgr;
};

struct Buf {
    s32 w[8];
};

extern "C" s32 func_004454C0(Sub *arg0);
extern "C" s32 func_004462E0(Sub *arg0);
extern "C" s32 func_00446320(Sub *arg0);
extern "C" void func_004468F8(Sub *arg0, s32 arg1);
extern "C" s32 func_00447550(s32 arg0);
extern "C" void func_00449D58(Buf *arg0);
extern "C" void func_00449D78(Buf *arg0, int arg1);
extern "C" s32 func_00449E10(Buf *arg0, s32 arg1);
extern "C" s32 func_0044A048(Buf *arg0, s32 arg1, s32 arg2);

extern "C" void func_00330650(Self *self) {
    Mgr *mgr = self->mgr;
    s32 mode = -1;
    s32 count;
    s32 i;
    Buf buf;

    switch (func_00447550(mgr->id)) {
    case 2:
        mode = 11;
        break;
    case 3:
        mode = 12;
        break;
    }
    count = mgr->list->count;
    func_00449D58(&buf);
    for (i = 0; i < count; i++) {
        Sub *sub = &mgr->list->items[i]->sub;
        s32 c1;
        s32 c2;
        s32 t1;
        s32 t2;
        if (sub->dirty) {
            c1 = sub->c1;
            c2 = sub->c2;
        } else {
            c1 = func_004462E0(sub);
            c2 = func_00446320(sub);
        }
        if (mode == -1) {
            t1 = c1;
            t2 = c2;
        } else {
            t1 = t2 = mode;
        }
        if (c1 != t1 || c2 != t2 || sub->dirty) {
            sub->dirty = 0;
            if (func_00449E10(&buf, func_004454C0(sub)) != 0) {
                s32 r = func_0044A048(&buf, 0x19, t1);
                if (r != -1) {
                    func_004468F8(sub, r);
                }
                r = func_0044A048(&buf, 0x1A, t2);
                if (r != -1) {
                    func_004468F8(sub, r);
                }
            }
        }
    }
    func_00449D78(&buf, 2);
}

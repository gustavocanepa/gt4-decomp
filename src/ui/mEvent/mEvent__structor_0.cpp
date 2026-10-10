/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RefCounter;

extern "C" void func_00328660(RefCounter *p); /* retain */
extern "C" void func_003286B8(RefCounter *p); /* release */

struct Ref {
    RefCounter *p;
    Ref() : p(0) {}
    Ref &operator=(RefCounter *q) {
        if (q)
            func_00328660(q);
        if (p)
            func_003286B8(p);
        p = q;
        return *this;
    }
};

/* g++ 2.96 puts the vptr after the fields of the class that introduces it: 4 here. */
struct hObjectBase {
    int unk0;
    virtual ~hObjectBase();
};

/* hObject, named after its constructor (0x0030A678) so the call resolves. */
struct hObject__structor_0 : hObjectBase {
    int unk8;
    int unkC;
    hObject__structor_0();
    virtual ~hObject__structor_0();
};

struct mEvent : hObject__structor_0 {
    int unk10;
    int unk14;
    int type;
    Ref target;
    mEvent(int type, RefCounter *target);
    virtual ~mEvent();
};

mEvent::mEvent(int t, RefCounter *tgt) : unk10(0), unk14(0), type(t) {
    target = tgt;
}

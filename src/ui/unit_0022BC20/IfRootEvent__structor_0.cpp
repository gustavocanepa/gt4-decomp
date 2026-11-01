/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char IfRootEvent__vtable[], MEventFilter__vtable[], mLeaveEvent__vtable[], D_006984C0[];
struct Iter {
    void **current;
    Iter() {}
    Iter(void **p) : current(p) {}
    Iter(const Iter &other) : current(other.current) {}
    void *operator*() const { void **p = current; return *--p; }
    Iter operator++(int) { Iter old = *this; --current; return old; }
    void **base() const { return current; }
};
static inline bool operator!=(const Iter &a, const Iter &b) { return a.base() != b.base(); }
struct Vec {
    int pad;
    void **begin, **end, **storage;
    Iter rbegin() const { return Iter(end); }
    Iter rend() const { return Iter(begin); }
};
struct MEventFilter {
    virtual ~MEventFilter() {}
    virtual void key(); /* declared only: the vtable stays the original's */
};
struct IfRootEvent : MEventFilter {
    void *widget;
    int type, handled;
    IfRootEvent(void *w, int t) : widget(w), type(t), handled(0) {}
    virtual ~IfRootEvent() {}
    virtual void key(); /* declared only: the vtable stays the original's */
};
struct Handle { char *p; Handle() {} Handle(char *q) : p(q) {} };
struct VE { short delta, index; int (*fn)(void *); };
extern "C" void *func_0022F000(void *) throw();
extern "C" void *func_0022F2A0(void *) throw();
extern "C" void func_00231980(void *, void *);
extern "C" void *mWidget__getRootWindow(void *);
extern "C" void func_0028B180(void *, void *);
extern "C" int mEnterEvent__GetClassID();
extern "C" void *mEvent__structor_0(void *, void *, void *);
extern "C" int mFocusEnterEvent__GetClassID();
extern "C" int mFocusLeaveEvent__GetClassID();
extern "C" void func_00294F88(void *, int);
extern "C" void func_00295260(void *, void *, void *);
extern "C" int mLeaveEvent__GetClassID();
extern "C" void func_002ADEE0(void *, int);
extern "C" void *func_00326750(int, int, const char *);
static inline void dispatch(Handle *h) {
    char *p = h->p;
    VE *e = (VE *)(*(char **)(p + 4) + 0x190);
    e->fn(p + e->delta);
}
struct Focus : Handle {
    Focus(void *self, void *target) __asm__("func_00295260");
    Focus(const Focus &v) { p = v.p; }
    ~Focus() { func_00294F88(this, 2); }
    void send() { dispatch(this); }
};
struct Leave : Handle {
    Leave(void *self, void *target) {
        char *event = (char *)func_00326750(32, 4, D_006984C0);
        mEvent__structor_0(event, self, target);
        *(char **)(event + 4) = mLeaveEvent__vtable;
        Handle own = Handle(event);
        func_0028B180(this, &own);
    }
    Leave(const Leave &v) { p = v.p; }
    ~Leave() { func_002ADEE0(this, 2); }
    void send() { dispatch(this); }
};
extern "C" void IfRootEvent__structor_0(void *self, Vec *v) {
    Iter it;
    for (it = v->rbegin(); it != v->rend(); it++) {
        void *widget = *it;
        if (widget) {
            IfRootEvent e1(widget, mFocusEnterEvent__GetClassID());
            IfRootEvent *p1 = &e1;
            func_00231980(self, p1);
            IfRootEvent e2(widget, mFocusLeaveEvent__GetClassID());
            IfRootEvent *p2 = &e2;
            func_00231980(self, p2);
            if (!p2->handled && func_0022F000(self) && widget == mWidget__getRootWindow(func_0022F000(self)))
                Focus(self, func_0022F000(self)).send();
            IfRootEvent e3(widget, mEnterEvent__GetClassID());
            IfRootEvent *p3 = &e3;
            func_00231980(self, p3);
            IfRootEvent e4(widget, mLeaveEvent__GetClassID());
            IfRootEvent *p4 = &e4;
            func_00231980(self, p4);
            if (!p4->handled && func_0022F2A0(self) && widget == mWidget__getRootWindow(func_0022F2A0(self)))
                Leave(self, func_0022F2A0(self)).send();
        }
    }
}

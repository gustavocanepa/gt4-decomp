typedef int s32;

extern char mDomNodeList__vtable[];

/* hObject; its constructor is func_0030A678 (named after it so __13func_0030A678 resolves). */
struct func_0030A678 {
    s32 m0;
    char *vtbl;
    s32 m8, mC;
    func_0030A678();
};

/* A standard-style allocator object: the default argument `Alloc()` of the vector constructor is
   a stack temporary passed by reference, which leaves an unused 16-byte slot in the frame. */
struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct NodeVector {
    Alloc a;
    s32 *start, *finish, *eos;
    NodeVector(const Alloc &al = Alloc()) : a(al), start(0), finish(0), eos(0) {}
};

struct mDomNodeList : func_0030A678 {
    NodeVector nodes;
    mDomNodeList();
};

mDomNodeList::mDomNodeList() {
    vtbl = mDomNodeList__vtable;
}

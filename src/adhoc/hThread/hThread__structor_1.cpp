/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *HObject__tf(void);
extern char D_0069E280[];

struct TypeInfo {
    const char *name;
};

template <class T> struct TypeTag;

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


/* hThread::~hThread (deleting destructor): leaves and deletes every frame
 * still on the frame stack, then destroys the value stack, the handle and the
 * frame vector. */

typedef int s32;

struct RefCounter;
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" TypeInfo *HObject__tf(void);
extern "C" TypeInfo *func_005F0970(void);
extern "C" void hObject__structor_2(void *self, int inCharge);
extern char D_0069E298[];
extern char hThread__vtable[];

struct HObject {
    RefCounter *p;
    HObject() __asm__("func_0030BB18");
    HObject(const HObject &);
    ~HObject() __asm__("func_00309378");
};
template <> struct TypeTag<HObject> { static void *tf() { return HObject__tf(); } };

struct HStack {
    vector<HObject, GameAlloc<HObject> > a;
    vector<HObject, GameAlloc<HObject> > b;
    int n;
    static void operator delete(void *p, size_t size) { func_00326798(p, size, 4, D_0069E280); }
};

struct hThread;
struct HFrame {
    virtual ~HFrame();
    virtual void enter(hThread *thread);
    virtual void leave(hThread *thread);
};
template <> struct TypeTag<HFrame *> { static void *tf() { return func_005F0970(); } };

struct hThread {
    int f0;
    void *vt;
    int f8, fC;
    vector<HFrame *, GameAlloc<HFrame *> > frames;
    int code;
    RefCounter *ref;
    void *data;
    HStack *stack;
    HObject handle;
    char pad34[0x18];
};

extern "C" void hThread__structor_1(hThread *self, int inCharge) {
    self->vt = hThread__vtable;
    while (self->frames.size() != 0) {
        HFrame *f = self->frames.back();
        f->leave(self);
        delete f;
        self->frames.pop_back();
    }
    delete self->stack;
    self->handle.~HObject();
    self->frames.~vector();
    hObject__structor_2(self, 0);
    if (inCharge & 1) func_00326798(self, sizeof(hThread), 4, D_0069E298);
}

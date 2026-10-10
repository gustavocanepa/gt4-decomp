/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

/* The root object: 0x4C bytes of data, then its vptr (constructor func_001CBFE0, so
   __14func_001CBFE0 resolves). */
struct func_001CBFE0 {
    char data[0x4C];
    func_001CBFE0();
    virtual void update();
};

/* A vector-like member: its first word is left alone, the three pointers are cleared. */
template <class T>
class func_001D3800_Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef func_001D3800_Alloc<U> other; };
    func_001D3800_Alloc() throw() {}
    func_001D3800_Alloc(const func_001D3800_Alloc &) throw() {}
    ~func_001D3800_Alloc() throw() {}
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type);
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
};

/* The common base of the five kinds, named after its vtable (0x006611F0). */
struct D_006611F0 : func_001CBFE0 {
    vector<void *, func_001D3800_Alloc<void *> > list;
    virtual void update();
};

/* The kinds, each named after its vtable. */
struct D_00660FC0 : D_006611F0 {
    int x60;
    char pad[0x150 - 0x64];
    D_00660FC0() : x60(0) {}
    virtual void update();
};
struct D_00660EA8 : D_006611F0 {
    int x60;
    char pad[0x150 - 0x64];
    D_00660EA8() : x60(0) {}
    virtual void update();
};
struct D_00661EC0 : D_006611F0 {
    int x60;
    char pad[0x150 - 0x64];
    D_00661EC0() : x60(0) {}
    virtual void update();
};
struct D_00661860 : D_006611F0 {
    int x60;
    char pad[0x150 - 0x64];
    D_00661860() : x60(0) {}
    virtual void update();
};
struct D_00661758 : D_006611F0 {
    int x60;
    char pad[0x150 - 0x64];
    vector<void *, func_001D3800_Alloc<void *> > list2;
    D_00661758() : x60(0) {}
    virtual void update();
};

extern "C" func_001CBFE0 *func_001D3800(int kind) {
    switch (kind) {
    case 'R':
        return new D_00660FC0;
    case 'B':
        return new D_00660EA8;
    case 'D':
        return new D_00661EC0;
    case 'F':
        return new D_00661860;
    case 'P':
        return new D_00661758;
    }
    return 0;
}

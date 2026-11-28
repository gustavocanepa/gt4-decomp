/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<T_005DBC00, GameAlloc> copy_ctor */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
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

typedef unsigned int u32;
struct Rep {
 u32 len, cap, ref, sel;
 char *data() { return (char *)(this+1); }
 char *grab();
 void release();
};
struct Str;
extern Rep D_00659FA8;
extern char D_0069DEC0[], D_0069DEC8[], D_0069DED0[], D_0069DED8[];
extern "C" char *func_005C2560(Rep *);
extern "C" TypeInfo *func_005C11A8();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" Str *func_005CE388(Str *,u32,u32,const Str *,u32,u32);
extern "C" int func_005CD320(const Str *,const char *,u32,u32);
inline char *Rep::grab() { if(sel) return func_005C2560(this); ++ref; return data(); }
inline void Rep::release() { if(--ref==0) { int size=cap+16; func_00326798(this,size,4,func_005C11A8()->name); } }
struct Str {
 char *p;
 Rep *rep() const { return (Rep *)p-1; }
 u32 size() const { return rep()->len; }
 Str() { p=D_00659FA8.grab(); }
 Str(const char *s,u32 n) { p=D_00659FA8.grab(); func_005C2630(this,0,-1,s,n); }
 Str(const Str &s) { p=s.rep()->grab(); }
 ~Str() { rep()->release(); }
 int compare(const char *s) const { return func_005CD320(this,s,0,func_0057F260(s)); }
 Str &append(const char *s,u32 n) { return *func_005C2630(this,size(),0,s,n); }
 Str &append(const char *s) { return append(s,func_0057F260(s)); }
 Str &append(const Str &s) { return *func_005CE388(this,size(),0,&s,0,-1); }
 const char *c_str() const { if(size()==0) return D_0069DED8; rep()->data()[size()]=0; return rep()->data(); }
};
extern "C" int HIO__operator_shr(int,int *);
extern "C" void *func_002FFA40(void *,void *);
extern "C" int HSymID__GetID(const Str *);
struct Sym {
 int id;
 Sym():id(0){}
 Sym(const Sym &s):id(s.id){}
 Sym(const Str &s):id(HSymID__GetID(&s)){}
 ~Sym(){}
 Sym &operator=(const Sym &s) { if(this!=&s) id=s.id; return *this; }
};
extern "C" void *HSymID__tf(void);
template <> struct TypeTag<Sym> { static void *tf() { return HSymID__tf(); } };
typedef vector<Sym,GameAlloc<Sym> > Vec;
extern "C" void func_005EDE90(Vec *,Sym *,unsigned,const Sym *);
template<> inline void Vec::insert(Vec::iterator p,Vec::size_type n,const Sym &v) {func_005EDE90(this,p,n,&v);}

/* Reads a compiled code object: its name, the symbol table, two counters and
 * the instruction list (each instruction is created from its opcode byte and
 * then reads itself). */
struct InstHeader {
 int line;
 unsigned char op;
};
struct Inst;
struct VEntry { short delta, index; void (*read)(void *, int io); };
struct Inst { int refCount; VEntry *vtbl; };
struct InstRef;
extern "C" void func_002FB218(InstRef *,unsigned char op);
struct InstRef {
 Inst *p;
 InstRef(const InstRef &);
 InstRef(unsigned char op) { func_002FB218(this,op); }
 ~InstRef() __asm__("func_002FB1C0");
 Inst *get() const { return p; }
 void read(int io) { VEntry *e=&p->vtbl[10]; e->read((char *)p+e->delta,io); }
};
extern "C" void *func_005EE2B0(void);
template <> struct TypeTag<Inst *> { static void *tf() { return func_005EE2B0(); } };
typedef vector<Inst *,GameAlloc<Inst *> > Insts;
struct Code {
 char pad[0x10];
 Vec symbols;
 int pad20;
 int m24;
 int m28;
 Insts insts;
};
extern "C" void HIO__read(int io,void *buf,int size);
extern "C" void func_002F4988(Code *);
extern "C" int func_002F4900(Code *,Inst *);
extern "C" void func_002F4A10(Code *self,int io) {
 Str s;
 func_002FFA40((void *)io,&s);
 int n;
 HIO__operator_shr(io,&n);
 self->symbols.resize(n);
 for(int i=0;i<n;i++) {
  func_002FFA40((void *)io,&s);
  self->symbols[i]=Sym(s);
 }
 HIO__operator_shr(io,&self->m24);
 HIO__operator_shr(io,&self->m28);
 HIO__operator_shr(io,&n);
 func_002F4988(self);
 self->insts.reserve(n);
 /* Never set. The exit test after add() leaves no code (gcse folds it), but it
  * ends the basic block before inst's destructor, which is why the destructor
  * gets the frame address register and not the loop's copy of it. */
 bool failed=false;
 for(int i=0;i<n;i++) {
  InstHeader h;
  HIO__read(io,&h,5);
  InstRef inst(h.op);
  inst.read(io);
  func_002F4900(self,inst.get());
  if(failed) break;
 }
}

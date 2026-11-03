/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
/* Writes to an open file under the owner's lock (map lookup as func_004CCEA8, -9 if unknown, -22 if
   pos + len wraps), then grows the payload's unaligned size to the new position and marks the
   file active; the size goes through a reference to a packed word (retail's addiu + lwr 0). */
struct Block { int a,b,c,d; };
struct __attribute__((packed)) U32 { unsigned v; };
struct __attribute__((packed)) Header { char pad[28]; U32 size; };
struct Data { int active; void *buf; Header *payload; int file; unsigned pos; Block block; };
struct Value { const unsigned first; Data *second; };
struct NodeBase { int color; NodeBase *parent,*left,*right; };
struct Node : NodeBase { Value value; };
struct IteratorBase { NodeBase *node; };
template <class Ref,class Ptr> struct Iter : IteratorBase {
 typedef Iter<Value&,Value*> iterator;
 Iter() {}
 Iter(Node *p) { node=p; }
 Iter(const iterator &it) { node=it.node; }
 Ref operator*() const { return ((Node*)node)->value; }
 Ptr operator->() const { return &(operator*()); }
};
inline bool operator==(const IteratorBase &a,const IteratorBase &b) { return a.node==b.node; }
struct Tree;
extern "C" Iter<Value&,Value*> func_0060C3A0(Tree*,const unsigned&);
struct Tree {
 int allocator; Node *header; unsigned count; int compare;
 typedef Iter<Value&,Value*> iterator;
 iterator find(const unsigned &key) { return func_0060C3A0(this,key); }
 iterator end() { return header; }
};
struct Map {
 Tree t;
 typedef Iter<Value&,Value*> iterator;
 typedef Iter<const Value&,const Value*> const_iterator;
 iterator find(const unsigned &key) { return t.find(key); }
 iterator end() { return t.end(); }
};
extern "C" int func_004CC380(void*,Data*,void*,unsigned,int);
extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
struct Guard {
 void *p;
 Guard(void *v):p(v) {func_00576788(p);}
 ~Guard() {func_005767C0(p);}
};
struct Owner { void *vtable; void *list; Map map; int unused; char mutex[48]; };
extern "C" int func_004CCFC0(Owner *s,int key,void *buf,unsigned len) {
 Guard guard(s->mutex);
 Map::const_iterator it=s->map.find(key);
 if(it==s->map.end()) return -9;
 Data *data=it->second;
 if(data->pos+len<data->pos) return -22;
 int r=func_004CC380(s,data,buf,len,0);
 U32 &size=data->payload->size;
 if(size.v<data->pos) size.v=data->pos;
 data->active=1;
 return r;
}

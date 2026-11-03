/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
/* Reads from an open file under the owner's lock: looks the handle up in the map (-9 if unknown),
   clamps len to what is left of the payload after the current position and hands the read to
   func_004CC380; the same map/guard shapes as the seek func_004CD0F0. */
struct Block { int a,b,c,d; };
struct __attribute__((packed)) Header { char pad[28]; unsigned size; };
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
extern "C" int func_004CCEA8(Owner *s,int key,void *buf,unsigned len) {
 Guard guard(s->mutex);
 Map::const_iterator it=s->map.find(key);
 if(it==s->map.end()) return -9;
 Data *data=it->second;
 unsigned size=data->payload->size;
 if(size<data->pos+len) len=size-data->pos;
 if(len==0) return 0;
 return func_004CC380(s,data,buf,len,1);
}

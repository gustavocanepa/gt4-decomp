/* Sets item sub of entry index to value (only 0-3) and sends a 12-byte
   message 9 with index, sub and value through func_00527510; returns 2 for a
   bad index/sub/value, 3 without entries. Sibling of func_00524CC0. */
struct Item { char pad[0x40]; unsigned int value; };
struct Entry { Item **items; char pad[0x14]; };
struct Obj { char p[0x88]; Entry *entries; char q[0x10]; unsigned short subs; char r[0x1E]; unsigned int count; };
struct Message { unsigned short code; unsigned char index; unsigned char pad; unsigned short sub; unsigned short pad2; unsigned int value; };
struct Part { void *ptr; int len; };
struct Request {
 Part parts[8]; int size, count;

 void add(void * const p,const int n) { parts[count].ptr=p; parts[count].len=n; size+=n; ++count; }
};
extern "C" int func_00525648(int,int);
extern "C" int func_00527510(Obj*,int,int,int,Request*);
inline int send(Obj *o,Request *r) { return func_00527510(o,0,0,0xf000,r); }
extern "C" int func_00525190(Obj *o, unsigned char index, unsigned short sub, unsigned int value) {
 Message msg;
 Request req;
 int ret=0;
 if (!o) return 2;
 if (index>=o->count) return 2;
 if (!o->entries) return 3;
 if (sub>=o->subs) return 2;
 if (value<4) {
  o->entries[index].items[sub]->value=value;
  msg.code=func_00525648(9,12);
  msg.index=index;
  msg.sub=sub;
  msg.value=value;
  req.count=0; req.size=0;
  req.add(&msg,12);
  int r=send(o,&req);
  if (r) return r;
 } else ret=2;
 return ret;
}

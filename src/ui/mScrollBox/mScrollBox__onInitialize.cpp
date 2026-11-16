/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Hold { void *p; char pad[12]; };
struct Heap { const char *name; };
struct Entry { short delta,index; void *fn; };
struct Obj { int word; Entry *vt; };
struct Self { char pad[0xB0]; void *scroll,*pinch,*inc,*dec; };
extern Rep D_00659FA8;
extern char D_0069C9F0[],D_0069C9F8[],D_0069CA08[];
extern "C" void mScrollable__tf();
extern "C" void mWidget__tf();
extern "C" void mTextFace__virtual_67(void*);
extern "C" s32 mScrollable__GetClassID();
extern "C" Obj *func_00206868(void*);
extern "C" Obj *func_0025C300(void*);
extern "C" s32 hObject__isInstanceOf(void*,s32);
extern "C" void *__dynamic_cast_2(void*,void*,int,void*,void*,void*);
extern "C" int func_0030BB18(void*);
extern "C" char *func_005C2560(Rep*);
extern "C" u32 func_0057F260(const char*) throw();
extern "C" Str *func_005C2630(Str*,u32,u32,const char*,u32);
extern "C" s32 HSymID__GetID(Str*);
extern "C" void func_003069F8(void*,void*,void*);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void*,u32,u32,const char*);
extern "C" int func_00255110(void*,void*);
extern "C" void func_002550B8(void*,int);
extern "C" void func_00309378(void*,int);
static inline char *grab(Rep *r) {
 if(r->sel) return func_005C2560(r);
 ++r->ref;
 return (char*)(r+1);
}
static inline void construct(Str *s,const char *text) {
 s->p=grab(&D_00659FA8);
 func_005C2630(s,0,-1,text,func_0057F260(text));
}
static inline void release(Str *s) {
 Rep *r=(Rep*)(s->p-16);
 if(--r->ref==0) { u32 size=r->cap+16;func_00326798(r,size,4,func_005C11A8()->name); }
}
extern "C" void mScrollBox__onInitialize(Self *self) {
 Hold h,buf; Str s1,s2,s3;
 mTextFace__virtual_67(self);self->scroll=0;self->pinch=0;
 s32 cls=mScrollable__GetClassID();
 for(Obj *p=func_00206868(self);p;p=func_0025C300(p)) {
  if(hObject__isInstanceOf(p,cls)) {
   Entry *e=p->vt;
   self->scroll=__dynamic_cast_2(e->fn,(void*)mScrollable__tf,0,(char*)p+e->delta,(void*)mWidget__tf,p);
   break;
  }
 }
 func_0030BB18(&h);
 Hold *pb=&buf;
 Str *ps=&s1;
 construct(ps,D_0069C9F0); *(s32*)pb=HSymID__GetID(ps);func_003069F8(self,&h,pb);release(ps);
 if(__builtin_expect((int)h.p,0)) {func_00255110(pb,&h);self->pinch=pb->p;func_002550B8(pb,2);}
 ps=&s2;
 construct(ps,D_0069C9F8); *(s32*)pb=HSymID__GetID(ps);func_003069F8(self,&h,pb);release(ps);
 if(__builtin_expect((int)h.p,0)) {func_00255110(pb,&h);self->inc=pb->p;func_002550B8(pb,2);}
 ps=&s3;
 construct(ps,D_0069CA08); *(s32*)pb=HSymID__GetID(ps);func_003069F8(self,&h,pb);release(ps);
 if(__builtin_expect((int)h.p,0)) {func_00255110(pb,&h);self->dec=pb->p;func_002550B8(pb,2);}
 func_00309378(&h,2);
}

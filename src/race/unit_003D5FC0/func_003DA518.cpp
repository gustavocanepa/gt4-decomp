/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" Found *func_00480878(int,Str *);
extern "C" void free(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" int __dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" void func_00480638(int,int);
extern "C" void func_0047FCF8(int,void *);
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_003DA518(void *owner,int handle,const char *name,int index) {
    Str s;
    Str *ps=&s;
    Rep *r=&D_00659E20;
    char *d=(char *)(r+1);
    if(r->selfish) d=strobe__toUpper(r);
    else ++r->ref;
    ps->p=d;
    strobe__Any__setMember(ps,0,-1,name,func_0057F260(name));
    int result=0;
    Found *f=func_00480878(handle,&s);
    if(f) { Entry *e=f->entry; result=__dynamic_cast_2(e->fn,func_00608F30,0,(char *)f+e->delta,func_00607408,f); }
    destroy(&s);
    if(result) {
        func_00480638(result,index);
        func_0047FCF8(result,owner);
        func_0047FCF8(result,owner);
    }
}

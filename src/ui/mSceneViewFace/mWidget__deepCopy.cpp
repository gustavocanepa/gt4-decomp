/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { unsigned len,cap,ref,sel; };
struct Str { char *p; };
struct Info { const char *name; };
struct Entry { short delta,index; void *fn; };
struct V4 { float x,y,z,w; };
struct V2 { float x,y; };
struct Raw16 { int a,b,c,d; };
struct Ext { V4 a,b; unsigned x:1,y:1; };
struct Bits { unsigned a:4,b:4,c:4,d:1,e:1,f:1,g:1,h:1,i:1,j:1,k:1,l:1,m:1,n:1,o:2,p:1,q:1,r:4,s:1; };
struct Bits2 { unsigned a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1; };
struct Obj { int unk; Entry *vt; char pad[0x24]; void *handle; int pad30; V4 v; Raw16 raw; int z54,z58,z5c; char p60[12]; V2 v6c; float f74; V2 v78,v80; float f88; Str str; Ext *ext; int p94; Bits bits; Bits2 bits2; };
extern "C" void hObject__deepCopy(void *,void *);
extern "C" Obj *__dynamic_cast_2(void *,void *,int,void *,void *,void *);
extern "C" const char *hModule__getName(Obj *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" int func_003284E8(void *);
extern "C" void func_00328660(void *);
extern "C" void func_003286B8(void *);
extern "C" Ext *func_00254FD0() throw();
extern char mWidget__tf[],hObject__tf[];
extern Rep D_00659FA8;
static inline char *retain(Rep *r) { if(r->sel) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
static inline void release(Str *s) { Rep *r=(Rep *)(s->p-16); if(--r->ref == 0) { int n=r->cap+16; func_00326798(r,n,4,func_005C11A8()->name); } }
static inline void assign(Str *d,const Str *s) { if(s!=d) { release(d); d->p=retain((Rep *)(s->p-16)); } }
static inline void vec(V4 *d,const V4 *s) { if(d!=s) { d->x=s->x; d->y=s->y; d->z=s->z; d->w=s->w; } }
static inline void vec2(V2 *d,float x,float y) { d->x=x; d->y=y; }
static inline void construct(Str *d,const char *name) { d->p=retain(&D_00659FA8); func_005C2630(d,0,-1,name,func_0057F260(name)); }
static inline void handle(void **d,void **s) { int empty=0; if(!*s || !func_003284E8(*s)) empty=1; void *p=0; if(!empty) p=*s; if(p) func_00328660(p); if(*d) func_003286B8(*d); *d=p; }
extern "C" void mWidget__deepCopy(Obj *self,Obj *src) {
    Obj *copy=0;
    hObject__deepCopy(self,src);
    if(src) { Entry *e=src->vt; copy=__dynamic_cast_2(e->fn,mWidget__tf,0,(char *)src+e->delta,hObject__tf,src); }
    if(copy) {
        Str tmp;
        construct(&tmp,hModule__getName(copy));
        Entry *e=self->vt+50;
        ((void (*)(void *,Str *))e->fn)((char *)self+e->delta,&tmp);
        release(&tmp);
        handle(&self->handle,&copy->handle);
        vec(&self->v,&copy->v);
        self->raw=copy->raw;
        self->z54=0; self->z58=0; self->z5c=0;
        { V2 *d=&self->v6c; d->x=copy->v6c.x; d->y=copy->v6c.y; } self->f74=copy->f74;
        { V2 *d=&self->v78; d->x=copy->v78.x; d->y=copy->v78.y; } { V2 *d=&self->v80; d->x=copy->v80.x; d->y=copy->v80.y; } self->f88=copy->f88;
        if(copy->ext) { if(!self->ext) self->ext=func_00254FD0(); Ext *d=self->ext,*s=copy->ext; vec(&d->a,&s->a); vec(&d->b,&s->b); d->x=s->x; d->y=s->y; }
        assign(&self->str,&copy->str);
#define B(x) self->bits.x=copy->bits.x
        B(a); B(b); B(c); B(d); B(e); B(f); B(g); B(h); B(i); B(j); self->bits.l=0; B(m); B(n); B(o); B(p); B(q); B(r); B(s);
#undef B
#define B(x) self->bits2.x=copy->bits2.x
        B(a); B(b); B(c); B(d); B(e); B(f); B(g); B(h);
#undef B
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Handle {
    s32 p;
};

struct Rep { unsigned len,cap,ref,sel; };
struct Str { char *p; };
struct Entry { short delta,index; void *fn; };
struct Base { int x; Entry *vtable; };
struct Info { const char *name; };
struct Obj {
    char pad0[0xF0];
    Str str[8];
    Handle h[8];
    float x,y;
};

extern "C" void mImageFace__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *,void *,int,void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" char *func_005C2560(Rep *);
extern char mFrameImageFace__tf[],hObject__tf[];
static inline void str_assign(Str *d, const Str *s) {
    if(s != d) {
        Rep *r=(Rep *)(d->p-16);
        if(--r->ref == 0) {
            int n=r->cap+16;
            func_00326798(r,n,4,func_005C11A8()->name);
        }
        Rep *r2=(Rep *)(s->p-16);
        char *p;
        if(r2->sel) p=func_005C2560(r2);
        else { ++r2->ref; p=(char *)(r2+1); }
        d->p=p;
    }
}
extern "C" void func_002106E0(Handle *, s32 *);
extern "C" void func_00210710(Handle *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline void assign(Handle *dst, Handle *src) {
    if (dst != src) {
        s32 v = src->p;
        if (v != 0) {
            func_003285A8(v);
        }
        if (dst->p != 0) {
            func_003285F8(dst->p);
        }
        dst->p = v;
    }
}

#define SET(i, z)                       \
    {                                   \
        Handle *d = &self->h[i];        \
        z = 0;                          \
        func_002106E0(&tmp[0], &z);        \
        assign(d, &tmp[0]);                \
        func_00210710(&tmp[0], 2);         \
    }

extern "C" void mFrameImageFace__deepCopy(Obj *self, void *src) {
    Handle tmp[4];
    s32 z0, z1, z2, z3, z4, z5, z6, z7;

    SET(0, z0)
    SET(1, z1)
    SET(2, z2)
    SET(3, z3)
    SET(4, z4)
    SET(5, z5)
    SET(6, z6)
    SET(7, z7)
    Obj *copy=0;
    mImageFace__deepCopy(self,src);
    if(src) {
        Entry *e=((Base *)src)->vtable;
        copy=(Obj *)__dynamic_cast_2(e->fn,mFrameImageFace__tf,0,(char *)src+e->delta,hObject__tf,src);
    }
    if(copy) {
        str_assign(&self->str[0],&copy->str[0]);
        str_assign(&self->str[1],&copy->str[1]);
        str_assign(&self->str[2],&copy->str[2]);
        str_assign(&self->str[3],&copy->str[3]);
        str_assign(&self->str[4],&copy->str[4]);
        str_assign(&self->str[5],&copy->str[5]);
        str_assign(&self->str[6],&copy->str[6]);
        str_assign(&self->str[7],&copy->str[7]);
        self->x=copy->x;
        self->y=copy->y;
    }
}

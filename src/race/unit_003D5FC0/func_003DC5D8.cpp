/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Car { char pad0[0x14]; int id; char pad18[0x3444-0x18]; int pos; };
struct List { int count; int pad4; Car **cars; };
struct Group { char pad0[0x60]; List *list; };
struct Owner { int pad0; int *handle; char pad8[0x20]; int mode; char pad2c[0x38]; int id; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern char D_006A3500[], D_006A3350[];
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" int func_003D8BE8(Owner *,Car *) throw();
extern "C" void func_003DA518(int *,int,const char *,int) throw();
extern "C" Found *func_00480878(int,Str *);
extern "C" void free(void *) throw();
extern "C" int func_0057DA20(char *,const char *,...);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" int __dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_003DC5D8(Owner *self,Group *group) {
    if(self->handle && self->mode==1) {
        int i=0;
        int h=*self->handle;
        if(group->list->count>0) {
            do {
                Car *car=group->list->cars[i];
                if(func_003D8BE8(self,car)) {
                    int pos=car->pos;
                    char buf[16];
                    Str s;
                    func_0057DA20(buf,D_006A3500,pos+0x41);
                    construct(&s,buf);
                    int result=0;
                    Found *found=func_00480878(h,&s);
                    if(found) {
                        Entry *e=found->entry;
                        result=__dynamic_cast_2(e->fn,func_00608F30,0,(char *)found+e->delta,func_00607408,found);
                    }
                    destroy(&s);
                    if(result) {
                        int index=pos*2;
                        int alt=index+1;
                        if ((car->id ^ self->id)==0) index=alt;
                        func_003DA518(self->handle,result,D_006A3350,index);
                    }
                }
                ++i;
            } while(i<group->list->count);
        }
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Car { char pad0[0x14]; int id; char pad18[0x3444-0x18]; int pos; };
struct List { int count; int pad4; Car **cars; };
struct Group { char pad0[0x60]; List *list; };
struct Owner { int pad0; int *handle; char pad8[0x54]; int p5c; char pad60[0x10]; int x70; int x74; char pad78[0x18]; int flags; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" Found *func_00480878(int,Str *);
extern "C" void free(void *) throw();
extern "C" int func_0057DA20(char *,const char *,...) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" char *__dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
struct Val { int type; int spare[3]; };
extern char D_006A34E0[],D_006A34E8[],D_006A34F0[];
extern "C" int RaceMonitor__is_player_car(Owner *) throw();
extern "C" void RaceMonitor__update_pit_panel(Owner *,int) throw();
extern "C" void func_004768C0(Val *);
extern "C" void func_00476AE8(Val *,const char *);
extern "C" int func_004809D8(int,Str *,Val *);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_003DBBD0(Owner *self) {
    char buf[64];
    Val value;
    Str s;
    int handle=*self->handle;
    Val *pv=&value;
    pv->type=1;
    buf[0]=0;
    if(self->p5c==0 || (((self->flags>>4)^1)&1)) func_0057DA20(buf,D_006A34E0,self->x74);
    func_00476AE8(pv,buf);
    Str *ps=&s;
    construct(ps,D_006A34E8);
    func_004809D8(handle,ps,pv);
    destroy(ps);
    construct(ps,D_006A34F0);
    char *result=0;
    Found *found=func_00480878(handle,ps);
    if(found) {
        Entry *e=found->entry;
        result=__dynamic_cast_2(e->fn,func_00608F30,0,(char *)found+e->delta,func_00607408,found);
    }
    destroy(ps);
    if(result) *(int *)(result+0x74)=self->x70;
    RaceMonitor__update_pit_panel(self,RaceMonitor__is_player_car(self));
    func_004768C0(pv);
}

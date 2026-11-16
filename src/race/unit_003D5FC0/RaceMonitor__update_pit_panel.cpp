/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,selfish; };
struct Str { char *p; };
struct Val { int type; int spare[3]; };
struct Owner { int pad; int *handle; char pad8[8]; int race; char pad14[0x50]; int player; };
struct Entry { short delta,pad; void *fn; };
struct Found { char pad[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern char D_006A34B0[],D_006A34C0[],D_006A3398[],D_006A3368[],D_006A34D0[],D_006A34D8[];
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" void free(void *) throw();
extern "C" Found *func_00480878(int,Str *);
extern "C" char *__dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" int func_003FA4B0(int,int,int,signed char *);
extern "C" int func_0057DA20(char *,const char *,...);
extern "C" void func_00476AE8(Val *,const char *);
extern "C" void func_004768C0(Val *);
extern "C" int func_004809D8(char *,Str *,Val *);
extern "C" const char *func_003B03B8(int);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void RaceMonitor__update_pit_panel(Owner *self,int enabled) {
 union { Str str; signed char tires[2]; } u;
 char key[16];
 char buf[64];
 Val value;
 Str s;
 int handle=*self->handle;
 Str *ps0=&u.str;
 construct(ps0,D_006A34B0);
 char *panel=0;
 Found *f=func_00480878(handle,&u.str);
 if(f) { Entry *e=f->entry; panel=__dynamic_cast_2(e->fn,func_00608F30,0,(char *)f+e->delta,func_00607408,f); }
 destroy(&u.str);
 int count=0;
 if(panel) {
  *(int *)(panel+0x74)=enabled;
  for(int i=0;i<3;i++) count+=func_003FA4B0(self->race,self->player,2-i,0)>0;
  for(int i=0;i<3;i++) {
   int next=i+1;
   Val *pv=&value; pv->type=1;
   func_0057DA20(key,D_006A34C0,next);
   int lap=0;
   u.tires[0]=-1; u.tires[1]=-1;
   if(i<count) lap=func_003FA4B0(self->race,self->player,count-i-1,u.tires);
   if(lap>0) { func_0057DA20(buf,D_006A3398,lap); func_00476AE8(pv,buf); }
   else func_00476AE8(pv,D_006A3368);
   Str *ps=&s;
   construct(ps,key); func_004809D8(panel,&s,pv); destroy(&s);
   func_0057DA20(key,D_006A34D0,next);
   func_00476AE8(pv,func_003B03B8(u.tires[0]));
   construct(ps,key); func_004809D8(panel,&s,pv); destroy(&s);
   func_0057DA20(key,D_006A34D8,next);
   func_00476AE8(pv,func_003B03B8(u.tires[1]));
   construct(ps,key); func_004809D8(panel,&s,pv); destroy(&s);
   func_004768C0(pv);
  }
 }
}

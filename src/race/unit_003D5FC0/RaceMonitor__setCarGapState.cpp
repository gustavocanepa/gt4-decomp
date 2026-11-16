/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; int spare[3]; };
struct Val { int type; int spare[3]; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; char p60[0x14]; int visible; };
struct Node { char p0[0x14]; int id; char p18[0x3444-0x18]; int rank; };
struct Self { int p0; Found **handle; char p8[8]; void *race; char p14[0x14]; int mode; char p2c[0x38]; int player; };
struct Context { char p0[0x60]; void *entries; char p64[0x1c]; void *course; };
extern Rep D_00659E20;
extern char D_006A3350[],D_006A3500[],D_006A3510[],D_006A3520[],D_006A3528[],D_006A3530[],D_006A3540[];
extern int PDISTD__UNIT_MANAGER[];
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" float RaceCourse__getCourseLength(void *);
extern "C" const char *DisplayRText__getRTextStr(const char *);
extern "C" void RaceEntryBase__sortByRank(void *);
extern "C" Node *func_003D8CB8(Self *,Node *) throw();
extern "C" Node *func_003D8D08(Self *) throw();
extern "C" void func_003DA518(Found **,Found *,const char *,int) throw();
static inline void setState(Found **h,Found *w,const char *name,int state) { func_003DA518(h,w,name,state); }
extern "C" float func_003DBDF0(Context *,Node *,Node *) throw();
extern "C" float func_003DBE98(float) throw() __attribute__((const));
extern "C" void func_003DBEE8(char *,int,float,float) throw();
extern "C" int func_003FA508(void *,int,int);
extern "C" char *func_004728D0(int *);
extern "C" void func_004768C0(Val *);
extern "C" void func_00476AE8(Val *,const char *);
extern "C" void func_0047DA90(Found *,float);
extern "C" Found *func_00480878(Found *,Str *);
extern "C" int func_004809D8(Found *,Str *,Val *);
extern "C" void free(void *) throw();
extern "C" int func_0057DA20(char *,const char *,...);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Found *__dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
static inline Found *cast(Found *found) {
 Found *result=0;
 if(found) { Entry *e=found->entry; result=__dynamic_cast_2(e->fn,func_00608F30,0,(char *)found+e->delta,func_00607408,found); }
 return result;
}
extern "C" void RaceMonitor__setCarGapState(Self *self,Context *ctx) {
 union { char buf[32]; struct { Val value; Str s; } tail; } u;
 Str s;
 Val value;
 char label[64];
 if(self->handle && self->mode==1) {
  Found *handle=*self->handle;
  RaceEntryBase__sortByRank(ctx->entries);
  float pos=0.0f;
  Node *node=func_003D8D08(self);
  while(node) {
   Node *next=func_003D8CB8(self,node);
   if(!next) break;
   pos+=func_003DBE98(func_003DBDF0(ctx,node,next));
   node=next;
  }
  pos=(640.0f-pos)*0.5f+20.0f;
  Node *prev=0;
  int index=0;
  Node *current=func_003D8D08(self);
  while(current) {
   Str *ps=&s;
   int rank=current->rank;
   float oldpos=pos;
   func_0057DA20(u.buf,D_006A3500,rank+0x41);
   construct(ps,u.buf);
   Found *widget=cast(func_00480878(handle,ps));
   destroy(ps);
   float gap=0.0f;
   if(prev) { gap=func_003DBDF0(ctx,prev,current); pos+=func_003DBE98(gap); }
   if(widget) {
    func_0047DA90(widget,pos); widget->visible=1;
    int n=rank*2;
    int selected=n+1;
    if(current->id!=self->player) selected=n;
    setState(self->handle,widget,D_006A3350,selected);
    construct(ps,D_006A3510);
    Found *mark=cast(func_00480878(widget,ps));
    destroy(ps);
    if(mark) mark->visible=prev?func_003FA508(self->race,current->id,prev->id)!=0:0;
   }
   if(prev) {
    func_0057DA20(u.buf,D_006A3520,index+0x30);
    construct(ps,u.buf);
    Found *gapwidget=cast(func_00480878(handle,ps));
    destroy(ps);
    if(gapwidget) {
     func_003DBEE8(u.buf,32,gap,RaceCourse__getCourseLength(ctx->course));
     Val *pv=&value; pv->type=1;
     func_00476AE8(pv,u.buf);
     construct(ps,D_006A3528);
     func_004809D8(gapwidget,&s,pv);
     destroy(&s);
     func_0047DA90(gapwidget,(pos+oldpos)*0.5f); gapwidget->visible=1;
     func_004768C0(pv);
    }
   }
   ++index; prev=current; current=func_003D8CB8(self,prev);
  }
  const char *format=DisplayRText__getRTextStr(D_006A3530);
  char *unit=func_004728D0(PDISTD__UNIT_MANAGER);
  char *out=label;
  func_0057DA20(out,format,unit);
  u.tail.value.type=1;
  func_00476AE8(&u.tail.value,out);
  Found *h=*self->handle;
  Str *tail=&u.tail.s;
  construct(tail,D_006A3540); func_004809D8(h,tail,&u.tail.value); destroy(tail);
  func_004768C0(&u.tail.value);
 }
}

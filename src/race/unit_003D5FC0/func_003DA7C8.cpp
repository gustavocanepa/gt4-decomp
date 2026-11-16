/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" char *strcpy(char *, const char *);
extern "C" {
int Automobile__GetExplicitCurrentLap(void *);
u32 func_0035E3F0(void *);
void func_003B0320(char *, int, const char *, int);
void func_003DA518(void *, void *, const char *, int) throw();
void func_003DA668(char *, const char *, void *, float) throw();
int func_003DA6F8(void *, void *) throw();
unsigned short func_003FA498(void *, int);
void GranTurismo4__GetTimeString(u32, char *, u32);
void func_004768C0(void *);
void func_00476AE8(void *, const char *);
float *func_00479688(char *);
void *func_004796B8(char *);
char *func_00480878(void *, const void *);
int func_004809D8(void *, const void *, void *);
void func_00575DA0(void *) throw();
int func_0057DA20(char *, const char *, ...);
u32 func_0057F260(const char *) throw();
char *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
char *strobe__toUpper(void *);
void *strobe__Any__setMember(void *, u32, u32, const char *, u32);
}
extern char D_00606670[], D_00607408[], D_00608F30[];
extern char D_006A3350[], D_006A3358[], D_006A3360[], D_006A3370[], D_006A3378[], D_006A3388[], D_006A3390[], D_006A3398[], D_006A33A0[], D_006A33A8[];
struct Rep { u32 len,res,ref,selfish; char *data(){return (char *)(this+1);} char *grab(){if(selfish)return strobe__toUpper(this); ++ref; return data();} void release(){if(--ref==0)func_00575DA0(this);} };
extern Rep D_00659E20;
struct String { char *dat; char pad[12]; String(const char *s):dat(D_00659E20.grab()){strobe__Any__setMember(this,0,-1,s,func_0057F260(s));} ~String(){((Rep *)dat-1)->release();} };
struct Value { int data[4]; Value(){data[0]=1;} ~Value(){func_004768C0(this);} void assign(const char *s){func_00476AE8(this,s);} };
struct Car { char p0[0x14]; int id; void *ent; char p1[0x11DC - 0x1C]; u32 time; char p2[0x11E8 - 0x11E0]; int gap; const char *gapText; char p3[0x3444 - 0x11F0]; int grid; char p4[0x350C - 0x3448]; char name[128]; };
struct Monitor { char p0[0x10]; void *race; char p1[0xE2 - 0x14]; u8 best[6]; int laps[6]; u32 times[6]; char p2[0xFB4 - 0x118]; char names[6][128]; };
static inline char *toLabel(char *p){char *r=0; if(p){char *v=F(p,char *,0x5c); r=__dynamic_cast_2(F(v,void *,4),D_00606670,0,p+F(v,short,0),D_00607408,p);} return r;}
static inline char *toMark(char *p){char *r=0; if(p){char *v=F(p,char *,0x5c); r=__dynamic_cast_2(F(v,void *,4),D_00608F30,0,p+F(v,short,0),D_00607408,p);} return r;}
extern "C" void func_003DA7C8(Monitor *self, Car *car, void *owner, void *root, int first) {
 char buf[32];
 Value val;
 func_003DA518(owner, root, D_006A3350, car->grid);
 func_003DA518(owner, root, D_006A3358, func_003DA6F8(self, car));
 int id = car->id;
 void *ent = car->ent;
 int lap = Automobile__GetExplicitCurrentLap(ent);
 if (self->laps[id] != lap) {
  self->laps[id] = lap;
  self->best[id] = func_0035E3F0(ent) < self->times[id];
  self->times[id] = func_0035E3F0(ent);
 }
 char *name = self->names[id];
 if (!*name) {
  char *widget = toLabel(func_00480878(root, &String(D_006A3360)));
  if (widget) {
   const char *src = car->name;
   float *rect = func_00479688(widget);
   float width = rect[2] - rect[0];
   func_003DA668(name, src, func_004796B8(widget), width);
  } else {
   strcpy(name, "-");
  }
 }
 val.assign(name);
 func_004809D8(root, &String(D_006A3360), &val);
 GranTurismo4__GetTimeString(car->time, buf, 32);
 val.assign(buf);
 func_004809D8(root, &String(D_006A3370), &val);
 char *mark = toMark(func_00480878(root, &String(D_006A3378)));
 if (mark) F(mark, int, 0x74) = self->best[id] != 0;
 if (car->gapText) func_003B0320(buf, 32, car->gapText, 0);
 else if (car->gap >= 0) GranTurismo4__GetTimeString(car->gap, buf, 32);
 else buf[0] = 0;
 val.assign(buf);
 func_004809D8(root, &String(D_006A3388), &val);
 GranTurismo4__GetTimeString(func_0035E3F0(ent), buf, 32);
 val.assign(buf);
 func_004809D8(root, &String(D_006A3390), &val);
 func_0057DA20(buf, D_006A3398, Automobile__GetExplicitCurrentLap(ent));
 val.assign(buf);
 func_004809D8(root, &String(D_006A33A0), &val);
 func_0057DA20(buf, D_006A3398, func_003FA498(self->race, id));
 val.assign(buf);
 func_004809D8(root, &String(D_006A33A8), &val);
}

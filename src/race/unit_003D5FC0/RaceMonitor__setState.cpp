/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int (*VCall)(void *);
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" {
int DynamicsConductor__CurrentTotalTime(void *);
char *DisplayRText__getRTextStr(const char *);
void func_003B00A8(char *,int);
void RaceEntryBase__sortByRank(void *);
char *func_003D8CB8(void *,void *) throw();
char *func_003D8D08(void *) throw();
void func_003DA518(void *,void *,const char *,int) throw();
void func_003DA7C8(void *,void *,void *,void *,int) throw();
void func_004768C0(void *);
void func_00476AE8(void *,const char *);
void func_0047FCF8(void *,void *);
void func_00480638(void *,int);
char *func_00480878(void *,const void *);
int func_004809D8(void *,const void *,void *);
void func_00575DA0(void *) throw();
int func_0057DA20(char *,const char *,...);
u32 func_0057F260(const char *) throw();
char *__dynamic_cast_2(void *,void *,int,void *,void *,void *);
char *strobe__toUpper(void *);
void *strobe__Any__setMember(void *,u32,u32,const char *,u32);
}
extern char D_00608F30[],D_00607408[],D_006A33A0[],D_006A33B0[],D_006A33B8[],D_006A33C8[],D_006A33D8[],D_006A33F0[],D_006A3408[];
struct Rep { u32 len,res,ref,selfish; char *data(){return (char *)(this+1);} char *grab(){if(selfish)return strobe__toUpper(this); ++ref; return data();} void release(){if(--ref==0)func_00575DA0(this);} };
extern Rep D_00659E20;
struct String { char *dat; char pad[12]; String(const char *s):dat(D_00659E20.grab()){strobe__Any__setMember(this,0,-1,s,func_0057F260(s));} ~String(){((Rep *)dat-1)->release();} };
struct Value { int data[4]; Value(){data[0]=1;} ~Value(){func_004768C0(this);} void assign(const char *s){func_00476AE8(this,s);} };
static inline char *cast(char *p){char *r=0; if(p){char *v=F(p,char *,0x5c); r=__dynamic_cast_2(F(v,void *,4),D_00608F30,0,p+F(v,short,0),D_00607408,p);} return r;}
extern "C" void RaceMonitor__setState(char *self,char *ctx){
 if(F(self,void *,4)&&F(self,int,0x28)){
  char buf[64];
  void *root=F(F(self,void *,4),void *,0);
  int i=0;
  Value val;
  RaceEntryBase__sortByRank(F(ctx,void *,0x60));
  for(char *car=func_003D8D08(self);car;car=func_003D8CB8(self,car),i++){
   func_0057DA20(buf,D_006A33B0,i+1);
   char *widget=cast(func_00480878(root,&String(buf)));
   int selected=F(car,int,0x14)==F(self,int,0x64);
   if(widget){
    func_003DA7C8(self,car,F(self,void *,4),widget,i==0);
    F(widget,int,0x74)=1;
    func_00480638(widget,selected);
    func_0047FCF8(widget,F(self,void *,4));
    func_0047FCF8(widget,F(self,void *,4));
   }
   if(selected){
    val.assign(car+0x350c);
    func_004809D8(root,&String(D_006A33B8),&val);
    func_003DA518(F(self,void *,4),root,D_006A33C8,F(car,int,0x3444));
   }
  }
  for(;i<6;i++){
   func_0057DA20(buf,D_006A33B0,i+1);
   char *widget=cast(func_00480878(root,&String(buf)));
   if(widget) F(widget,int,0x74)=0;
  }
  char *race=F(self,char *,0x10);
  char *v=F(race,char *,0x10140)+0x128;
  int n=F(v,VCall,4)(race+F(v,short,0));
  const char *fmt;
  if(n>0)fmt=D_006A33D8;else fmt=D_006A33F0;
  func_0057DA20(buf,DisplayRText__getRTextStr(fmt),F(self+F(self,int,0x60)*4,int,0xe8),n);
  val.assign(buf);
  func_004809D8(root,&String(D_006A33A0),&val);
  func_003B00A8(buf,DynamicsConductor__CurrentTotalTime(F(self,void *,0x10)));
  buf[func_0057F260(buf)-4]=0;
  val.assign(buf);
  func_004809D8(root,&String(D_006A3408),&val);
  F(self,int,0xa4)=(F(self,int,0xa4)&~255)|1;
 }
}

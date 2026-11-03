/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Loads data into a local buffer (func_001CDAC8) under a progress report, hands it to the global
   sink, then runs func_001CE9D0 on the sink's +0xBC30 area and finishes with func_0043AC28 and
   func_00436248; each Result is tested in place, as in the loader func_001CDE38. */
struct PEntry { short delta,index; void (*fn)(void*,float); };
struct PTable { char pad[0x10]; PEntry e; };
struct Progress { PTable *vt;int arg;char pad[8]; };
struct Result { int value; };
static inline int status(const Result *const x) { return x->value; }
struct Entry { short delta,index; int (*fn)(void*,void*); };
struct Sink { Entry *vt; };
struct Buf { int unk0; void *data; int size; int cap; int pad[4]; };
extern PTable D_00661718,D_0065CE00;
extern Sink *D_00622F4C;
extern "C" Result func_001CDAC8(void*,void*,Buf*,int);
extern "C" Result func_001CE9D0(void*,void*,char*,int);
extern "C" void func_00575DA0(void*);
extern "C" void func_0043AC28(Sink*);
extern "C" void func_00436248();
static inline void progress(Progress *p,float f) { PEntry *e=&p->vt->e;e->fn((char*)p+e->delta,f); }
static inline void put(Sink *o,void *data) { Entry *e=o->vt+6;e->fn((char*)o+e->delta,data); }
extern "C" int func_001CDCC0(void *self,void *src,int unused,int arg) {
 Progress p;Result result;Buf buf;
 p.vt=&D_00661718;p.arg=arg;
 PTable *fin=&D_0065CE00;
 progress(&p,0.0f);
 buf.data=0;buf.size=0;buf.cap=0;
 result=func_001CDAC8(self,src,&buf,arg);
 int r=status(&result);
 if(r){int v=result.value;if(buf.data)func_00575DA0(buf.data);p.vt=fin;return v;}
 put(D_00622F4C,buf.data);
 if(buf.data)func_00575DA0(buf.data);
 result=func_001CE9D0(self,src,(char*)D_00622F4C+0xBC30,1);
 if(status(&result)){p.vt=fin;return result.value;}
 func_0043AC28(D_00622F4C);
 func_00436248();
 progress(&p,1.0f);
 p.vt=fin;return 0;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds an on-screen element from game data: looks up the entry named D_006A3410 in the owner's handle, loads its
 * instance (GT4MC FileGT4GameData), stores func_003D8C18(self) at +0x74 of it, then for slots 1..7 formats a name
 * (D_006A3420 with the slot number) and calls func_003DA518 with a flag: slots 1-5 are on when the slot equals pace+1,
 * slot 6 when +0x50 > 0, slot 7 when +0x54 > 0. Last it fetches a localised string (text table at 0x621C78 indexed by
 * +0x58) and sets it as a member of the instance. The names behind the string constants are purpose unknown. The
 * grab/construct/destroy helpers are the inlined refcounted-string handling the compiler needed to see. */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Val { int type; int spare[3]; };
struct Owner { int pad0; int *handle; char pad8[0x4c-8]; int pace, p50, p54, p58; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_00659E20;
extern char D_006A3410[], D_006A3420[], D_006A3498[], D_006A34A0[];
extern "C" void func_00608F30();
extern "C" void func_00607408();
extern "C" int func_003D8C18(Owner *) throw();
extern "C" void func_003DA518(int *,char *,const char *,int) throw();
extern "C" Found *func_00480878(int,Str *);
extern "C" void free(void *) throw();
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" char *__dynamic_cast_2(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" char *DisplayRText__getRTextStr(int);
extern "C" void func_004768C0(Val *);
extern "C" void func_00476AE8(Val *,const char *);
extern "C" int func_004809D8(char *,Str *,Val *);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_00659E20); strobe__Any__setMember(s,0,-1,p,func_0057F260(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_003DB520(Owner *self) {
    union { Val v; Str s; } first;
    union { char buf[32]; Str s; } second;
    Str *firstString=&first.s;
    int handle=*self->handle;
    const char *lookupName=D_006A3410;
    firstString->p=grab(&D_00659E20);
    char *instance=0;
    strobe__Any__setMember(firstString,0,-1,lookupName,func_0057F260(lookupName));
    Found *found=func_00480878(handle,&first.s);
    if(found) {
        Entry *entry=found->entry;
        instance=__dynamic_cast_2(entry->fn,func_00608F30,0,(char *)found+entry->delta,func_00607408,found);
    }
    destroy(&first.s);
    if(instance) *(int *)(instance+0x74)=func_003D8C18(self);
    for(int slot=1;slot<8;slot++) {
        func_0057DA20(second.buf,D_006A3420,slot);
        int slotOn=0;
        switch(slot) {
        case 1: case 2: case 3: case 4: case 5: slotOn=slot==self->pace+1; break;
        case 6: slotOn=self->p50>0; break;
        case 7: slotOn=self->p54>0; break;
        }
        func_003DA518(self->handle,instance,second.buf,slotOn);
    }
    const char *labelText=DisplayRText__getRTextStr(((int *)0x621C78)[self->p58]);
    if(!labelText) labelText=D_006A3498;
    first.v.type=1;
    func_00476AE8(&first.v,labelText);
    construct(&second.s,D_006A34A0);
    func_004809D8(instance,&second.s,&first.v);
    destroy(&second.s);
    func_004768C0(&first.v);
}

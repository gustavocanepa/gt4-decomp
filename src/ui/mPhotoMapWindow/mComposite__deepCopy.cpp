/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; void (*fn)(void *); };
struct S { int x; Entry *vt; char pad[0x98]; int a0; char pad2[8]; int ac; };
extern char mComposite__tf[], hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" int __dynamic_cast_2(void *,void *,int,void *,void *,void *);
extern "C" int func_00206860(S *) throw();
extern "C" void func_00206B60(void *,int) throw();
extern "C" void func_0030BA08(void *,int);
extern "C" void func_00255110(void *,void *);
extern "C" void func_00309378(void *,int);
extern "C" void func_002550B8(void *,int);
extern "C" int func_0025C2F8(void *);
extern "C" void mComposite__deepCopy(S *self, S *src) {
 int buf[4], temp[4];
 mWidget__deepCopy(self,src);
 S *copy=0;
 if(src) {
  Entry *e=src->vt;
  copy=(S *)__dynamic_cast_2((void *)e->fn,mComposite__tf,0,(char *)src+e->delta,hObject__tf,src);
 }
 if(copy) {
  int v_ac = copy->ac;
  self->a0=0;
  self->ac=v_ac;
  void *p=(void *)func_00206860(copy);
  if(p) {
   do {
    func_0030BA08(temp,(int)p);
    func_00255110(buf,temp);
    func_00309378(temp,2);
    func_00206B60(self,buf[0]);
    func_002550B8(buf,2);
    p=(void *)func_0025C2F8(p);
   } while(p);
  }
 }
}

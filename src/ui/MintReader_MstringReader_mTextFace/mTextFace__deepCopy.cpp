/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry {
 short delta,index;
 void (*fn)(void *,void *);
};
struct Object { int a0; VEntry *vt; };
struct Face {
 int a0; VEntry *vt;
 char pad8[0x98]; char style[0x64];
 Object *child; int a108;
};
extern char mTextFace__tf[];
extern char hObject__tf[];
extern "C" void mWidget__deepCopy(Face *,Object *);
extern "C" Face *__dynamic_cast_2(void (*)(void *,void *),void *,int,void *,void *,void *);
extern "C" void func_00248398(void *,void *);
extern "C" void mTextFace__deepCopy(Face *self,Object *src) {
 mWidget__deepCopy(self,src);
 Face *r=0;
 if (src != 0) {
  VEntry *e=src->vt;
  r=__dynamic_cast_2(e->fn,mTextFace__tf,0,(char *)src+e->delta,hObject__tf,src);
 }
 if (r != 0) {
  func_00248398(self->style,r->style);
  Object *child=self->child;
  VEntry *e=child->vt+9;
  e->fn((char *)child+e->delta,r->child);
  self->a108=r->a108;
 }
}

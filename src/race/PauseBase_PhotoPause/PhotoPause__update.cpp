/* compiler: ee-gcc2.96-no-strict-aliasing */
// Partial, provisional layouts: padding preserves observed ABI offsets.
// The camera property meanings below are also used by PhotoPause__callFunction.
// These embedded capture settings and the camera are borrowed from PhotoPause;
// buffer allocation is delegated to func_00106A68.
struct Sub {
 char p[0x118];
 int unknown118;
 char q[12];
 int mode, resetState;
 float scale, exposure, colorTemperature;
};
struct Self { char p[0x10]; void *anim; int p14; int active; int p1c; Sub sub; char gap[0x198-0x20-sizeof(Sub)]; int frame,count,pending,disabled,mode,choice; };
struct Entry { short delta,index; void *fn; };
struct Root { char p[0x64]; Entry *vt; };
struct Race { char p[0xe424]; void *monitor; };
struct Car { char p[0x18]; void *data; };
struct Link3 { int a,value; };
struct Link2 { char pad[0x18]; Link3 *p; };
struct Link1 { Link2 *p; };
struct Link0 { char pad[8]; Link1 *p; };
struct Context { char pad[0x60]; Link0 *p; };
struct Global { char pad[0x39dd0]; int value; };
extern Global *D_00622F4C;
extern char RaceBasic__tf[],RacePS2Base__tf[],D_006A2C78[],D_006A2C80[],D_006A2CA0[],D_006184D0[];
// Unnamed virtual slots retain their positions in the original camera ABI.
struct Camera {
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void v10();
 virtual void v11();
 virtual float getAperture();
 virtual void v13();
 virtual void v14();
 virtual void v15();
 virtual float getExposure();
 virtual float getColorTemperature();
 virtual float getPortraitMode();
 virtual void v19();
 virtual void v20();
 virtual void v21();
 virtual void v22(Context *,int,int);
 virtual void v23();
 virtual void v24();
 virtual void v25();
 virtual void v26();
 virtual void v27();
 virtual void v28();
 virtual void v29();
 virtual void v30();
 virtual void v31();
 virtual void v32();
 virtual void v33();
 virtual void v34();
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual int v39(int);
 virtual void v40();
 virtual void v41();
 virtual void v42();
 virtual void v43();
 virtual Car *v44();
 virtual void v45();
 virtual void v46();
 virtual void v47();
 virtual void v48();
 virtual void v49();
 virtual void v50();
 virtual void v51();
 virtual void v52();
 virtual void v53();
 virtual void v54();
 virtual int v55();
};
extern "C" void PauseBase__clearTimeCount(Self *);
extern "C" void func_003C49C8(Self *) throw();
extern "C" Root *func_003C3F98(Self *) throw();
extern "C" Race *__dynamic_cast_2(void *,void *,int,void *,void *,Root *);
extern "C" int RaceMonitor__isFullScreenMode(void *);
extern "C" void func_004857C8(const char *);
extern "C" Camera *func_003C3FA0(Self *) throw();
extern "C" int GetPitStopStatus(void *);
extern "C" int func_00333550();
extern "C" void *DisplayRText__getRTextStr(const char *);
extern "C" void func_0038BC98(Race *,void *,int,float);
extern "C" void func_003C4928(Self *) throw();
extern "C" void func_00475488(void *,float);
extern "C" int RaceInput__getButtonDown(void *);
extern "C" int func_00426A90(void *);
extern "C" int func_00426A88(void *);
extern "C" int func_00436640(void *);
extern "C" void PhotoPause__deleteAnimInst(Self *) throw();
extern "C" void func_003335F8(Sub *,int,int,int,int,int,float);
extern "C" void func_00333680(Sub *,float);
extern "C" void func_00106A68(void *,int,int,int);
extern "C" void func_003C2940(void *);
// Store the final camera property and reset the capture processing state.
static inline void setCaptureFilter(Sub *s, float temperature) {
 s->colorTemperature=temperature;
 s->resetState=0;
}
extern "C" int PhotoPause__update(Self *self, void *input, Context *context) {
 if(self->frame<0) {
 if(!self->pending) {
 if(self->disabled) {
  if(++self->disabled==3) {
   PauseBase__clearTimeCount(self); self->active=0; func_003C49C8(self); self->disabled=0; return 3;
  }
  return 1;
 }
 if(!self->active) {
  Race *race=0;
  Root *r=func_003C3F98(self);
  if(r) race=__dynamic_cast_2(r->vt->fn,RaceBasic__tf,0,(char*)r+r->vt->delta,RacePS2Base__tf,r);
  void *monitor=race ? race->monitor : 0;
  if(monitor && RaceMonitor__isFullScreenMode(monitor)) {func_004857C8(D_006A2C78); return 3;}
  if(GetPitStopStatus(func_003C3FA0(self)->v44()->data) && !func_00333550()) {
   if(race) func_0038BC98(race,DisplayRText__getRTextStr(D_006A2C80),0,3.0f);
   return 3;
  }
  self->active=1; func_003C4928(self);
 }
 if(self->anim) func_00475488(self->anim,0.08333333f);
 if(RaceInput__getButtonDown(input)&0x80) {
  func_00436640((char*)D_00622F4C+0x38cb0); self->disabled=1; return 1;
 }
 if(func_00426A90(input)&0x20) {if(++self->mode>=3) self->mode=0;}
 int buttons=func_00426A88(input);
 // Simultaneous direction inputs cancel the selected adjustment.
 int count=0;
 self->choice=-1;
 if(buttons&0x200) {self->choice=0; count=1;}
 if(buttons&1) {++count; self->choice=1;}
 if(buttons&0x400) {++count; self->choice=2;}
 if(buttons&2) {++count; self->choice=3;}
 if(count>=2) self->choice=-1;
 Camera *cam=func_003C3FA0(self);
 cam->v22(context,context->p->p->p->p->value,1);
 if(cam->v55() && self->frame<0) {
  PhotoPause__deleteAnimInst(self); self->frame=0; func_004857C8(D_006A2CA0);
  int flag=cam->getPortraitMode()>0.5f;
  Sub *sub=&self->sub;
  func_003335F8(sub,640,480,2,2,flag,1.3333332538604736328125f);
  sub->unknown118=32;
  func_00333680(sub,cam->getAperture());
  sub->mode=self->mode;
  sub->scale=(float)D_00622F4C->value/10.0f+1.0f;
  sub->exposure=cam->getExposure();
  setCaptureFilter(sub,cam->getColorTemperature());
  func_00106A68(D_006184D0,2,256,384);
  // Capture setup completes this update; return directly from this path.
  return 1;
 } else {
  if(cam->v39(0)) func_003C2940((char*)func_003C3F98(self)+0x3238);
  PauseBase__clearTimeCount(self);
 }
 }
 }
 return 1;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;
extern "C" void func_0055D408(void *);

struct Chan {
    char pad00[0x10]; s32 f10; char pad14[6]; s16 f1A; char pad1C;
    s8 f1D[0x12]; char pad2F; s32 f30,f34,f38,f3C,f40,f44,f48,f4C,f50,f54,f58,f5C,f60;
    s16 f64,f66; s32 f68,f6C,f70,f74,f78,f7C,f80,f84,f88; char pad8C[0xA];
    s16 f96,f98; char pad9A[2];
};
extern "C" void func_0055D778(Chan *p, s32 x) {
    p->f3C=-1; p->f44=-1; p->f30=x;
    p->f34=(s32)0x80000000u; p->f4C=0x3fff; p->f50=0x7f; p->f40=-1;
    p->f54=0x3fff; p->f58=0x7f; p->f5C=0x7f; p->f64=0x3fff;
    p->f1A=0;
    p->f60=0x7f;
    p->f1A=0;
    p->f66=0x3fff;
    p->f1D[0]=0;p->f1D[1]=0;p->f1D[2]=0;p->f1D[3]=0;p->f1D[4]=0;p->f1D[5]=0;
    p->f1D[6]=0;p->f1D[7]=0;p->f1D[8]=0;p->f1D[9]=0;p->f1D[10]=0;p->f1D[11]=0;
    p->f1D[12]=0;p->f1D[13]=0;p->f1D[14]=0;p->f1D[15]=0;p->f1D[16]=0;p->f1D[17]=0;
    p->f10=0;
    p->f68=0x40; p->f74=0x1000; p->f6C=0x40; p->f70=0x40; p->f88=0x40; p->f78=0; p->f7C=0; p->f80=0; p->f84=0; p->f96=0; p->f98=0;
    func_0055D408((char*)p+0x9c); func_0055D408((char*)p+0xac); func_0055D408((char*)p+0xbc);
    s32 *tail=(s32*)((char*)p+0xcc); tail[1]=0; tail[2]=0; tail[4]=0; tail[3]=0; tail[0]=0;
}

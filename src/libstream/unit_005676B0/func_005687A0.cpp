/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Decodes a motion vector pair: per component a motion code (func_00568610), f-code residual bits
   when both are nonzero, reconstruction by func_005688C8 (the vertical one halved around it for
   field vectors), then a dual-prime delta (func_00568660) when ctx->dmv.on is set. */
extern "C" short func_00568610(void);
extern "C" short func_00568660(void);
extern "C" int func_00563158(int n);
extern "C" void func_005688C8(int *mv, int fcode, int code, int resid);
struct Dmv { int on; int x; int y; };
struct Ctx { int full; char pad4[0x10]; Dmv dmv; };
extern "C" void func_005687A0(Ctx *ctx, int *mv, int fh, int fv) {
    int full = ctx->full;
    Dmv *d = &ctx->dmv;
    int code = func_00568610();
    int resid;
    if (fh && code) resid = func_00563158(fh);
    else resid = 0;
    func_005688C8(mv, fh, code, resid);
    if (d->on) d->x = func_00568660();
    code = func_00568610();
    if (fv && code) resid = func_00563158(fv);
    else resid = 0;
    if (full) mv[1] >>= 1;
    func_005688C8(&mv[1], fv, code, resid);
    if (full) mv[1] <<= 1;
    if (d->on) d->y = func_00568660();
}

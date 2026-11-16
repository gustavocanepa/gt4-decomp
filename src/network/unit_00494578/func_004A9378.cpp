/* Renders through a temporary 0x2000-byte work buffer: builds two packets in it (at 0x1800 and
   0x1900), then calls the worker with the current frame base, the caller's arguments, the
   buffer, both packets, a scissor register for w x h and the scratchpad's mode byte, and
   releases the buffer. */
#include "spr.h"
struct Spr { char pad0[0x172]; unsigned char mode; char pad173[0x4D]; unsigned long frame; };
extern "C" int func_004AA558(int);
extern "C" void func_004A9228(int);
extern "C" void func_004A8F78(int);
extern "C" void func_004A9470(int, int, int, int, int, int, int, long, int);
extern "C" int func_004AA6B8(int);
extern "C" int func_004A9378(int a, int b, int c, int w, int h) {
    Spr *s = (Spr *)spr_base();
    int buf = func_004AA558(0x2000);
    long scissor = (((long)h - 1) << 48) | (((long)w - 1) << 16);
    int fbp = (int)(s->frame & 0x3FFF) << 6;
    int mode = s->mode;
    int p0 = buf + 0x1800;
    int p1 = buf + 0x1900;
    func_004A9228(p0);
    func_004A8F78(p1);
    func_004A9470(fbp, a, b, c, buf, p0, p1, scissor, mode);
    return func_004AA6B8(buf);
}

/* Error exit of the decoder: jumps back to the setjmp taken in func_004B0120 with value 1.
   longjmp does not return, hence no epilogue; the function that follows it (004B0210, glued to
   this one in the inventory) flags the decoder as running and enters its loop. */
struct Obj { char pad[0x50]; char jmp[0x3240]; int running; };
extern "C" void longjmp(void *, int) __asm__("func_005A5930") __attribute__((noreturn));
extern "C" void func_004B0610(Obj *);
extern "C" void func_004B01F8(Obj *p) {
    longjmp(p->jmp, 1);
}
extern "C" void func_004B0210(Obj *p) {
    p->running = 1;
    func_004B0610(p);
}

/* Decodes through the stream reader with a setjmp error trap: opens (virtual slot 6), runs the
   reader unless an error unwound back here, then closes (virtual slot 7). setjmp keeps self in
   memory, hence the reloads. */
struct Reader {
    char pad0[0x44];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void open();
    virtual void close(int done);
};
struct Decoder : Reader {
    char pad48[0x304C];
    int state;
    char pad3098[8];
    char jmp[1];
};
extern "C" void func_00572D30(Decoder *);
extern "C" int func_00573898(Decoder *);
extern "C" int setjmp(void *) __asm__("func_005A58D8");
extern "C" void func_004AE0B8(Decoder *self) {
    self->state = 0;
    func_00572D30(self);
    self->open();
    if (setjmp(self->jmp) == 0) func_00573898(self);
    self->close(1);
}

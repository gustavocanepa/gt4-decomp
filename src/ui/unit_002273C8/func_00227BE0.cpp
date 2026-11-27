/* Default project compiler (ee-gcc 2.96 -O2 -G0 -fno-exceptions): no compiler marker. */
struct Ring { int unk0; int unk4; int used; };
struct Console {
    char pad0[0x10];
    Ring ring;
    char pad1C[0x104];
    int sema;
};
extern "C" {
int func_0057F260(const char *) throw();
char *func_00575DC8(int) throw();
void func_005A6AB0(char *, const char *, int) throw();
void func_00576788(int *) throw();
void func_005DA9E8(Ring *, const char *, int) throw();
void func_005767C0(int *) throw();
void func_00575DA0(char *) throw();
void mUpdateContext__Sync(int) throw();
}
struct Lock {
    int *sema;
    void lock(int *s) { sema = s; func_00576788(s); }
    void unlock() { func_005767C0(sema); }
};

/* Writes a text to the console ring buffer (0x100 bytes), waiting one frame between tries (at
 * most 10): when the free space is smaller than the text, a chunk of that size is copied and
 * written, the rest waits for the next try.
 * Shape notes: the frame wait is written inside the partial arm as well (jump2 cross-jumps it with
 * the shared one after sched2): with that call in the arm's block the a1/a2 argument copies of the
 * ring write have one dependent more than the a0 copy (whose register is set again for unlock),
 * and sched2 issues a1, a2, a0 as the original does. The goto keeps the completing write after
 * the wait in the layout. */
extern "C" void func_00227BE0(Console *self, const char *text) {
    int length = func_0057F260(text);
    int *sema = &self->sema;
    Ring *ring = &self->ring;
    Lock lock;
    for (int tries = 0; tries < 10; tries++) {
        int space = 0x100 - ring->used;
        if (space > 0) {
            if (space < length) {
                char *chunk = func_00575DC8(space);
                length -= space;
                func_005A6AB0(chunk, text, space);
                lock.lock(sema);
                func_005DA9E8(ring, chunk, space);
                text += space;
                lock.unlock();
                func_00575DA0(chunk);
                mUpdateContext__Sync(1);
                continue;
            } else {
                goto complete;
            }
        }
        mUpdateContext__Sync(1);
        continue;
    complete:
        lock.lock(sema);
        func_005DA9E8(ring, text, length);
        lock.unlock();
        mUpdateContext__Sync(1);
        return;
    }
}

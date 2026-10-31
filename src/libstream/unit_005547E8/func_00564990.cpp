/* Current read position of a stream buffer: 0 without a handle or when func_00564840 reports a
   problem, else base + idx * size read under the buffer's semaphore. func_00564840 is declared
   throw(): otherwise reorg sees $v0 live after the first test and annuls its slot (beql). */
struct Buf { int base; int pad4; int size; int padc; int pad10; int idx; int count; int handle; int sema; };
extern "C" int func_00564840(Buf *) throw();
extern "C" int func_005ADCE0(int), func_005ADCC0(int);
extern "C" int func_00564990(Buf *b) {
    if (b->handle == -1 || func_00564840(b)) return 0;
    func_005ADCE0(b->sema);
    int r = b->base + b->idx * b->size;
    func_005ADCC0(b->sema);
    return r;
}
/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reads up to n bytes of a NUL-terminated string from the object's byte queue under its mutex,
   consuming each byte with func_0060EC10; on the NUL it drops the count and returns 1, else 0.
   One int carries both the copied byte and the result, as retail's register homes require. */
struct Mutex { int x[2]; };
struct Queue { int x0; int off; int x8; char data[1]; };
struct O { int x0; int x4; Mutex m; char pad[0x190 - 0x10]; int count; Queue *q; };
extern "C" void func_00576788(Mutex *);
extern "C" void func_005767C0(Mutex *);
extern "C" void func_0060EC10(Queue *, int);
extern "C" int func_004F2308(O *o, char *dst, int n) {
    int done = 0;
    int value;
    Mutex *m = &o->m;
    func_00576788(m);
    if (--n != -1) do {
        Queue *q = o->q;
        char c = q->data[q->off];
        func_0060EC10(q, 1);
        value = c;
        *dst++ = value;
        if (c == 0) {
            o->count--;
            done = 1;
            break;
        }
    } while (--n != -1);
    func_005767C0(m);
    value = done;
    return value;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;

struct Req_00611A48 {
    int m0;
    char data[0x3C];
};

struct Obj_00611A48 {
    int m0;
    char pad4[0x24];
    u64 m28;
};

extern "C" void func_0055CFE8(Req_00611A48 *req, u64 id);
extern "C" void func_0055C9A0(int h, Req_00611A48 *req, void (*cb)(void), Obj_00611A48 *obj, int flags);
extern "C" void func_0055AB00(void);

extern "C" void func_00611A48(Obj_00611A48 *obj) {
    if (obj->m0 != 0) {
        Req_00611A48 req;
        func_0055CFE8(&req, obj->m28);
        func_0055C9A0(req.m0, &req, func_0055AB00, obj, 0);
        obj->m0 = 0;
    }
}

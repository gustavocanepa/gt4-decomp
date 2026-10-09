typedef int s32;

extern "C" void func_00203118(void *arg0, s32 arg1);
extern "C" void func_00574DA8(void *arg0, s32 arg1);
extern "C" void func_005DD278(void *arg0);
extern "C" void func_005DD1F8(void *arg0);
extern "C" void func_005DD168(void *arg0);
extern "C" const char **func_005DD870(void);
extern "C" const char **func_005DD830(void);
extern "C" const char **func_005DD7F0(void);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mUpdateContext__vtable;

struct Node { void *a; void *p; };
static inline void kill_a(Node *q) { func_005DD278(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD870()); }
static inline void kill_b(Node *q) { func_005DD1F8(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD830()); }
static inline void kill_c(Node *q) { func_005DD168(q); void *p = q->p; func_00326798(p, 0xC, 4, *func_005DD7F0()); }

extern "C" void mUpdateContext__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &mUpdateContext__vtable;
    func_00203118((char *)arg0 + 0x118, 2);
    func_00574DA8((char *)arg0 + 0xE8, 2);
    kill_a((Node *)((char *)arg0 + 0xCC));
    kill_b((Node *)((char *)arg0 + 0x18));
    kill_c((Node *)((char *)arg0 + 0x10));
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x12C, 4, "RefCounter");
    }
}

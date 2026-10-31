/* MRenderContext__startPage without the list opening call: builds a context handle from arg1, adds the object of
   each of the count names through a temporary handle and closes the list. Same guarded loop shape. */
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_0022ACC8(void *, int);
extern "C" void func_0022F890(void *, void *);
extern "C" void func_0022F948(void *);
extern "C" void func_00232C78(void *, void *);
extern "C" void func_00232C20(void *, int);

struct Handle {
    void *p;
    int pad[3];
};

static inline void *get(Handle *h) { return h->p; }

extern "C" void MRenderContext__pushPage(void *arg0, void *arg1, int count, void **names)
{
    if (count > 0) {
        Handle ctx;
        int i;
        func_0022AD20(&ctx, arg1);
        Handle obj;
        Handle *pobj;
        i = 0;
        if (i < count) {
            pobj = &obj;
            for (; i < count; i++) {
                void *list = ctx.p;
                func_00232C78(&obj, &names[i]);
                func_0022F890(list, get(&obj));
                func_00232C20(pobj, 2);
            }
        }
        func_0022F948(ctx.p);
        func_0022ACC8(&ctx, 2);
    }
}

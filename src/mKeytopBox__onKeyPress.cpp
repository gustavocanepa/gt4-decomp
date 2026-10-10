struct KeyEvent {
    char pad0[0x20];
    unsigned int key;
};

struct mWidget;
struct mKeytopBox;

extern "C" int mKeytopBox__on_activate(mKeytopBox *self, void *ctx);
extern "C" mWidget *mWidget__getRootWindow(mKeytopBox *self);
extern "C" void mRenderContext__closePage(void *ctx, mWidget *root);

extern "C" int mKeytopBox__onKeyPress(mKeytopBox *self, void *ctx, KeyEvent *e) {
    switch (e->key) {
    case 0xFF0D:
    case 0xFF8D:
        return mKeytopBox__on_activate(self, ctx);
    case 0xFF1B:
        mRenderContext__closePage(ctx, mWidget__getRootWindow(self));
        return 2;
    }
    return 0;
}

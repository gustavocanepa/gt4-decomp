struct Pool {
    char pad0[0x60];
    void *queue;
    int pad64[2];
    void *items[1];
};

extern "C" int func_005657E0(void *queue, int timeout, int *index);

// Takes the next item index from the pool's queue (no wait) and returns the item through out;
// the result variable is its own pseudo (copied from the call result, set to 0 on success).
extern "C" int func_005528A8(Pool *self, void **out)
{
    int index[4];
    void **items = self->items;
    int ret;
    int e = func_005657E0(self->queue, 0, index);
    if (e != 0) {
        ret = e;
    } else {
        ret = 0;
        *out = items[index[0]];
    }
    return ret;
}

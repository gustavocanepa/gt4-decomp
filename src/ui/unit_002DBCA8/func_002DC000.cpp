/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef short s16;

struct Widget { char pad0[4]; char *vtbl; };
struct VEntry { s16 delta; s16 index; void (*fn)(); };

extern "C" Widget *func_00206868(Widget *);
extern "C" void mPhotoMapWindow__virtual_101(Widget *, void *, s32, Widget *);
extern "C" s32 func_0025C2E8(Widget *);
extern "C" s32 func_002DBCA8(s32 *, Widget *, s32);
extern "C" Widget *func_002DBE50(s32 *, s32, Widget *, s32);

/* virtual slot 100: nothing to show for this key */
static inline void notifyNone(Widget *self, void *a1, s32 key) {
    VEntry *e = (VEntry *)(self->vtbl + 0x320);
    ((void (*)(void *, void *, s32))e->fn)((char *)self + e->delta, a1, key);
}

/* virtual slot 101: show the item without the filtered path */
static inline void notifyItem(Widget *self, void *a1, s32 key, Widget *item) {
    VEntry *e = (VEntry *)(self->vtbl + 0x328);
    ((void (*)(void *, void *, s32, Widget *))e->fn)((char *)self + e->delta, a1, key, item);
}

extern "C" void func_002DC000(Widget *self, void *a1, s32 *keyRef, s32 *list, s32 *filter) {
    if (*list != 0) {
        s32 key = *keyRef;
        Widget *item = func_00206868(self);
        /* Retail keeps the key in two saved registers: the copy made after the
           first call serves every use but the last one, so it has two sets. */
        s32 k = key;
        if (item == 0) {
            notifyNone(self, a1, k);
            return;
        }
        item = func_002DBE50(list, k, item, func_0025C2E8(item));
        if (item != 0) {
            /* An empty filter is the expected case: retail's branch to the
               unfiltered path is predicted taken (annulled delay slot). */
            if (__builtin_expect(*filter, 0) != 0 && func_002DBCA8(filter, item, k) != 0) {
                mPhotoMapWindow__virtual_101(self, a1, k, item);
                return;
            }
            notifyItem(self, a1, k, item);
            return;
        }
        k = key;
        notifyNone(self, a1, k);
    }
}

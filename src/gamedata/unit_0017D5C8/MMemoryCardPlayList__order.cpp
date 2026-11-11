#include "types.h"

/* Script method MMemoryCardPlayList.order (config/adhoc_methods.txt). Inferred: with at least one
 * argument, builds a new play list whose i-th entry is the current list's entry at the index held by
 * the i-th element of the argument array (indices past the current count leave that entry unset),
 * gives it the array's length as its count and hands both lists to func_001D1440, which installs the
 * new order. The play list itself is reached through the object handle func_0017D2C0 builds. */

extern "C" u32 hArray__size(void *);

struct PlayList {
    u64 entries[400];
    s32 count;
};

struct PlayListRef {
    u8 *node;
    u32 pad[3];
};

struct IndexArray {
    void *rep;
    u32 pad[3];
    u32 size() { return hArray__size(rep); }
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ScriptValue {
    char pad[4];
    VEntry *vtbl;
};

extern "C" void func_0017D2C0(PlayListRef *, void *);
extern "C" void func_0017D268(PlayListRef *, s32);
extern "C" void func_002ED618(IndexArray *, void *);
extern "C" void func_002ED5C0(IndexArray *, s32);
extern "C" ScriptValue **HArray__operator_index(IndexArray *, u32);
extern "C" void func_001D1440(PlayList *, PlayList *);

/* Virtual slot 0x58 of a script value: its integer value. */
static inline s32 to_int(ScriptValue *value) {
    VEntry *e = (VEntry *)((char *)value->vtbl + 0x58);
    return e->fn((char *)value + e->delta);
}

extern "C" void MMemoryCardPlayList__order(void *ret, void *self, s32 argc, void *args) {
    if (argc > 0) {
        PlayListRef ref;
        IndexArray indices;
        PlayList ordered;
        func_0017D2C0(&ref, self);
        PlayList *current = *(PlayList **)(ref.node + 0x10);
        func_002ED618(&indices, args);
        ordered.count = 0;
        for (u32 i = 0; i < indices.size(); i++) {
            s32 index = to_int(*HArray__operator_index(&indices, i));
            if (index < current->count)
                ordered.entries[i] = current->entries[index];
        }
        ordered.count = indices.size();
        func_001D1440(current, &ordered);
        func_002ED5C0(&indices, 2);
        func_0017D268(&ref, 2);
    }
}

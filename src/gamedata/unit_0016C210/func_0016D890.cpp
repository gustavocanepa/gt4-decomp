/* Checked downcast of a reference-counted handle to mGarage (inferred from the __tf type-info arguments: this is the shape of GCC 2.96's
 * dynamic_cast call). On success the new reference is added (func_003285A8) and the previous one released (func_003285F8,
 * inferred from the increment-before-replace order) and 1 is returned; otherwise the destination is left untouched and 0 is returned. */
struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct NodeB {
    int unk0;
    Unk64 *unk64;
};

extern char mGarage__tf[];
extern char RefCounter__tf[];

extern void *__dynamic_cast_2(int, void *, int, void *, void *, void *);
extern void func_003285A8(void *);
extern void func_003285F8(void *);

int func_0016D890(void **dest, NodeB **source)
{
    NodeB *node;
    void *casted;
    int succeeded;

    casted = 0;
    node = *source;
    if (node != 0) {
        Unk64 *u = node->unk64;
        casted = __dynamic_cast_2(u->unk4, mGarage__tf, 0,
                                (char *)node + u->unk0,
                                RefCounter__tf, node);
    }
    if (casted != 0) {
        func_003285A8(casted);
        if (*dest != 0) {
            func_003285F8(*dest);
        }
        *dest = casted;
        succeeded = 1;
    } else {
        succeeded = 0;
    }
    return succeeded;
}

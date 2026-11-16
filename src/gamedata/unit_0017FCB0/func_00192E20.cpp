/* Returns the current RacePhotoMode instance, or 0: takes the holder returned by func_00192E10 and downcasts the RacePS2Base inside it to
 * RacePhotoMode (GCC 2.96 dynamic_cast shape, inferred from the __tf arguments). */
struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct Node {
    int unk0;
    char pad[0x60];
    Unk64 *unk64;
};

extern char RacePhotoMode__tf[];
extern char RacePS2Base__tf[];

extern Node **func_00192E10(void);
extern int __dynamic_cast_2(int, void *, int, void *, void *, void *);

int func_00192E20(void)
{
    Node **holder;
    Node *node;
    int result;
    int casted;

    holder = func_00192E10();
    result = 0;
    if (holder != 0) {
        node = *holder;
        if (node != 0) {
            Unk64 *u = node->unk64;
            casted = __dynamic_cast_2(u->unk4, RacePhotoMode__tf, 0,
                                    (char *)node + u->unk0,
                                    RacePS2Base__tf, node);
        } else {
            casted = 0;
        }
        result = casted;
    }
    return result;
}

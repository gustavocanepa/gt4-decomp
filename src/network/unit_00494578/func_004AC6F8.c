/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x10];
    char lock[0x98];
    char listA8[8];
} Manager_004AC6F8;

typedef struct {
    char pad0[0x3C];
    char node[0xC];
} Item_004AC6F8;

extern Manager_004AC6F8 D_0084B480;

void func_004AC618(Item_004AC6F8 *item);
void func_00576788(void *lock);
void func_005767C0(void *lock);
void func_0057CB00(void *list, void *node);

void func_004AC6F8(Item_004AC6F8 *item) {
    Manager_004AC6F8 *m;
    func_004AC618(item);
    m = &D_0084B480;
    func_00576788(m->lock);
    func_0057CB00(m->listA8, item->node);
    func_005767C0(m->lock);
}

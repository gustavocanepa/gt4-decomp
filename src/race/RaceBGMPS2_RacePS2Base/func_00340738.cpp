/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 {
    float x, y, z;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 position(float t);
};

struct Item {
    Node *node;
};

struct Entry {
    Item *item;
    float depth;
};

struct Sorter {
    Entry entries[6];
    int count;
    Vec3 *dir;
    float time;
};

extern "C" void func_00340738(Sorter *self, Item *item)
{
    Vec3 p = item->node->position(self->time);
    Entry *e = &self->entries[self->count++];
    float d = p.x * self->dir->x + p.y * self->dir->y + p.z * self->dir->z;
    e->item = item;
    e->depth = d;
}

/* compiler: ee-gcc2.96-stl */
/* One step of a sweep-line polygon triangulator (names provisional, inferred from the code and its
   callees): takes the next edge event from the priority queue and attaches it to the monotone region
   it continues, closes or splits, emitting triangles. Regions live in a fixed-size list; each holds
   the reflex chain as a stack of up to 48 points.
   The queue pop is SGI's real pop_heap; __adjust_heap is out of line, see config/stl_symbols.txt. */
#include <stl_algobase.h>
#include <stl_heap.h>

struct Point { float x, y; };

/* An edge of the polygon, from a to b; flag tells which side of its region it bounds. */
struct SweepEdge2 { Point *a, *b; int flag; };
struct SweepEdge2Compare { char state; bool operator()(const SweepEdge2 &, const SweepEdge2 &) const; };

struct TriangleOutput;
struct Region;
extern "C" void func_00608598(Region *region, TriangleOutput *out, Point *p, int side);

static inline bool samePoint(const Point *a, const Point *b) { return a->x == b->x && a->y == b->y; }

struct Region {
    Point *chain[48];
    int chainCount, chainSide;
    SweepEdge2 left, right;
    int leftOpen, rightOpen;
    Region *next, *prev;
    bool closed() const { return samePoint(left.b, right.b); }
    void close(TriangleOutput *out) { const SweepEdge2 &e = left; func_00608598(this, out, e.b, 1); }
    void setLeft(const SweepEdge2 &e) { left = e; leftOpen = 0; }
    void setRight(const SweepEdge2 &e) { right = e; rightOpen = 0; }
};

struct RegionIterData { void *owner; Region *n; };
struct RegionIter : RegionIterData {
    RegionIter() { n = 0; }
    RegionIter(Region *p) { n = p; }
    RegionIter(const RegionIter &o) : RegionIterData(o) {}
    RegionIter &operator--() { n = n->prev; return *this; }
    RegionIter &operator++() { n = n->next; return *this; }
    Region *operator->() const { return n; }
    Region &operator*() const { return *n; }
    bool operator!=(const RegionIter &o) const { return n != o.n; }
};

struct RegionList;
extern "C" RegionIter func_006088C0(RegionList *list, RegionIter pos);
extern "C" void func_00608950(RegionList *list, RegionIter pos);
struct RegionList {
    char pool[0x1E04];
    Region *tail;
    int count;
    RegionIter begin() { return RegionIter(tail->next); }
    RegionIter end() { return RegionIter(tail); }
    Region &back() { return *(--end()).n; }
    void push_back() { func_00608950(this, end()); }
    void pop_back() { func_006088C0(this, --end()); }
};

struct Triangulator {
    SweepEdge2 events[1024];
    int eventCount;
    SweepEdge2Compare compare;
    RegionList regions;
};

/* Queues the extra event that splits at a point below the current one. */
extern "C" void func_00608488(Triangulator *self, Point *a, Point *b);
/* The region whose left edge is nearest to the point's left at its height. */
extern "C" RegionIter func_006087A0(Triangulator *self, const Point *p);
extern "C" void func_006078E8(Triangulator *self);

static inline void popEvent(Triangulator *self) {
    pop_heap(self->events, self->events + self->eventCount, self->compare);
    func_006078E8(self);
}

extern "C" int func_00607B98(Triangulator *self, TriangleOutput *out) {
    const SweepEdge2 &top = self->events[0];
    SweepEdge2 *otherEdge;
    RegionList *list = &self->regions;
    RegionIter end = list->end();
    RegionIter cur;
    cur = list->begin();
    for (; cur != end; ++cur) {
        if (top.flag == 0 && samePoint(cur->left.b, top.a)) {
            otherEdge = &cur->right;
            if (cur->right.b->y < top.a->y) goto splitAtOther;
            func_00608598(&*cur, out, top.a, 1);
            cur->setLeft(top);
            break;
        } else if (top.flag != 0 && samePoint(cur->right.b, top.a)) {
            otherEdge = &cur->left;
            if (cur->left.b->y < top.a->y) goto splitAtOther;
            func_00608598(&*cur, out, top.a, 0);
            cur->setRight(top);
            break;
        }
    }
    if (cur != end) goto continued;

    if (top.flag != 0) {
        /* A point inside an open region: split it in two, or fail when no region contains it. */
        RegionIter found = func_006087A0(self, top.a);
        if (found.n != end.n) {
            SweepEdge2 *right = &found->right;
            SweepEdge2 *left = &found->left;
            if (found->right.b->y < top.a->y) { func_00608488(self, right->b, top.a); goto done; }
            if (found->left.b->y < top.a->y) { func_00608488(self, left->b, top.a); goto done; }
            SweepEdge2 saved;
            if (right->a->y > left->a->y) {
                saved = *right;
                SweepEdge2 e;
                e.a = saved.a; e.b = top.a; e.flag = 1;
                found->setRight(e);
                list->push_back();
                Region *added = &list->back();
                func_00608598(added, out, e.a, 1);
                e.flag = 0;
                added->setLeft(e);
                added->setRight(saved);
            } else {
                saved = *left;
                SweepEdge2 e;
                e.a = saved.a; e.b = top.a; e.flag = 0;
                found->setLeft(e);
                list->push_back();
                Region *added = &list->back();
                func_00608598(added, out, e.a, 0);
                e.flag = 1;
                added->setRight(e);
                added->setLeft(saved);
            }
            return 1;
        }
        return 0;
    }

    {
        /* A start vertex: open a new region with this event and the next one. */
        list->push_back();
        Region *added = &list->back();
        func_00608598(added, out, top.a, 1);
        added->setLeft(self->events[0]);
        popEvent(self);
        if (self->eventCount == 0) return 1;
        added->setRight(self->events[0]);
        popEvent(self);
        if (added->closed()) {
            added->close(out);
            list->pop_back();
            return 1;
        }
    }
    return 1;

splitAtOther:
    func_00608488(self, otherEdge->b, top.a);
    goto done;

continued:
    popEvent(self);
    if (cur->closed()) {
        cur->close(out);
        func_006088C0(list, cur);
    }
done:
    return 1;
}

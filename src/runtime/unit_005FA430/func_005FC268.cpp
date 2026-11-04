/* compiler: ee-gcc2.96-stl */
/* One step of a sweep-line polygon triangulator (names provisional, inferred from the code and its
   callees): takes the next edge event from the priority queue and attaches it to the monotone region
   it continues, closes or splits, emitting triangles. Regions live in a fixed-size list; each holds
   the reflex chain as a stack of up to 32 points.
   The queue pop is SGI's real pop_heap; __adjust_heap is out of line, see config/stl_symbols.txt. */
#include <stl_algobase.h>
#include <stl_heap.h>

struct Point { float x, y; };

/* An edge of the polygon, from a to b; flag tells which side of its region it bounds. */
struct SweepEdge { Point *a, *b; int flag; };
struct SweepEdgeCompare { char state; bool operator()(const SweepEdge &, const SweepEdge &) const; };

struct TriangleOutput;
struct Region;
extern "C" void func_005FCD30(Region *region, TriangleOutput *out, Point *p, int side);

static inline bool samePoint(const Point *a, const Point *b) { return a->x == b->x && a->y == b->y; }

struct Region {
    Point *chain[32];
    int chainCount, chainSide;
    SweepEdge left, right;
    int leftOpen, rightOpen;
    Region *next, *prev;
    bool closed() const { return samePoint(left.b, right.b); }
    void close(TriangleOutput *out) { const SweepEdge &e = left; func_005FCD30(this, out, e.b, 1); }
    void setLeft(const SweepEdge &e) { left = e; leftOpen = 0; }
    void setRight(const SweepEdge &e) { right = e; rightOpen = 0; }
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
extern "C" RegionIter func_005FD0D8(RegionList *list, RegionIter pos);
extern "C" void func_005FD168(RegionList *list, RegionIter pos);
struct RegionList {
    char pool[0x584];
    Region *tail;
    int count;
    RegionIter begin() { return RegionIter(tail->next); }
    RegionIter end() { return RegionIter(tail); }
    Region &back() { return *(--end()).n; }
    void push_back() { func_005FD168(this, end()); }
    void pop_back() { func_005FD0D8(this, --end()); }
};

struct Triangulator {
    SweepEdge events[1024];
    int eventCount;
    SweepEdgeCompare compare;
    RegionList regions;
};

/* Queues the extra event that splits at a point below the current one. */
extern "C" void func_005FCC20(Triangulator *self, Point *a, Point *b);
/* The region whose left edge is nearest to the point's left at its height. */
extern "C" RegionIter func_005FCFB8(Triangulator *self, const Point *p);
extern "C" void func_005FD1B8(Triangulator *self);

static inline void popEvent(Triangulator *self) {
    pop_heap(self->events, self->events + self->eventCount, self->compare);
    func_005FD1B8(self);
}

extern "C" int func_005FC268(Triangulator *self, TriangleOutput *out) {
    const SweepEdge &top = self->events[0];
    SweepEdge *otherEdge;
    RegionList *list = &self->regions;
    RegionIter end = list->end();
    RegionIter cur;
    cur = list->begin();
    for (; cur != end; ++cur) {
        if (top.flag == 0 && samePoint(cur->left.b, top.a)) {
            otherEdge = &cur->right;
            if (cur->right.b->y < top.a->y) goto splitAtOther;
            func_005FCD30(&*cur, out, top.a, 1);
            cur->setLeft(top);
            break;
        } else if (top.flag != 0 && samePoint(cur->right.b, top.a)) {
            otherEdge = &cur->left;
            if (cur->left.b->y < top.a->y) goto splitAtOther;
            func_005FCD30(&*cur, out, top.a, 0);
            cur->setRight(top);
            break;
        }
    }
    if (cur != end) goto continued;

    if (top.flag != 0) {
        /* A point inside an open region: split it in two, or fail when no region contains it. */
        RegionIter found = func_005FCFB8(self, top.a);
        if (found.n != end.n) {
            SweepEdge *right = &found->right;
            SweepEdge *left = &found->left;
            if (found->right.b->y < top.a->y) { func_005FCC20(self, right->b, top.a); goto done; }
            if (found->left.b->y < top.a->y) { func_005FCC20(self, left->b, top.a); goto done; }
            SweepEdge saved;
            if (right->a->y > left->a->y) {
                saved = *right;
                SweepEdge e;
                e.a = saved.a; e.b = top.a; e.flag = 1;
                found->setRight(e);
                list->push_back();
                Region *added = &list->back();
                func_005FCD30(added, out, e.a, 1);
                e.flag = 0;
                added->setLeft(e);
                added->setRight(saved);
            } else {
                saved = *left;
                SweepEdge e;
                e.a = saved.a; e.b = top.a; e.flag = 0;
                found->setLeft(e);
                list->push_back();
                Region *added = &list->back();
                func_005FCD30(added, out, e.a, 0);
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
        func_005FCD30(added, out, top.a, 1);
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
    func_005FCC20(self, otherEdge->b, top.a);
    goto done;

continued:
    popEvent(self);
    if (cur->closed()) {
        cur->close(out);
        func_005FD0D8(list, cur);
    }
done:
    return 1;
}

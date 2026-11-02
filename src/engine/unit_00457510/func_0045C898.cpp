/* Rebuilds an object's 2D bounding box from the two corner points a and b, ordered by the
   sign of the velocity on each axis and widened by the margin, then stores its size.
   The margin is read at every use: a cached local changes the schedule. */
struct Vec2 { float x, y; };
struct Box { Vec2 min; Vec2 max; Vec2 size; };
struct T {
    char p0[0x388]; float margin; char p38c[4];
    Vec2 a; char p398[0x3A4 - 0x398]; Vec2 b; char p3ac[0x3B4 - 0x3AC]; Vec2 v;
    char p3bc[0x3D4 - 0x3BC]; Box box;
};
extern "C" void func_0045C898(T *t) {
    if (t->v.x < 0.0f) {
        t->box.min.x = t->b.x - t->margin;
        t->box.max.x = t->a.x + t->margin;
    } else {
        t->box.min.x = t->a.x - t->margin;
        t->box.max.x = t->b.x + t->margin;
    }
    if (t->v.y < 0.0f) {
        t->box.min.y = t->b.y - t->margin;
        t->box.max.y = t->a.y + t->margin;
    } else {
        t->box.min.y = t->a.y - t->margin;
        t->box.max.y = t->b.y + t->margin;
    }
    t->box.size.x = t->box.max.x - t->box.min.x;
    t->box.size.y = t->box.max.y - t->box.min.y;
}

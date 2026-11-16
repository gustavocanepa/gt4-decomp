/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct Entry {
    short delta;
    short index;
    void *fn;
};

struct Obj {
    char pad0[4];
    Entry *vtable;
};

struct V2 {
    float x, y;
};

struct Face {
    char pad0[0xC8];
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned f2 : 1;
    unsigned pad3 : 29;
    V2 a;
    V2 b;
    V2 c;
    V2 d;
    u8 r, g, bl, al;
};

extern char mImageFace__tf[];
extern char hObject__tf[];
extern "C" void mColorFace__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void *func_002A35F0(void *);
extern "C" void func_002A35F8(void *, void *);

extern "C" void mImageFace__deepCopy(Face *self, void *src) {
    Face *copy = 0;
    mColorFace__deepCopy(self, src);
    if (src != 0) {
        Entry *e = ((Obj *)src)->vtable;
        copy = (Face *)__dynamic_cast_2(e->fn, mImageFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (copy != 0) {
        func_002A35F8(self, func_002A35F0(copy));
        self->f0 = copy->f0;
        self->f1 = copy->f1;
        self->f2 = copy->f2;
        V2 *da = &self->a;
        V2 *db = &self->b;
        V2 *dc = &self->c;
        V2 *dd = &self->d;
        da->x = copy->a.x;
        da->y = copy->a.y;
        db->x = copy->b.x;
        db->y = copy->b.y;
        dc->x = copy->c.x;
        dc->y = copy->c.y;
        dd->x = copy->d.x;
        dd->y = copy->d.y;
        self->r = copy->r;
        self->g = copy->g;
        self->bl = copy->bl;
        self->al = copy->al;
    }
}

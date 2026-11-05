/* compiler: ee-gcc2.96-stl */
/* Builds one image from a grid of planes (names provisional, inferred from the code): each output
   pixel takes its luma from a Y plane and its chroma from the low-resolution RGB source image, the last
   grid cell keeping the source pixel unchanged. The planes are then freed and the result
   swapped into the source image. The conversion uses the JPEG YCbCr coefficients. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

template <class T>
class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() throw() {}
    PlainAlloc40(const PlainAlloc40 &) throw() {}
    template <class U> PlainAlloc40(const PlainAlloc40<U> &) throw() {}
    ~PlainAlloc40() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef signed char Elem;

typedef vector<Elem, PlainAlloc40<Elem> > Vec;


extern "C" unsigned int func_00575D00(void);
extern "C" void func_005CD968(Vec *);
/* Note that the constructor's setup reads the fields before setting them: bytes() is computed
   from uninitialised values, as in the original, so the old size is effectively arbitrary. */
struct Image {
    Vec pixels;
    int width, height, depth, layers, bytesPerPixel;
    float scale;
    Image(int w, int h, int d, int l, int b) { setup(w, h, d, l, b); }
    void clear() { func_005CD968(&pixels); width = 0; height = 0; }
    unsigned int pitch() const { return width * bytesPerPixel; }
    unsigned int bytes() const { return pitch() * height * (depth * layers); }
    void setup(int w, int h, int d, int l, int b) {
        unsigned int old = bytes();
        width = w; height = h; depth = d; layers = l; bytesPerPixel = b;
        unsigned int size = bytes();
        unsigned int avail = func_00575D00();
        if (size != old) {
            func_005CD968(&pixels);
            if (avail >= size) pixels.resize(size);
        }
    }
};
/* The owner of the planes; its size fields describe one plane. */
struct Mosaic {
    int pad0;
    int width, height, columns, rows;
    float scale;
    int pad18;
    Image chroma;
    char pad44[0x10];
    Image planes[1];
};
/* Nonzero selects the plain path. */
extern "C" int D_006201A8;
extern "C" void func_003355F0(Mosaic *);
extern "C" void func_00331520(Image *, int, int);
template <class T> inline void swapValue(T &a, T &b) { T t = a; a = b; b = t; }
/* Clamps below at zero; min() above takes the result by reference. */
static inline const int &above(const int &v) { return max(0, v); }
extern "C" void func_00334158(Mosaic *self) {
    if (D_006201A8) { func_003355F0(self); return; }
    int count = self->columns * self->rows;
    float scale = self->scale;
    Image tmp(self->width * self->columns, self->height * self->rows, 1, 1, 3);
    tmp.scale = scale;
    Image *chroma = &self->chroma; /* the low-resolution RGB source */
    unsigned char *src = (unsigned char *)chroma->pixels.begin();
    for (int k = 0; k < self->height; k++) {
        for (int j = 0; j < self->width; j++) {
            int red = src[0], green = src[1], blue = src[2];
            src += 3;
            float fr = red, fg = green, fb = blue;
            float cr = fr * 0.5f - fg * 0x1.AD0E56p-2f - fb * 0x1.4BC6A6p-4f;
            float cb = fr * -0x1.5A1CACp-3f - fg * 0x1.53F7CEp-2f + fb * 0.5f;
            for (int row = 0; row < self->rows; row++) {
                for (int col = 0; col < self->columns; col++) {
                    int index = row * self->columns + col;
                    signed char *dst = tmp.pixels.begin() + tmp.width * tmp.bytesPerPixel * (k * self->rows + row) + (j * self->columns + col) * tmp.bytesPerPixel;
                    if (index == count - 1) {
                        dst[0] = red; dst[1] = green; dst[2] = blue;
                    } else {
                        Image *p = &self->planes[index];
                        float y = *(unsigned char *)(p->width * p->bytesPerPixel * k + j * p->bytesPerPixel + (int)p->pixels.begin());
                        int r = (int)(y + cr * 0x1.66E978p+0f);
                        int g = (int)((double)(y - cr * 0x1.6D9168p-1f) - (double)cb * 0.344);
                        int b = (int)(y + cb * 0x1.C5A1CAp+0f);
                        dst[0] = min(255, above(r));
                        dst[1] = min(255, above(g));
                        dst[2] = min(255, above(b));
                    }
                }
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        self->planes[i].clear();
    }
    tmp.pixels.swap(self->chroma.pixels);
    swapValue(tmp.width, self->chroma.width);
    swapValue(tmp.height, self->chroma.height);
    swapValue(tmp.depth, self->chroma.depth);
    swapValue(tmp.layers, self->chroma.layers);
    swapValue(tmp.bytesPerPixel, self->chroma.bytesPerPixel);
    swapValue(tmp.scale, self->chroma.scale);
    func_00331520(chroma, self->columns, self->rows);
}

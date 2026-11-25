/* compiler: ee-gcc2.96-no-strict-aliasing */
// Provisional layouts, inferred from this routine and its course-map caller.
// The texture and view are borrowed; the vertex/UV arrays live only for this draw.
struct Point2 {
    float x, y;
    float &X() { return x; } float &Y() { return y; }
    Point2 &operator=(const Point2 &other) { x = other.x; y = other.y; return *this; }
};
struct TextureBuffer { char unknown[0x20]; unsigned long region; };
struct Texture { char unknown[0x18]; TextureBuffer *buffer; };
struct View;
struct CourseMapFace {
    char unknown[0xC4];
    int enabled;
    View *view;
    Texture *texture;
    char unknownD0[0x10];
    float mapX, mapY;
};
struct DrawEntry { short adjustment, index; void (*call)(void *, int, Point2 *, Point2 *, int); };
struct Renderer { int unknown; DrawEntry *vtable; };
extern "C" int func_00499728(Texture *);
extern "C" void func_0049CC48(TextureBuffer *);
extern "C" void func_003BEBA0(View *, float *, float *, float, float);
extern "C" void func_004A1638(unsigned);
extern "C" void func_004A4810(int, unsigned, unsigned);
extern "C" void func_004A4550(unsigned, int);
extern "C" void func_004AA1D8(float, float, float, float);
static inline int leadingSignBits(int value) {
    int result;
    __asm__ volatile("plzcw %0, %1" : "=r"(result) : "r"(value));
    return result;
}
// Normalize against the power-of-two texture allocation, not the visible extent.
static inline float textureExtent(unsigned size) {
    float numerator = (float)size;
    unsigned powerOfTwo = 1U << ((leadingSignBits(size - 1) & 31) ^ 31);
    return numerator / (float)powerOfTwo;
}
extern "C" void func_00129010(CourseMapFace *self, Renderer *renderer, float offsetX, float offsetY) {
    Point2 origin;
    Point2 vertices[4];
    Point2 texcoords[4];
    if (self->enabled && self->texture) {
        TextureBuffer *buffer = self->texture->buffer;
        func_00499728(self->texture);
        func_0049CC48(buffer);
        int width = ((buffer->region >> 14) & 0x3FF) + 1;
        int height = ((buffer->region >> 34) & 0x3FF) + 1;
        func_003BEBA0(self->view, &origin.x, &origin.y, self->mapX, self->mapY);
        // Center the marker at the transformed map position; half sizes truncate.
        origin.x += offsetX - (float)(width / 2);
        origin.y += offsetY - (float)(height / 2);
        float right = origin.x + (float)width;
        float bottom = origin.y + (float)height;
        vertices[0] = origin;
        vertices[1].X() = right; vertices[1].Y() = origin.y;
        vertices[2].X() = origin.x; vertices[2].Y() = bottom;
        vertices[3].X() = right; vertices[3].Y() = bottom;
        float u = textureExtent(width);
        float v = textureExtent(height);
        texcoords[0].X() = 0.0f; texcoords[0].Y() = 0.0f;
        texcoords[1].X() = u; texcoords[1].Y() = 0.0f;
        texcoords[2].X() = 0.0f; texcoords[2].Y() = v;
        texcoords[3].X() = u; texcoords[3].Y() = v;
        func_004A1638(2);
        func_004A4810(0, 0, width - 1);
        func_004A4810(1, 0, height - 1);
        func_004A4550(4, 2);
        func_004A4550(5, 2);
        func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
        // Old GCC virtual entry: adjust this, then submit the four stack vertices.
        DrawEntry *entry = renderer->vtable + 54;
        entry->call((char *)renderer + entry->adjustment, 4, vertices, texcoords, 0);
    }
}

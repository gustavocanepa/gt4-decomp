/* compiler: ee-gcc2.96-no-strict-aliasing */
// Provisional packet-builder layout shared with func_00494A28. Member names
// describe observed behavior; they are not recovered original identifiers.
struct Packer {
    int *head;
    int *out;
    int packets;
    float pos[64][3];
    float norm[64][3];
    float uv[64][2];
    int color[64];
    int runs[21];
    int attr, prim, flags, count, pending, nruns, dirty, total;
    int unk980, enabled, words;
};

extern "C" void func_00494A28(Packer *);
extern "C" void func_00494780(Packer *, float *, float *, float *, int *);

// A flush resets the counters but leaves the attribute arrays intact. Carry the
// last two vertices into the next batch to preserve strip continuity. Source
// pointers are borrowed and only select which attributes are present; no pointer
// is retained. Keeping both submissions in one indexed inline helper also
// reproduces the original compiler's conditional-pointer instruction sequence.
static inline void carryBoundaryPair(Packer *p, int index, float *position,
                                    float *normal, float *uv, int *color) {
    func_00494780(p, position ? p->pos[index] : 0,
                 normal ? p->norm[index] : 0,
                 uv ? p->uv[index] : 0,
                 color ? &p->color[index] : 0);
    func_00494780(p, position ? p->pos[index + 1] : 0,
                 normal ? p->norm[index + 1] : 0,
                 uv ? p->uv[index + 1] : 0,
                 color ? &p->color[index + 1] : 0);
}

// Append one vertex, copying each supplied attribute into the packer's storage.
extern "C" void func_00494780(Packer *p, float *position, float *normal,
                              float *uv, int *color) {
    int mask;
    if (position) mask = 1;
    else mask = 0;
    if (normal) mask |= 2;
    if (uv) mask |= 4;
    if (color) mask |= 8;

    // Each packet has one attribute format, so a format change ends the batch.
    if (p->flags != mask) {
        func_00494A28(p);
        p->flags = mask;
    }
    if (position) {
        p->pos[p->count][0] = position[0];
        p->pos[p->count][1] = position[1];
        p->pos[p->count][2] = position[2];
    }
    if (normal) {
        p->norm[p->count][0] = normal[0];
        p->norm[p->count][1] = normal[1];
        p->norm[p->count][2] = normal[2];
    }
    if (uv) {
        p->uv[p->count][0] = uv[0];
        p->uv[p->count][1] = uv[1];
    }
    if (color) p->color[p->count] = *color;

    p->pending++;
    if (++p->count >= 64) {
        func_00494A28(p);
        carryBoundaryPair(p, 62, position, normal, uv, color);
    }
}

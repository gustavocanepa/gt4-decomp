typedef int s32;

struct Self { char pad[0x14]; s32 m14; char pad2[0x1C]; s32 m34; };
struct Best { Self *obj; s32 key; s32 sub; };

extern "C" void func_0055D070(Self *self, Best *b) {
    s32 key = self->m34;
    s32 sub = self->m14;
    if (key < b->key || (key == b->key && sub >= b->sub)) {
        b->obj = self;
        b->key = key;
        b->sub = sub;
    }
}

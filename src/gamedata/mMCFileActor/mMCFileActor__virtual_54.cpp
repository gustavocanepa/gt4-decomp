struct Ventry { short delta; short pad; float (*fn)(void *); };
struct Root { int unk0; Ventry *vt; };
struct Texture { int words[15]; };
struct Widget;
struct Actor {
    char pad0[0x14];
    Root *root;
    char pad18[0x28];
    Texture texture;
    Widget *item;
};
struct Buffer { char pad[0x28]; int id; char pad2[0x10]; };
struct Buffers { Buffer buf[2]; int current; };
extern Buffers D_0061850C;
extern "C" {
void func_004A5400(void);
void func_004A1638(int);
void func_004A2808(int, float);
void func_004AA1D8(float, float, float, float);
float mWidget__getWindowX(Widget *);
float mWidget__getWindowY(Widget *);
float mWidget__getWindowW(Widget *);
float mWidget__getWindowH(Widget *);
float func_00173708(float);
float func_00173710(float);
void func_004A5688(void);
void func_00105728(Texture *);
void func_001055C0(Texture *);
int func_004A2A10(int);
void func_004A6668(float, float, float, float, float, float, float, float);
}
inline float opacity(Root *o) { Ventry *e = o->vt + 0x1C0 / 8; return e->fn((char *)o + e->delta); }

/* The texture address is taken where it is used: the scheduler hoists that one add above the
   first call by itself. A local computed up here would be issued after the call instead. */
extern "C" void mMCFileActor__virtual_54(Actor *self) {
    float one = 1.0f;
    Widget *item = self->item;
    func_004A5400();
    float alpha = opacity(self->root);
    func_004A1638(6);
    func_004A2808(0x64, alpha);
    func_004AA1D8(one, one, one, one);
    float x = func_00173708(mWidget__getWindowX(item));
    float y = func_00173710(mWidget__getWindowY(item));
    float w = func_00173708(mWidget__getWindowW(item));
    float h = func_00173710(mWidget__getWindowH(item));
    if (x < 0.0f) x = 0.0f;
    if (y < 0.0f) y = 0.0f;
    func_004A5688();
    func_00105728(&self->texture);
    y *= 0.5f;
    h *= 0.5f;
    func_004A2A10(0);
    func_004A6668(x, y, x + w, y + h, x, y, x + w, y + h);
    func_004A2A10(D_0061850C.buf[D_0061850C.current].id);
    func_001055C0(&self->texture);
    func_004A2808(0x44, one);
}

typedef float f32;
struct V2 {
    f32 x, y;
    void set(f32 a, f32 b) { x = a; y = b; }
};
extern "C" void func_003D34A8(V2 *arg0) {
    for (int i = 0; i < 4; i++) {
        arg0->set(0.0f, 0.0f);
        arg0++;
    }
}

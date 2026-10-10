typedef unsigned int u32;

/* The base class RaceDisplayObjectBase, named after its constructor (RaceDisplayObjectBase__structor_0) so that
   __13func_003AEBA8 resolves. The vptr sits after its 0x14 bytes of data. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

/* A real C++ constructor: the compiler's own vptr store (_vt$16RaceTexturePanel) gives the
   original's scheduling (constant before the vtable address, ld $s0 before ld $ra). */
struct RaceTexturePanel : RaceDisplayObjectBase__structor_0 {
    u32 color;
    RaceTexturePanel();
    virtual ~RaceTexturePanel();
};

RaceTexturePanel::RaceTexturePanel() : color(0x80FFFFFF) {
}

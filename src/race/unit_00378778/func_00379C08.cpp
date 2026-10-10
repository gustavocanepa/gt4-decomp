typedef int s32;
typedef float f32;
struct Root { virtual ~Root(); };
struct func_00378AE0 : Root {
    char pad[0x17C];
    func_00378AE0();
    virtual ~func_00378AE0();
};
struct D_0067A5D8 : func_00378AE0 {
    s32 m180;
    f32 m184;
    s32 m188;
    s32 m18C;
    D_0067A5D8();
    virtual ~D_0067A5D8();
};
D_0067A5D8::D_0067A5D8() {
    m18C = 0;
    m180 = 0;
    m184 = 90.0f;
}

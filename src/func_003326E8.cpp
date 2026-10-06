struct S { float f0; char pad[0x10]; float f14; char pad2[0x20]; };

extern void func_004A7550(S *);
extern void func_004A7890(float, float, float);

void func_003326E8(float x)
{
    S s;
    func_004A7550(&s);
    float v = s.f14 / s.f0;
    v = v / x;
    func_004A7890(v, 1.0f, 1.0f);
}

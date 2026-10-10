struct Obj;
extern "C" float func_00355D80(Obj *o);
extern "C" void func_00355E40(Obj *o, float d);
extern "C" void func_00355D60(Obj *o, float v);

extern "C" float func_00355F08(Obj *o, float x) {
    float have = func_00355D80(o);
    func_00355E40(o, -x);
    if (have < x) {
        float d = x - have;
        have = 0.0f;
        x -= d;
    } else {
        have -= x;
    }
    func_00355D60(o, have);
    return x;
}

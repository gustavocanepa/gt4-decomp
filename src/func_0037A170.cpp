extern "C" float func_0057D380(float);

struct Camera {
    char pad0[0xC];
    float fov;
};

extern "C" void func_00378F18(Camera *self, float x, float y, float z);

extern "C" void func_0037A170(Camera *self)
{
    float t = func_0057D380(self->fov * 0.5f * 0.017453292f);
    func_00378F18(self, 1.0f, 1.0f, 1.0f / t);
}

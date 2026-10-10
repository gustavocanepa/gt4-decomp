extern "C" int func_0035A458(void *car);
extern "C" void func_00402170(void *self, float x, float y, float z);
extern "C" void func_00403EF0(void *self, float x, float y, float z);

extern "C" void func_003869B0(void *self, void *car, float x, float y, float z) {
    switch (func_0035A458(car)) {
    case 0:
        break;
    case 1:
        return func_00402170(self, x, y, z);
    }
    return func_00403EF0(self, x, y, z);
}

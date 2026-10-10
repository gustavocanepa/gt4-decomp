typedef int s32;

struct Obj;

extern "C" void *func_00389628(Obj *self, s32 id);
extern "C" void *func_003EA8C8(Obj *self, s32 id);
extern "C" void *func_003EA908(Obj *self, s32 id);

extern "C" void *func_003EA970(Obj *self, s32 id) {
    switch (id) {
    case 0x100:
        return func_003EA8C8(self, id);
    case 1:
        return func_003EA908(self, id);
    default:
        return func_00389628(self, id);
    }
}

struct Item { char pad0[0x10]; int handle; char pad14[0x20 - 0x14]; short anim; char pad22[0xA0 - 0x22]; };
extern "C" Item *D_006D6054;
extern "C" void ModelSet2___render(int handle, int anim, int arg);
extern "C" void func_003E53B8(int idx, int alt) {
    Item *items = D_006D6054;
    Item *it = &items[idx];
    int anim = it->anim * 2;
    if (alt) anim++;
    ModelSet2___render(items->handle, anim, 0);
}

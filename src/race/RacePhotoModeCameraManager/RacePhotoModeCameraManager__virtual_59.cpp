typedef char Obj;

extern "C" {
void func_00378778(Obj *self, int a);
void func_00378958(Obj *self, int a);
void func_003789A0(Obj *self, int a);
void func_003789E8(Obj *self, int a);
void func_00378A40(Obj *self, int a);
void func_00378A98(Obj *self, int a);
void func_003FAD18(void *p);
void func_0036FE18(void *a, void *b);
void func_003848D8(void *cam, void *b);
void func_003844D0(void *cam, void *b);
void func_00378F28(void *cam, int a, void *b, void *c, void *d);
void func_0036FE40(void *a, void *cam, void *d);
}

extern "C" void RacePhotoModeCameraManager__virtual_59(Obj *self, int a, int unused, int *mode) {
    void *s4 = self + 0xDD0;
    void *s5 = self + 0xE28;
    *(int *)(self + 0xF34) = *mode;
    void *s6 = self + 0xD00;
    switch (*mode) {
    case 1:
    case 2:
        func_00378778(self, a);
        break;
    case 6:
        func_00378958(self, a);
        break;
    case 7:
        func_003789A0(self, a);
        break;
    case 3:
        func_003789E8(self, a);
        break;
    case 4:
        func_00378A40(self, a);
        break;
    case 5:
        func_00378A98(self, a);
        break;
    default:
        func_003FAD18(s4);
        func_0036FE18(s5, s4);
        break;
    }
    void *cam = *(void **)(self + 0xC44);
    void *s1 = self + 0x9C0;
    func_003848D8(cam, s5);
    func_00378F28(cam, a, s4, s6, s1);
    void *cam2 = *(void **)(self + 0xC40);
    func_003844D0(cam2, s5);
    func_00378F28(cam2, a, s4, s6, s1);
    func_0036FE40(s5, *(void **)(self + 0xC40), s1);
}

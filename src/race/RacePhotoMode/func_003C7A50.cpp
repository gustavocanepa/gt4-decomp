struct Image {
    int unk0;
    int unk4;
    int width;
};

struct Screen {
    char pad[0x1E660];
    float scaleX;
    float scaleY;
};

extern "C" int func_00105818(Image *img);
extern "C" void func_003C7AE0(Screen *s, Image *img, int w, int h);

extern "C" void func_003C7A50(Screen *s, Image *img) {
    int w = (int)(s->scaleX * (float)img->width);
    int h = (int)(s->scaleY * (float)func_00105818(img));
    func_003C7AE0(s, img, w, h);
}

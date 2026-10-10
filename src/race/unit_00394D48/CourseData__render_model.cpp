struct Ref {
    int id;
};

extern "C" Ref *VisionList__getVoronoi(void *p);
extern "C" void func_003971F0(void *self, void *obj, int id);

extern "C" void CourseData__render_model(void *self, void *obj, void *p) {
    if (obj == 0)
        return;
    if (p != 0)
        func_003971F0(self, obj, VisionList__getVoronoi(p)->id);
    else
        func_003971F0(self, obj, 0);
}

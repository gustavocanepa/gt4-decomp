typedef float f32;

extern "C" f32 D_006214DC;
extern "C" void CourseData__evalVMMethods(void);

extern "C" void CourseData__render_course_for_renderer(f32 fparg0) {
    D_006214DC = fparg0;
    CourseData__evalVMMethods();
}

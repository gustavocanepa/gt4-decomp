struct VEntry { short delta; short index; void *pfn; };
struct hObject { int pad; VEntry *vptr; };

extern "C" char mPhotoRenderFace__tf[];
extern "C" char hObject__tf[];
/* __dynamic_cast (old ABI): from, to, require_public, address, sub, subptr */
extern "C" void *func_005C0FC8(void *from, void *to, int require_public, void *address, void *sub, void *subptr);
extern "C" void mSceneViewFace__virtual_08(void *self, hObject *obj);

/* The parent's handler, then dynamic_cast<mPhotoRenderFace *>(obj) with the result unused. */
extern "C" void mPhotoRenderFace__virtual_08(void *self, hObject *obj)
{
    mSceneViewFace__virtual_08(self, obj);
    if (obj)
        func_005C0FC8(obj->vptr[0].pfn, mPhotoRenderFace__tf, 0, (char *)obj + obj->vptr[0].delta, hObject__tf, obj);
}

typedef float f32;

extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatOffsetZ(void *p);

extern "C" f32 SpecialCarGeometry__GetSeatPosition_Z(void) {
    void *p = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
    if (p) {
        return DRIVERSUPPORT_NAME__MotoristDynamicParameter__getSeatOffsetZ(p) + 0.1f;
    }
    return 0.1f;
}

extern "C" float func_0036CB90(float);

extern "C" float func_0036CC40(float a, float b)
{
    float d = func_0036CB90(a) - func_0036CB90(b);
    if (d >= 3.14159274101257324f) d -= 6.28318548202514648f;
    else if (d < -3.14159274101257324f) d += 6.28318548202514648f;
    return d;
}

#include <math.h>
#include "Vector3D.h"

Vector3D::Vector3D(const Point3D& p0, const Point3D& p1)
{
    m_radiusVect = std::make_shared<Point3D>(p1);
    *m_radiusVect -= p0;
}

Vector3D::Vector3D(const Vector3D& v1)
    : m_radiusVect(v1.m_radiusVect)
{
}

double operator* (const Vector3D& v1, const Vector3D& v2)
{
    double x1 = v1.m_radiusVect->X();
    double x2 = v2.m_radiusVect->X();
    double y1 = v1.m_radiusVect->Y();
    double y2 = v2.m_radiusVect->Y();
    double z1 = v1.m_radiusVect->Z();
    double z2 = v2.m_radiusVect->Z();
    double res = x1*x2+y1*y2+z1*z2;
    return res;
}

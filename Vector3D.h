#pragma once

#include <memory>
#include "Point3D.h"

using std::shared_ptr;

class Point3D;

class Vector3D {
public:
    Vector3D(const Point3D& p0=Point3D(), const Point3D& p1=Point3D());
    Vector3D(const Vector3D& v1);

    friend double operator* (const Vector3D& v1, const Vector3D& v2);

private:
    shared_ptr<Point3D> m_radiusVect;
};

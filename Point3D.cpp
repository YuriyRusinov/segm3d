#include <math.h>
#include <limits>
#include "Point3D.h"

using std::endl;

Point3D& Point3D::operator+= (const Point3D& p) {
    m_x += p.m_x;
    m_y += p.m_y;
    m_z += p.m_z;
    return *this;
}

Point3D& Point3D::operator-= (const Point3D& p) {
    m_x -= p.m_x;
    m_y -= p.m_y;
    m_z -= p.m_z;
    return *this;
}

Point3D& Point3D::operator*= (double alamb) {
    m_x *= alamb;
    m_y *= alamb;
    m_z *= alamb;
    return *this;
}

Point3D& Point3D::operator/= (double alamb) {
    double eps = std::numeric_limits<double>::epsilon();
    if(fabs(alamb) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    (*this) *= (0.1e1/alamb);
    return *this;
}


istream& operator>>(istream& f, Point3D& p)
{
    f >> p.m_x >> p.m_y >> p.m_z;
    return f;
}

ostream& operator<<(ostream& f, const Point3D& p) {
    f << p.m_x << ' ' << p.m_y << ' ' << p.m_z;
    return f;
}

double P2Dist::operator() (const Point3D& p1, const Point3D& p2) const {
    double dx = p1.X()-p2.X();
    double dy = p1.Y()-p2.Y();
    double dz = p1.Z()-p2.Z();
    double res = sqrt(dx*dx+dy*dy+dz*dz);
    return res;
}

Point3D operator-(const Point3D& p0, const Point3D& p1) {
    Point3D res(p0);
    res -= p1;
    return res;
}

Point3D operator+(const Point3D& p0, const Point3D& p1) {
    Point3D res(p0);
    res += p1;
    return res;
}

Point3D operator*(const Point3D& p0, double alamb) {
    Point3D res(p0);
    res *= alamb;
    return res;
}

Point3D operator*(double alamb, const Point3D& p0) {
    return p0*alamb;
}


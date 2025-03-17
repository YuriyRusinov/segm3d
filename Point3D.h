#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class Point3D {
public:
    Point3D(double xx=0.0, double yy=0.0, double zz=0.0) : m_x(xx), m_y(yy), m_z(zz) {};

    double X() const { return m_x; }
    double& X() { return m_x; }

    double Y() const { return m_y; }
    double& Y() { return m_y; }

    double Z() const { return m_z; }
    double& Z() { return m_z; }

    Point3D& operator+= (const Point3D& p);
    Point3D& operator-= (const Point3D& p);
    Point3D& operator*= (double alamb);
    Point3D& operator/= (double alamb);

    friend istream& operator>>(istream& f, Point3D& p);
    friend ostream& operator<<(ostream& f, const Point3D& p);

    friend Point3D operator-(const Point3D& p0, const Point3D& p1);
    friend Point3D operator+(const Point3D& p0, const Point3D& p1);
    friend Point3D operator*(const Point3D& p0, double alamb);
    friend Point3D operator*(double alamb, const Point3D& p0);

private:
    double m_x;
    double m_y;
    double m_z;
};

class P2Dist {
public:
    double operator() (const Point3D& p1, const Point3D& p2) const;
};

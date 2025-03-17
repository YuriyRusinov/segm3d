#pragma once

#include "Point3D.h"

class Segment3D {
public:
    Segment3D(const Point3D& start=Point3D(), const Point3D& fin=Point3D());

    Point3D& start() { return m_start; }
    const Point3D& start() const { return m_start; }

    Point3D& finish() { return m_finish; }
    const Point3D finish() const { return m_finish; }

private:
    Point3D m_start;
    Point3D m_finish;
};

class SegmDist {
public:
    double operator() (const Segment3D& AB, const Segment3D& CD) const;
};

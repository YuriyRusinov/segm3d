#include <iostream>
#include <limits>
#include <math.h>

#include "Matrix.h"
#include "Segment3D.h"
#include "Vector3D.h"

using std::cout;
using std::endl;

Segment3D::Segment3D(const Point3D& start, const Point3D& fin)
    : m_start(start), m_finish(fin)
{
}

double SegmDist::operator() (const Segment3D& AB, const Segment3D& CD) const
{
    Point3D A = AB.start();
    Point3D B = AB.finish();
    Point3D C = CD.start();
    Point3D D = CD.finish();
    Vector3D AB0(A, B);
    Vector3D CD0(C, D);
    Vector3D AC0(A, C);
    double ab_ab = AB0*AB0;
    double cd_cd = CD0*CD0;
    double ab_cd = AB0*CD0;
    double ac_ab = AC0*AB0;
    double ac_cd = AC0*CD0;
    Matrix mGeom(2, 2);
    mGeom(0, 0) = ab_ab;
    mGeom(0, 1) = ab_cd;
    mGeom(1, 0) = ab_cd;
    mGeom(1, 1) = cd_cd;

    double det = determinant(mGeom);
    double eps = std::numeric_limits<double>::epsilon();
    double t, s;
    if(fabs(det) < eps) {
        t = fabs(ab_ab) > eps ? ac_ab / ab_ab : 0.0;
        s = fabs(cd_cd) > eps ? ac_cd / cd_cd : 0.0;
    }
    else {
        t = (ac_ab * cd_cd - ac_cd * ab_cd) / det;
        s = (ac_ab * ab_cd - ac_cd * ab_ab) / det;
    }

    Point3D P = A + t*(B-A);
    Point3D Q = C + s*(D-C);
    P2Dist PD;
    double res = PD(P,Q);
    return res;

}

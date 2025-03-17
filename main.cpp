#include <iostream>
#include <fstream>

#include "Point3D.h"
#include "Vector3D.h"
#include "Segment3D.h"
#include "Matrix.h"

using std::iostream;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    cout << "Program calculates distance between 2 line segments in 3d" << endl;
    Point3D A;
    fstream segFile("segments.dat");
    segFile >> A;
    cout << "first point of first segment is " << A << endl;
    Point3D B;
    segFile >> B;
    cout << "last point of first segment is " << B << endl;
    Segment3D seg1st(A, B);

    Point3D C;
    segFile >> C;
    cout << "first point of second segment is " << C << endl;
    Point3D D;
    segFile >> D;
    cout << "last point of second segment is " << D << endl;
    Segment3D seg2nd(C, D);

    SegmDist FSegmDist;
    double distance = FSegmDist(seg1st, seg2nd);
    cout << "distance between AB and CD is " << distance << endl;
/*    Matrix XX(4,4);
    XX(0,0) = 1.0;
    XX(0,1) = 0.0;
    XX(0,2) = 2.0;
    XX(0,3) = -1.0;
    XX(1,0) = 3.0;
    XX(1,1) = 0.0;
    XX(1,2) = 0.0;
    XX(1,3) = 5.0;
    XX(2,0) = 2.0;
    XX(2,1) = 1.0;
    XX(2,2) = 4.0;
    XX(2,3) = -3.0;
    XX(3,0) = 1.0;
    XX(3,1) = 0.0;
    XX(3,2) = 5.0;
    XX(3,3) = 0.0;
    cout << "Test matrix is" << XX;
    cout << "Determinant is " << determinant(XX) << endl;*/
    return 0;
}

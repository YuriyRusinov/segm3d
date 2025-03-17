#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::ostream;

class Matrix {
public:
    Matrix(int n=3, int m=3);

    double& operator() (int i, int j);
    const double& operator() (int i, int j) const;

    int rowCount() const;
    int columnCount() const;

    Matrix subMatrix(int i, int j) const;
    Matrix rowMinor(int rowStart, int rowEnd) const;
    vector<double> getRow(int i) const;
    void clearData();
    void appendRow(const vector<double> rr);
    friend ostream& operator<<(ostream& f, const Matrix& mm);

private:
    int m_nRows;
    int m_nCols;
    vector<double> m_data;
};

double determinant(const Matrix& A);
int rank(const Matrix& A);

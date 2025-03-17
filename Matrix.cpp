#include <stdexcept>
#include <iostream>
#include <exception>
#include <limits>
#include <math.h>
#include "Matrix.h"

using std::exception;

Matrix::Matrix(int n, int m)
    : m_nRows(n),
    m_nCols(m),
    m_data(vector<double>(n*m))
{
}

double& Matrix::operator() (int i, int j)
{
    if(i<0 || i>=m_nRows || j<0 || j>= m_nCols)
        throw std::range_error("Invalid indices");

    return m_data[i*m_nRows+j];
}

const double& Matrix::operator() (int i, int j) const
{
    if(i<0 || i>=m_nRows || j<0 || j>= m_nCols)
        throw std::range_error("Invalid indices");

    return m_data[i*m_nCols+j];
}

int Matrix::rowCount() const
{
    return m_nRows;
}

int Matrix::columnCount() const
{
    return m_nCols;
}

Matrix Matrix::subMatrix(int i, int j) const
{
    if(m_nRows == 1 || m_nCols == 1 )
        throw std::range_error("Invalid indices");

    int nr = (i<0 || i>=m_nRows ? 0 : 1);
    int nc = (j<0 || j>= m_nCols ? 0 : 1);
    Matrix sMatr(m_nRows-nr, m_nCols-nc);
    int subi = 0;
    for(int ii=0; ii<m_nRows; ii++) {
        int subj = 0;
        if(i==ii)
            continue;
        for(int jj=0; jj<m_nCols; jj++) {
            if(j==jj)
                continue;
            sMatr(subi, subj) = this->operator()(ii, jj);
            subj++;
        }
        subi++;
    }

    return sMatr;
}

//
// Minor by rows [rowStart, rowEnd)
//
Matrix Matrix::rowMinor(int rowStart, int rowEnd) const
{
    if(rowStart < 0 || rowStart >= m_nRows || rowEnd < 0 || rowEnd > m_nRows)
        throw std::range_error("Invalid limits");

    Matrix rMatr( rowEnd-rowStart, m_nCols);
    rMatr.m_data = std::vector<double>(m_data.begin()+m_nCols*rowStart, m_data.end());
    return rMatr;
}

vector<double> Matrix::getRow(int i) const {
    if(i<0 || i>=m_nRows)
        return vector<double>();
    vector<double> rr(m_nCols, 0.0);
    for (int j=0; j<m_nCols; j++)
        rr[j] = m_data[i*m_nRows+j];
    return rr;
}

void Matrix::clearData() {
    m_data.clear();
    m_nRows = 0;
    m_nCols = 0;
}

void Matrix::appendRow(const vector<double> rr)
{
    for (int j=0; j<m_nCols; j++)
        m_data.push_back(rr[j]);
    m_nRows++;
}


ostream& operator<<(ostream& f, const Matrix& mm) {

    for(int i=0; i<mm.m_nRows; i++)
    {
        for(int j=0; j<mm.m_nCols; j++)
            f << mm(i, j) << ' ';
        f << std::endl;
    }
    return f;
}

double determinant(const Matrix& A)
{
    if(A.rowCount() != A.columnCount())
    {
        throw std::length_error("Matrix is not square");
    }

    int n = A.rowCount();
    double det = 0.0;
    if(n == 1)
        return A(0,0);
    else if(n==2) {
        return (A(0,0)*A(1,1))-(A(0,1)*A(1,0));
    }
    else {
        int sign = 1;
        for(int i=0; i<n; i++) {
            det +=sign*A(0, i)*determinant(A.subMatrix(0,i));
            sign *= -1;
        }
        return det;
    }
}

int rank(const Matrix& A0)
{
    Matrix A(A0);
    int rank = std::max(A.rowCount(), A.columnCount());
    int n = A.rowCount();
    int m = A.columnCount();
    vector<bool> line_used(n, false);
    double eps = std::numeric_limits<double>::epsilon();
    for (int i=0; i<m; ++i) {
        int j;
        for (j=0; j<n; ++j)
            if (!line_used[j] && fabs(A(j,i)) > eps)
                break;
        if (j == n)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<m; ++p)
                A(j,p) /= A(j,i);
            for (int k=0; k<n; ++k)
                if (k != j && fabs (A(k,i)) > eps)
                    for (int p=i+1; p<m; ++p)
                        A(k,p) -= A(j,p) * A(k,i);
        }
    }
    return rank;
}


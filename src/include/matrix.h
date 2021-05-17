/// \file matrix.h

#ifndef SRC_INCLUDE_MATRIX_H_
#define SRC_INCLUDE_MATRIX_H_

#include "vector.h"

template <typename T>
class Matrix
{
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix<T>& rhs);
    ~Matrix();
    void print();
    Matrix<T> operator=(std::vector<std::vector<T>> mat);
    Matrix<T> operator*(const Matrix<T>& rhs);
    Vector<T> operator*(const Vector<T>& rhs);
    Matrix<T> operator*(const T& scale);
    Matrix<T> operator+(const Matrix<T>& rhs);
    Matrix<T> operator-(const Matrix<T>& rhs);

    int rows_;
    int cols_;
    T **mat_;
};

#endif  // SRC_INCLUDE_MATRIX_H_

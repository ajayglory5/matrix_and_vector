/// \file matrix_templates.h

#ifndef SRC_INCLUDE_MATRIX_TEMPLATES_H_
#define SRC_INCLUDE_MATRIX_TEMPLATES_H_

#include "matrix.h"

// templates for int
template Matrix<int>::Matrix(int r, int c);
template Matrix<int>::Matrix(const Matrix<int>& rhs);
template Matrix<int>::~Matrix();
template void Matrix<int>::print();
template Matrix<int> Matrix<int>::operator=(std::vector<std::vector<int>> mat);
template Vector<int> Matrix<int>::operator*(const Vector<int>& rhs);
template Matrix<int> Matrix<int>::operator*(const int& scale);
template Matrix<int> Matrix<int>::operator*(const Matrix<int>& rhs);
template Matrix<int> Matrix<int>::operator+(const Matrix<int>& rhs);
template Matrix<int> Matrix<int>::operator-(const Matrix<int>& rhs);

// templates for float
template Matrix<float>::Matrix(int r, int c);
template Matrix<float>::Matrix(const Matrix<float>& rhs);
template Matrix<float>::~Matrix();
template void Matrix<float>::print();
template Matrix<float> Matrix<float>::operator=(std::vector<std::vector<float>> mat);
template Vector<float> Matrix<float>::operator*(const Vector<float>& rhs);
template Matrix<float> Matrix<float>::operator*(const float& scale);
template Matrix<float> Matrix<float>::operator*(const Matrix<float>& rhs);
template Matrix<float> Matrix<float>::operator+(const Matrix<float>& rhs);
template Matrix<float> Matrix<float>::operator-(const Matrix<float>& rhs);

// templates for double
template Matrix<double>::Matrix(int r, int c);
template Matrix<double>::Matrix(const Matrix<double>& rhs);
template Matrix<double>::~Matrix();
template void Matrix<double>::print();
template Matrix<double> Matrix<double>::operator=(std::vector<std::vector<double>> mat);
template Vector<double> Matrix<double>::operator*(const Vector<double>& rhs);
template Matrix<double> Matrix<double>::operator*(const double& scale);
template Matrix<double> Matrix<double>::operator*(const Matrix<double>& rhs);
template Matrix<double> Matrix<double>::operator+(const Matrix<double>& rhs);
template Matrix<double> Matrix<double>::operator-(const Matrix<double>& rhs);

#endif  // SRC_INCLUDE_MATRIX_TEMPLATES_H_

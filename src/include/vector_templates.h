/// \file vector_templates.h

#ifndef SRC_INCLUDE_VECTOR_TEMPLATES_H_
#define SRC_INCLUDE_VECTOR_TEMPLATES_H_

#include "vector.h"

// templates for int
template Vector<int>::Vector();
template Vector<int>::Vector(const Vector<int>& rhs);
template Vector<int>::~Vector();
template void Vector<int>::print();
template Vector<int> Vector<int>::operator=(std::vector<int> vec);
template Vector<int> Vector<int>::operator*(const int& scale);
template Vector<int> Vector<int>::operator*(const Vector<int>& rhs);
template Vector<int> Vector<int>::operator+(const Vector<int>& rhs);
template Vector<int> Vector<int>::operator-(const Vector<int>& rhs);

// templates for float
template Vector<float>::Vector();
template Vector<float>::Vector(const Vector<float>& rhs);
template Vector<float>::~Vector();
template void Vector<float>::print();
template Vector<float> Vector<float>::operator=(std::vector<float> vec);
template Vector<float> Vector<float>::operator*(const float& scale);
template Vector<float> Vector<float>::operator*(const Vector<float>& rhs);
template Vector<float> Vector<float>::operator+(const Vector<float>& rhs);
template Vector<float> Vector<float>::operator-(const Vector<float>& rhs);

// templates for double
template Vector<double>::Vector();
template Vector<double>::Vector(const Vector<double>& rhs);
template Vector<double>::~Vector();
template void Vector<double>::print();
template Vector<double> Vector<double>::operator=(std::vector<double> vec);
template Vector<double> Vector<double>::operator*(const double& scale);
template Vector<double> Vector<double>::operator*(const Vector<double>& rhs);
template Vector<double> Vector<double>::operator+(const Vector<double>& rhs);
template Vector<double> Vector<double>::operator-(const Vector<double>& rhs);

#endif  // SRC_INCLUDE_VECTOR_TEMPLATES_H_

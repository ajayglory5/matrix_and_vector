/// \file vector.h

#ifndef SRC_INCLUDE_VECTOR_H_
#define SRC_INCLUDE_VECTOR_H_

#include <vector>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(const Vector<T>& rhs);
    ~Vector();
    void print();
    Vector<T> operator=(std::vector<T> vec);
    Vector<T> operator*(const Vector<T>& rhs);
    Vector<T> operator*(const T& scale);
    Vector<T> operator+(const Vector<T>& rhs);
    Vector<T> operator-(const Vector<T>& rhs);
    
    static constexpr int kElements{3U};
    T *vec_;
};

#endif  // SRC_INCLUDE_VECTOR_H_

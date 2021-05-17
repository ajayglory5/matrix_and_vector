/// \file vector.cpp

#include "vector.h"
#include "vector_templates.h"
#include <iomanip> 
#include <iostream>

template <typename T>
Vector<T>::Vector(){
    vec_ = (T*) new T[kElements];
    for(int i=0; i<kElements; ++i){
        vec_[i] = 0;    
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs){
    vec_ = (T*) new T[kElements]; 
    for(int i=0; i<kElements; ++i){
        vec_[i] = rhs.vec_[i];    
    }
}

template <typename T>
Vector<T>::~Vector(){
    if(vec_ != NULL){
        delete[] vec_;
        vec_ = NULL;
    }
}

template <typename T>
void Vector<T>::print(){
    for(int i=0; i<kElements; ++i){
        std::cout << std::setw(2) << vec_[i]  << std::endl;     
    }
    std::cout << std::endl;
}

template <typename T>
Vector<T> Vector<T>::operator=(std::vector<T> vec){
    if(kElements != vec.size()) {
        std::cout << "Input vector size should be " << kElements << "!" << std::endl;
    }
    else{
        for(int i=0; i<kElements; ++i){
            vec_[i] = vec[i];    
        }
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector<T>& rhs){
    Vector<T> output;

    output.vec_[0] = (vec_[1] * rhs.vec_[2]) - (vec_[2] * rhs.vec_[1]);
    output.vec_[1] = (vec_[2] * rhs.vec_[0]) - (vec_[0] * rhs.vec_[2]);
    output.vec_[2] = (vec_[0] * rhs.vec_[1]) - (vec_[1] * rhs.vec_[0]);

    return output;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T& scale){
    for(int i=0; i<kElements; ++i){
        vec_[i] *= scale;
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs){
    Vector<T> output;

    for(int i=0; i<kElements; ++i){
        output.vec_[i] = (vec_[i] + rhs.vec_[i]);
    }

    return output;
} 

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs){
    Vector<T> output;

    for(int i=0; i<kElements; ++i){
        output.vec_[i] = (vec_[i] - rhs.vec_[i]);
    }

    return output;
} 

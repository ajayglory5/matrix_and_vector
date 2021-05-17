/// \file matrix.cpp

#include "matrix.h"
#include "matrix_templates.h"
#include <iomanip> 
#include <iostream>

template <typename T>
Matrix<T>::Matrix(int rows, int cols){
    rows_ = rows;
    cols_ = cols;

    mat_ = (T**) new T*[rows_];
    for(int i=0; i<rows_; ++i){
        mat_[i] = (T*) new T[cols_];  
    } 

    for(int i=0; i<rows_; ++i){
        for(int j=0; j<cols_; ++j){
            mat_[i][j] = 0;    
        } 
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs){
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;

    mat_ = (T**) new T*[rows_];
    for(int i=0; i<rows_; ++i){
        mat_[i] = (T*) new T[cols_];  
    } 

    for(int i=0; i<rows_; ++i){
        for(int j=0; j<cols_; ++j){
            mat_[i][j] = rhs.mat_[i][j];    
        } 
    }
}

template <typename T>
Matrix<T>::~Matrix(){
    if(cols_ > 0){
        for(int i=0; i<rows_; ++i){
            delete[] mat_[i];  
        }
        cols_ = 0;
    }
    if(rows_ > 0){
        delete[] mat_;
        rows_ = 0;
    }
}

template <typename T>
void Matrix<T>::print(){
    for(int i=0; i<rows_; ++i){
        for(int j=0; j<cols_; ++j){
            std::cout << std::setw(2) << mat_[i][j] << " ";     
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
Matrix<T> Matrix<T>::operator=(std::vector<std::vector<T>> mat){
    if( (rows_ != mat.size()) || (cols_ != mat[0].size()) ){
        std::cout << "Input doesn't match with the created rows & columns of matrix!" << std::endl;
    }
    else{
        for(int i=0; i<rows_; ++i){
            for(int j=0; j<cols_; ++j){
                mat_[i][j] = mat[i][j];    
            }
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs){
    Matrix<T> output(rows_, rhs.cols_);

    if(cols_ != rhs.rows_){
        std::cout << "Column of first matrix and Row of second matrix has to be same!" << std::endl;
    }
    else{ 
        for(int i=0; i<rows_; ++i){
            for(int j=0; j<rhs.cols_; ++j){
                for(int k=0; k<cols_; ++k){
                    output.mat_[i][j] += (mat_[i][k] * rhs.mat_[k][j]);
                }
            }
        }
    }
    return output;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T>& rhs){
    Vector<T> output;

    if(cols_ != rhs.kElements){
        std::cout << "Column of matrix should be " << rhs.kElements << " !" << std::endl;
    }
    else{ 
        for(int i=0; i<rows_; ++i){
            for(int k=0; k<cols_; ++k){
                output.vec_[i] += (mat_[i][k] * rhs.vec_[k]);
            }
        }
    }
    return output;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& scale){
    for(int i=0; i<rows_; ++i){
        for(int j=0; j<cols_; ++j){
            mat_[i][j] *= scale;
        }
    }
    return *this;
} 

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs){
    Matrix<T> output(rows_, cols_);

    if( (rows_ != rhs.rows_) || (cols_ != rhs.cols_) ){
        std::cout << "Rows & Columns of both matrixces has to be same!" << std::endl;
    }
    else{ 
        for(int i=0; i<rows_; ++i){
            for(int j=0; j<cols_; ++j){
                output.mat_[i][j] = (mat_[i][j] + rhs.mat_[i][j]);
            }
        }
    }
    return output;
} 

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs){
    Matrix<T> output(rows_, cols_);

    if( (rows_ != rhs.rows_) || (cols_ != rhs.cols_) ){
        std::cout << "Rows & Columns of both matrixces has to be same!" << std::endl;
    }
    else{ 
        for(int i=0; i<rows_; ++i){
            for(int j=0; j<cols_; ++j){
                output.mat_[i][j] = (mat_[i][j] - rhs.mat_[i][j]);
            }
        }
    }
    return output;
} 

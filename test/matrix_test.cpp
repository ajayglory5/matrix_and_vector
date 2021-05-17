/// \file matrix_test.cpp

#include "matrix.h"
#include "test_utils.h"

using ::testing::internal::CaptureStderr;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStderr;
using ::testing::internal::GetCapturedStdout;

TEST(matrix, initError){
    CaptureStdout();
    int rows{3U}, cols{2U};

    Matrix<int> mat(rows, cols);
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], 0U);  
        } 
    }

    // try assigning an input with wrong rows
    std::vector<std::vector<int>> sampleRow{{2, 3}, {4, 5}};
    mat = sampleRow;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], 0U);  
        } 
    }

    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Input doesn't match with the created rows & columns of matrix")));

    CaptureStdout();
    // try assigning an input with wrong cols
    std::vector<std::vector<int>> sampleCol{{2, 3, 4}, {4, 5, 2}, {2, 0, 6}};
    mat = sampleCol;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], 0U);  
        } 
    }

    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Input doesn't match with the created rows & columns of matrix")));
}

TEST(matrix, initSuccess){
    CaptureStderr();
    int rows{3U}, cols{2U};

    Matrix<int> mat(rows, cols);
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], 0U);  
        } 
    }

    std::vector<std::vector<int>> sample{{2, 3}, {4, 5}, {3, 8}};
    mat = sample;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], sample[i][j]);  
        } 
    }

    GetCapturedStderr();
}

TEST(matrix, copySuccess){
    CaptureStderr();

    std::vector<std::vector<int>> sample{{2, 3}, {4, 5}, {3, 8}};
    int rows{3U}, cols{2U};

    Matrix<int> mat_1(rows, cols);
    mat_1 = sample;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], sample[i][j]);  
        } 
    }

    Matrix<int> mat_2(mat_1);
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], mat_2.mat_[i][j]);  
        } 
    }

    GetCapturedStderr();
}

TEST(matrix, productMatrixToMatrix){
    CaptureStdout();

    std::vector<std::vector<int>> sample_1{{2, 3}, {4, 5}, {3, 8}};
    std::vector<std::vector<int>> sample_2{{2, 3}, {4, 5}, {3, 8}};
    std::vector<std::vector<int>> sample_3{{6, 1, 2}, {3, 7, 2}};
    std::vector<std::vector<int>> expected{{21, 23, 10}, {39, 39, 18}, {42, 59, 22}};

    int rows{3U}, cols{2U};
    Matrix<int> mat_1(rows, cols), mat_2(rows, cols), mat_3(cols, rows);
    mat_1 = sample_1;
    mat_2 = sample_2;
    mat_3 = sample_3;

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], sample_1[i][j]);
            EXPECT_EQ(mat_2.mat_[i][j], sample_2[i][j]); 
        } 
    }

    for(int i=0; i<cols; ++i){
        for(int j=0; j<rows; ++j){
            EXPECT_EQ(mat_3.mat_[i][j], sample_3[i][j]);
        } 
    }

    Matrix<int> prodError = mat_1 * mat_2;
    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Column of first matrix and Row of second matrix has to be same!")));

    CaptureStderr();

    Matrix<int> prodSuccess = mat_1 * mat_3;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<rows; ++j){
            EXPECT_EQ(prodSuccess.mat_[i][j], expected[i][j]);
        } 
    }

    GetCapturedStderr();
}

TEST(matrix, productMatrixToVector){
    CaptureStdout();

    int rows{3U}, cols{3U};
    Matrix<int> mat_1(rows, cols), mat_2(cols, rows-1);
    std::vector<std::vector<int>> sample_1{{6, 1, 2}, {3, 7, 2}, {1, 1, 1}};
    std::vector<std::vector<int>> sample_2{{2, 3}, {4, 5}, {3, 8}};
    mat_1 = sample_1;
    mat_2 = sample_2;

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], sample_1[i][j]);
        } 
    }

    for(int i=0; i<cols; ++i){
        for(int j=0; j<rows-1; ++j){
            EXPECT_EQ(mat_2.mat_[i][j], sample_2[i][j]); 
        } 
    }

    Vector<int> vec;
    std::vector<int> sample_3{2, 3, 4};
    vec = sample_3;

    for(int i=0; i<vec.kElements; ++i){
        EXPECT_EQ(vec.vec_[i], sample_3[i]);
    }

    Vector<int> prodError = mat_2 * vec;
    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Column of matrix should be " + std::to_string(vec.kElements))));

    CaptureStderr();

    std::vector<int> expected{{23, 35, 9}};
    Vector<int> prodSuccess = mat_1 * vec;
    for(int i=0; i<rows; ++i){
        EXPECT_EQ(prodSuccess.vec_[i], expected[i]);
    }

    GetCapturedStderr();
}

TEST(matrix, scaling){
    CaptureStderr();

    int rows{2U}, cols{3U};
    Matrix<int> mat(rows, cols);
    std::vector<std::vector<int>> sample_1{{6, 1, 2}, {3, 7, 2}};
    std::vector<std::vector<int>> expected{{36, 6, 12}, {18, 42, 12}};
    mat = sample_1;

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], sample_1[i][j]);
        } 
    }

    Matrix<int> scaledMatrix = mat * 6U;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat.mat_[i][j], expected[i][j]);
        } 
    }

    GetCapturedStderr();
}

TEST(matrix, addition){
    CaptureStdout();

    std::vector<std::vector<int>> sample_1{{2, 3}, {4, 5}, {3, 8}};
    std::vector<std::vector<int>> sample_2{{3, 2}, {6, 1}, {5, 2}};
    std::vector<std::vector<int>> sample_3{{6, 1, 2}, {3, 7, 2}};
    std::vector<std::vector<int>> expected{{5, 5}, {10, 6}, {8, 10}};

    int rows{3U}, cols{2U};
    Matrix<int> mat_1(rows, cols), mat_2(rows, cols), mat_3(cols, rows);
    mat_1 = sample_1;
    mat_2 = sample_2;
    mat_3 = sample_3;

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], sample_1[i][j]);
            EXPECT_EQ(mat_2.mat_[i][j], sample_2[i][j]); 
        } 
    }

    for(int i=0; i<cols; ++i){
        for(int j=0; j<rows; ++j){
            EXPECT_EQ(mat_3.mat_[i][j], sample_3[i][j]);
        } 
    }

    Matrix<int> sumError = mat_1 + mat_3;
    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Rows & Columns of both matrixces has to be same!")));

    CaptureStderr();

    Matrix<int> sumSuccess = mat_1 + mat_2;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(sumSuccess.mat_[i][j], expected[i][j]);
        } 
    }

    GetCapturedStderr();
}

TEST(matrix, subtraction){
    CaptureStdout();

    std::vector<std::vector<int>> sample_1{{2, 3}, {4, 5}, {3, 8}};
    std::vector<std::vector<int>> sample_2{{3, 2}, {6, 1}, {5, 2}};
    std::vector<std::vector<int>> sample_3{{6, 1, 2}, {3, 7, 2}};
    std::vector<std::vector<int>> expected{{-1, 1}, {-2, 4}, {-2, 6}};

    int rows{3U}, cols{2U};
    Matrix<int> mat_1(rows, cols), mat_2(rows, cols), mat_3(cols, rows);
    mat_1 = sample_1;
    mat_2 = sample_2;
    mat_3 = sample_3;

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(mat_1.mat_[i][j], sample_1[i][j]);
            EXPECT_EQ(mat_2.mat_[i][j], sample_2[i][j]); 
        } 
    }

    for(int i=0; i<cols; ++i){
        for(int j=0; j<rows; ++j){
            EXPECT_EQ(mat_3.mat_[i][j], sample_3[i][j]);
        } 
    }

    Matrix<int> sumError = mat_1 - mat_3;
    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Rows & Columns of both matrixces has to be same!")));

    CaptureStderr();

    Matrix<int> sumSuccess = mat_1 - mat_2;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            EXPECT_EQ(sumSuccess.mat_[i][j], expected[i][j]);
        } 
    }

    GetCapturedStderr();
}

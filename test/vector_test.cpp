/// \file vector_test.cpp

#include "vector.h"
#include "test_utils.h"

using ::testing::internal::CaptureStderr;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStderr;
using ::testing::internal::GetCapturedStdout;

TEST(vector, initError){
    CaptureStdout();

    Vector<int> vec;
    for(int i=0; i<vec.kElements; ++i){
        EXPECT_EQ(vec.vec_[i], 0U);
    } 

    // try assigning a list having greater than 3 elements
    std::vector<int> gSampleValue{2, 3, 5, 8};
    vec = gSampleValue;
    for(int i=0; i<vec.kElements; ++i){
        EXPECT_EQ(vec.vec_[i], 0U);
    }

    // try assigning a list having less than 3 elements
    std::vector<int> lSampleValue{2, 3};
    vec = lSampleValue;
    for(int i=0; i<vec.kElements; ++i){
        EXPECT_EQ(vec.vec_[i], 0U);
    }

    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Input vector size should be " + std::to_string(vec.kElements))));
}

TEST(vector, initSuccess){
    CaptureStderr();

    Vector<int> vec_1;
    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], 0U);
    } 

    std::vector<int> sampleValues{2, 3, 4};
    vec_1 = sampleValues;

    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], sampleValues[i]);
    }

    GetCapturedStderr();
}

TEST(vector, copySuccess){
    CaptureStderr();

    Vector<int> vec_1;
    std::vector<int> sampleValues{2, 3, 4};
    vec_1 = sampleValues;

    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], sampleValues[i]);
    }

    Vector<int> vec_2(vec_1);
    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], vec_2.vec_[i]);
    }

    GetCapturedStderr();
}

TEST(vector, crossProduct){
    CaptureStderr();

    Vector<int> vec_1, vec_2;
    std::vector<int> sampleValues_1{2, 3, 4}, sampleValues_2{5, 3, 2};
    vec_1 = sampleValues_1;
    vec_2 = sampleValues_2;

    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], sampleValues_1[i]);
        EXPECT_EQ(vec_2.vec_[i], sampleValues_2[i]);
    }

    Vector<int> vec_3 = vec_1 * vec_2;
    EXPECT_EQ(vec_3.vec_[0], -6U);
    EXPECT_EQ(vec_3.vec_[1], 16U);
    EXPECT_EQ(vec_3.vec_[2], -9U);

    GetCapturedStderr();
}

TEST(vector, scaling){
    CaptureStderr();

    Vector<int> vec;
    std::vector<int> sampleValues{2, 3, 4};
    vec = sampleValues;

    for(int i=0; i<vec.kElements; ++i){
        EXPECT_EQ(vec.vec_[i], sampleValues[i]);
    }

    Vector<int> scaledVector = vec * 6U;
    EXPECT_EQ(scaledVector.vec_[0], 12U);
    EXPECT_EQ(scaledVector.vec_[1], 18U);
    EXPECT_EQ(scaledVector.vec_[2], 24U);

    GetCapturedStderr();
}

TEST(vector, addition){
    CaptureStderr();

    Vector<int> vec_1, vec_2;
    std::vector<int> sampleValues_1{2, 3, 4}, sampleValues_2{5, 3, 2};
    vec_1 = sampleValues_1;
    vec_2 = sampleValues_2;

    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], sampleValues_1[i]);
        EXPECT_EQ(vec_2.vec_[i], sampleValues_2[i]);
    }

    Vector<int> vec_3 = vec_1 + vec_2;
    EXPECT_EQ(vec_3.vec_[0], 7U);
    EXPECT_EQ(vec_3.vec_[1], 6U);
    EXPECT_EQ(vec_3.vec_[2], 6U);

    GetCapturedStderr();
}

TEST(vector, subtraction){
    CaptureStderr();

    Vector<int> vec_1, vec_2;
    std::vector<int> sampleValues_1{2, 3, 4}, sampleValues_2{5, 3, 2};
    vec_1 = sampleValues_1;
    vec_2 = sampleValues_2;

    for(int i=0; i<vec_1.kElements; ++i){
        EXPECT_EQ(vec_1.vec_[i], sampleValues_1[i]);
        EXPECT_EQ(vec_2.vec_[i], sampleValues_2[i]);
    }

    Vector<int> vec_3 = vec_1 - vec_2;
    EXPECT_EQ(vec_3.vec_[0], -3U);
    EXPECT_EQ(vec_3.vec_[1], 0U);
    EXPECT_EQ(vec_3.vec_[2], 2U);

    GetCapturedStderr();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
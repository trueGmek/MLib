
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>
#include <array>

using ::testing::ElementsAre;

MLib::Matrix<int, 2, 2> identity2x2{1, 0,
                                    0, 1};

MLib::Matrix<int, 2, 2> zero2x2{0, 0,
                                0, 0};

MLib::Matrix<int, 3, 3> identity3x3{1, 0, 0,
                                    0, 1, 0,
                                    0, 0, 1};

MLib::Matrix<int, 4, 4> identity4x4{1, 0, 0, 0,
                                    0, 1, 0, 0,
                                    0, 0, 1, 0,
                                    0, 0, 0, 1};

MLib::Matrix<int, 5, 5> identity5x5{1, 0, 0, 0, 0,
                                    0, 1, 0, 0, 0,
                                    0, 0, 1, 0, 0,
                                    0, 0, 0, 1, 0,
                                    0, 0, 0, 0, 1};

TEST(MatrixMultiplicationTest, identity2x2_identity2x2)
{
    //Arrange
    //Act
    MLib::Matrix<int, 2, 2> result = identity2x2 * identity2x2;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 0,
                                             0, 1));
}

TEST(MatrixMultiplicationTest, identity2x2_zero2x2)
{
    //Arrange
    //Act
    MLib::Matrix<int, 2, 2> result = identity2x2 * zero2x2;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0,
                                             0, 0));
}

TEST(MatrixMultiplicationTest, zero2x2_identity2x2)
{
    //Arrange
    //Act
    MLib::Matrix<int, 2, 2> result = zero2x2 * identity2x2;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0,
                                             0, 0));
}

TEST(MatrixMultiplicationTest, identity3x3_identity3x3)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> result = identity3x3 * identity3x3;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1));
}

TEST(MatrixMultiplicationTest, identity4x4_identity4x4)
{
    //Arrange
    //Act
    MLib::Matrix<int, 4, 4> result = identity4x4 * identity4x4;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 0, 0, 0,
                                             0, 1, 0, 0,
                                             0, 0, 1, 0,
                                             0, 0, 0, 1));
}

TEST(MatrixMultiplicationTest, identity5x5_identity5x5)
{
    //Arrange
    //Act
    MLib::Matrix<int, 5, 5> result = identity5x5 * identity5x5;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 0, 0, 0, 0,
                                             0, 1, 0, 0, 0,
                                             0, 0, 1, 0, 0,
                                             0, 0, 0, 1, 0,
                                             0, 0, 0, 0, 1));
}

TEST(MatrixMultiplicationTest, identity4x4_nonzero4x4)
{
    //Arrange
    MLib::Matrix<int, 4, 4> lhs{1, 2, 3, 4,
                                5, 6, 7, 8,
                                9, 10, 11, 12,
                                13, 14, 15, 16};
    //Act
    MLib::Matrix<int, 4, 4> result = lhs * identity4x4;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12,
                                             13, 14, 15, 16));
}

TEST(MatrixMultiplicationTest, nonzero4x4_identity4x4)
{
    //Arrange
    MLib::Matrix<int, 4, 4> rhs{1, 2, 3, 4,
                                5, 6, 7, 8,
                                9, 10, 11, 12,
                                13, 14, 15, 16};
    //Act
    MLib::Matrix<int, 4, 4> result = identity4x4 * rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12,
                                             13, 14, 15, 16));
}

TEST(MatrixMultiplicationTest, nonzero2x2_nonzero2x2)
{
    //Arrange
    int a0{2};
    int a1{2};
    int a2{3};
    int a3{4};

    int b0{1};
    int b1{2};
    int b2{-12};
    int b3{4};

    MLib::Matrix<int, 2, 2> lhs{a0, a1,
                                a2, a3};

    MLib::Matrix<int, 2, 2> rhs{b0, b1,
                                b2, b3};
    //Act
    MLib::Matrix<int, 2, 2> result = lhs * rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre((a0 * b0 + a1 * b2), (a0 * b1 + a1 * b3),
                                             (a2 * b0 + a3 * b2), (a2 * b1 + a3 * b3)));
}

TEST(MatrixMultiplicationTest, lhsXrhs_noteq_rhsXlhs)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{1, 2,
                                3, 4};

    MLib::Matrix<int, 2, 2> rhs{4, 3,
                                2, 1};
    //Act
    MLib::Matrix<int, 2, 2> result1 = lhs * rhs;
    MLib::Matrix<int, 2, 2> result2 = rhs * lhs;

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    //Assert
    ASSERT_NE(result1, result2);
}

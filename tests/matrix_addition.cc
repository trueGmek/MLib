#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h> 
#include <array>

using ::testing::ElementsAre;

TEST(MatrixIncrementOperatorTest, empty2x2_empty2x2)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{};
    MLib::Matrix<int, 2, 2> rhs{};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0, 0, 0));
}

TEST(MatrixIncrementOperatorTest, nonempty2x2_empty_2x2)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{1, 1, 1, 1};
    MLib::Matrix<int, 2, 2> rhs{0, 0, 0, 0};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 1, 1, 1));
}

TEST(MatrixIncrementOperatorTest, empty2x2_nonepty2x2)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{0, 0, 0, 0};
    MLib::Matrix<int, 2, 2> rhs{1, 1, 1, 1};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 1, 1, 1));
}

TEST(MatrixIncrementOperatorTest, nonempty2x2_nonempty2x2)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{0, 0, 0, 0};
    MLib::Matrix<int, 2, 2> rhs{1, 1, 1, 1};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 1, 1, 1));
}

TEST(MatrixIncrementOperatorTest, nonempty2x2_nonempty2x2_1)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{1, 1, 1, 1};
    MLib::Matrix<int, 2, 2> rhs{1, 1, 1, 1};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(2, 2, 2, 2));
}

TEST(MatrixIncrementOperatorTest, nonempty2x2_nonempty2x2_2)
{
    //Arrange
    MLib::Matrix<int, 2, 2> lhs{1, 0, 1, 0};
    MLib::Matrix<int, 2, 2> rhs{0, 1, 0, 1};

    //Act
    MLib::Matrix<int, 2, 2> result = lhs + rhs;

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(1, 1, 1, 1));
}

TEST(MatrixIncrementOperatorTest, nonempty3x3_nonempty3x3_2)
{
    //Arrange
    MLib::Matrix<int, 3, 3> lhs{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<int, 3, 3> rhs{9, 8, 7, 6, 5, 4, 3, 2, 1};

    //Act
    MLib::Matrix<int, 3, 3> result{lhs + rhs};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(10, 10, 10, 10, 10, 10, 10, 10, 10));
}
TEST(MatrixIncrementOperatorTest, zero_empty2x2)
{
    //Arrange
    int scalar{0};
    MLib::Matrix<int, 2, 2> matrix{0, 0, 0, 0};

    //Act
    MLib::Matrix<int, 2, 2> result{matrix + scalar};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0, 0, 0));
}

TEST(MatrixIncrementOperatorTest, empty2x2_zero)
{
    //Arrange
    int scalar{0};
    MLib::Matrix<int, 2, 2> matrix{0, 0, 0, 0};

    //Act
    MLib::Matrix<int, 2, 2> result{scalar + matrix};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0, 0, 0));
}

TEST(MatrixIncrementOperatorTest, nonzero_empty2x2)
{
    //Arrange
    int scalar{2};
    MLib::Matrix<int, 2, 2> matrix{0, 0, 0, 0};

    //Act
    MLib::Matrix<int, 2, 2> result{matrix + scalar};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(2, 2, 2, 2));
}

TEST(MatrixIncrementOperatorTest, empty2x2_nonzero)
{
    //Arrange
    int scalar{2};
    MLib::Matrix<int, 2, 2> matrix{0, 0, 0, 0};

    //Act
    MLib::Matrix<int, 2, 2> result{scalar + matrix};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(2, 2, 2, 2));
}
TEST(MatrixIncrementOperatorTest, nonempty3x3_scalar_nonempty3x3)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<int, 3, 3> matrix2{9, 8, 7, 6, 5, 4, 3, 2, 1};

    //Act
    MLib::Matrix<int, 3, 3> result{matrix1 + 1 + matrix2};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(11, 11, 11, 11, 11, 11, 11, 11, 11));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_scalar)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<int, 3, 3> result{matrix1 - 1};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_nonempty3x3)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<int, 3, 3> matrix2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<int, 3, 3> result{matrix1 - matrix2};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_scalar_nonempty3x3)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<int, 3, 3> matrix2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<int, 3, 3> result{matrix1 - 1 - matrix2};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(-1, -1, -1, -1, -1, -1, -1, -1, -1));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_scalar_float)
{
    //Arrange
    MLib::Matrix<float, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<float, 3, 3> result{matrix1 - 1};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_nonempty3x3_float)
{
    //Arrange
    MLib::Matrix<float, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<float, 3, 3> matrix2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<float, 3, 3> result{matrix1 - matrix2};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

TEST(MatrixDecrementOperatorTest, nonempty3x3_scalar_nonempty3x3_float)
{
    //Arrange
    MLib::Matrix<float, 3, 3> matrix1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<float, 3, 3> matrix2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Act
    MLib::Matrix<float, 3, 3> result{matrix1 - 1.0 - matrix2};

    //Assert
    EXPECT_THAT(result.values(), ElementsAre(-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0));
}
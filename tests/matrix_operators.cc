#include <gtest/gtest.h>
#include <matrix.h>

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator0_0)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(0, 0);

    // Assert
    ASSERT_EQ(result, 1);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator0_1)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(0, 1);

    // Assert
    ASSERT_EQ(result, 2);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator0_2)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(0, 2);

    // Assert
    ASSERT_EQ(result, 3);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator1_0)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(1, 0);

    // Assert
    ASSERT_EQ(result, 4);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator1_1)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(1, 1);

    // Assert
    ASSERT_EQ(result, 5);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator1_2)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(1, 2);

    // Assert
    ASSERT_EQ(result, 6);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator2_0)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(2, 0);

    // Assert
    ASSERT_EQ(result, 7);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator2_1)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(2, 1);

    // Assert
    ASSERT_EQ(result, 8);
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator2_2)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    int result = matrix(2, 2);

    // Assert
    ASSERT_EQ(result, 9);
}
TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator3_0)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    // Assert
    ASSERT_DEATH(matrix(3, 0), ".");
}

TEST(MatrixParenthesisOperatorTest_Square3x3, parenthesisOperator0_3)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act
    // Assert
    ASSERT_DEATH(matrix(0, 3), ".");
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator0_0)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(0, 0);

    // Assert
    ASSERT_EQ(result, 1);
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator0_1)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(0, 1);

    // Assert
    ASSERT_EQ(result, 2);
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator0_2)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(0, 2);

    // Assert
    ASSERT_EQ(result, 3);
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator1_0)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(1, 0);

    // Assert
    ASSERT_EQ(result, 4);
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator1_1)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(1, 1);

    // Assert
    ASSERT_EQ(result, 5);
}

TEST(MatrixParenthesisOperatorTest_2x3, parenthesisOperator1_2)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3, 4, 5, 6};
    // Act
    int result = matrix(1, 2);

    // Assert
    ASSERT_EQ(result, 6);
}
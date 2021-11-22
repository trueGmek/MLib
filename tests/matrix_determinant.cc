
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>

using ::testing::ElementsAre;
//TODO: WRITE MORE TEST CASES

float const TOLERANCE = 0.001;

TEST(MatrixDeterminant, Determinant_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{1, 2,
                                     3, 4};
    // Act
    float determinant = MLib::Determinant(matrix);
    // Assert
    EXPECT_NEAR(determinant, -2, TOLERANCE);
}

TEST(MatrixDeterminant, Determinant_2x2_2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{3, 8,
                                     4, 6};
    // Act
    float determinant = MLib::Determinant(matrix);
    // Assert
    EXPECT_NEAR(determinant, -14, TOLERANCE);
}

TEST(MatrixDeterminant, Determinant_2x2_3)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{2, 7,
                                     4, 6};
    // Act
    float determinant = MLib::Determinant(matrix);
    // Assert
    EXPECT_NEAR(determinant, -16, TOLERANCE);
}

TEST(MatrixDeterminant, Determinant_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{6, 1, 1,
                                     4, -2, 5,
                                     2, 8, 7};
    // Act
    float determinant = MLib::Determinant(matrix);
    // Assert
    EXPECT_NEAR(determinant, -306, TOLERANCE);
}
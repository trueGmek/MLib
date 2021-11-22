
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>

using ::testing::ElementsAre;

TEST(MatrixTransposeFunction, transpose_2_3)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 3, 2> transMatrix = MLib::Transpose(matrix);
    // Assert
    EXPECT_THAT(transMatrix.values(), ElementsAre(1, 4,
                                                  2, 5,
                                                  3, 6));
}

TEST(MatrixTransposeFunction, transpose_3_3)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 3, 3> transMatrix = MLib::Transpose(matrix);
    // Assert
    EXPECT_THAT(transMatrix.values(), ElementsAre(1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9));
}
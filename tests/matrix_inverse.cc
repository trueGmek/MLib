#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h> 
#include <array>

using ::testing::ElementsAre;
//TODO: WRITE MORE TEST CASES

float const TOLERANCE = 0.001;

TEST(MatrixInverse, Matrix_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{1, 2,
                                     3, 4};
    // Act
    MLib::Matrix<float, 2, 2> inverse = MLib::Invert(matrix);
    // Assert
    EXPECT_THAT(inverse.values(), ElementsAre(-2, 1,
                                              1.5, -0.5));
}

TEST(MatrixInverse, identity_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{MLib::Identity<float, 2>()};
    // Act
    MLib::Matrix<float, 2, 2> inverse = MLib::Invert(matrix);
    // Assert
    EXPECT_THAT(inverse.values(), matrix.values());
}

TEST(MatrixInverse, identity_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{MLib::Identity<float, 3>()};
    // Act
    MLib::Matrix<float, 3, 3> inverse = MLib::Invert(matrix);
    // Assert
    ASSERT_EQ(inverse.values(), matrix.values());
}

TEST(MatrixInverse, Matrix_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{2, 8, 7,
                                     5, 5, 2,
                                     9, 3, 0};
    // Act
    MLib::Matrix<float, 3, 3> inverse = MLib::Invert(matrix);
    // Assert
    EXPECT_NEAR(inverse(0, 0), 0.076923, TOLERANCE);
    EXPECT_NEAR(inverse(0, 1), -0.269231, TOLERANCE);
    EXPECT_NEAR(inverse(0, 2), 0.243590, TOLERANCE);

    EXPECT_NEAR(inverse(1, 0), -0.230769, TOLERANCE);
    EXPECT_NEAR(inverse(1, 1), 0.807692, TOLERANCE);
    EXPECT_NEAR(inverse(1, 2), -0.397436, TOLERANCE);

    EXPECT_NEAR(inverse(2, 0), 0.384615, TOLERANCE);
    EXPECT_NEAR(inverse(2, 1), -0.846153, TOLERANCE);
    EXPECT_NEAR(inverse(2, 2), 0.384615, TOLERANCE);
}

TEST(MatrixInverse, Matrix_4x4)
{
    // Arrange
    MLib::Matrix<float, 4, 4> matrix{1, 0, 0, 1,
                                     0, 2, 1, 2,
                                     2, 1, 0, 1,
                                     2, 0, 1, 4};
    // Act
    MLib::Matrix<float, 4, 4> inverse = MLib::Invert(matrix);
    // Assert
    EXPECT_NEAR(inverse(0, 0), -2, TOLERANCE);
    EXPECT_NEAR(inverse(0, 1), -0.5, TOLERANCE);
    EXPECT_NEAR(inverse(0, 2), 1, TOLERANCE);
    EXPECT_NEAR(inverse(0, 3), 0.5, TOLERANCE);

    EXPECT_NEAR(inverse(1, 0), 1, TOLERANCE);
    EXPECT_NEAR(inverse(1, 1), 0.5, TOLERANCE);
    EXPECT_NEAR(inverse(1, 2), 0, TOLERANCE);
    EXPECT_NEAR(inverse(1, 3), -0.5, TOLERANCE);

    EXPECT_NEAR(inverse(2, 0), -8, TOLERANCE);
    EXPECT_NEAR(inverse(2, 1), -1, TOLERANCE);
    EXPECT_NEAR(inverse(2, 2), 2, TOLERANCE);
    EXPECT_NEAR(inverse(2, 3), 2, TOLERANCE);

    EXPECT_NEAR(inverse(3, 0), 3, TOLERANCE);
    EXPECT_NEAR(inverse(3, 1), 0.5, TOLERANCE);
    EXPECT_NEAR(inverse(3, 2), -1, TOLERANCE);
    EXPECT_NEAR(inverse(3, 3), -0.5, TOLERANCE);
}
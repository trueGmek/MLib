#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h> 

using ::testing::ElementsAre;

TEST(MatrixLU, decomposition_1)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{2, -1, -2,
                                     -4, 6, 3,
                                     -4, -2, 8};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0, 0,
                                        -2, 1, 0,
                                        -2, -1, 1));

    EXPECT_THAT(U.values(), ElementsAre(2, -1, -2,
                                        0, 4, -1,
                                        0, 0, 3));

    EXPECT_THAT(matrix.values(), (L * U).values());
}

TEST(MatrixLU, decomposition_2)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{2, 7, 1,
                                     3, -2, 0,
                                     1, 5, 3};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0, 0,
                                        1.5, 1, 0,
                                        0.5, -0.12, 1));

    EXPECT_THAT(U.values(), ElementsAre(2, 7, 1,
                                        0, -12.5, -1.5,
                                        0, 0, 2.32));

    EXPECT_THAT(matrix.values(), (L * U).values());
}

TEST(MatrixLU, decomposition_3)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{2, 1,
                                     -4, -6};

    MLib::Matrix<float, 2, 2> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0,
                                        -2, 1));

    EXPECT_THAT(U.values(), ElementsAre(2, 1,
                                        0, -4));

    EXPECT_THAT(matrix.values(), (L * U).values());
}
TEST(MatrixLU, decomposition_4)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{2, 1, -4,
                                     2, 2, -2,
                                     6, 3, -11};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0, 0,
                                        1, 1, 0,
                                        3, 0, 1));

    EXPECT_THAT(U.values(), ElementsAre(2, 1, -4,
                                        0, 1, 2,
                                        0, 0, 1));

    EXPECT_THAT(matrix.values(), (L * U).values());
}
TEST(MatrixLU, decomposition_5)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{1, 3, 2,
                                     2, 8, 5,
                                     1, 11, 4};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0, 0,
                                        2, 1, 0,
                                        1, 4, 1));

    EXPECT_THAT(U.values(), ElementsAre(1, 3, 2,
                                        0, 2, 1,
                                        0, 0, -2));

    EXPECT_THAT(matrix.values(), (L * U).values());
}

TEST(MatrixLU, decomposition_6)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{2, 3, 2,
                                     2, 8, 5,
                                     1, 11, 4};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(matrix.values(), (L * U).values());
}

TEST(MatrixLU, decomposition_7)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{1, 2, 3,
                                     0, 1, 4,
                                     5, 6, 0};

    MLib::Matrix<float, 3, 3> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(matrix.values(), (L * U).values());
}

TEST(MatrixLU, decomposition_8)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{1, 2,
                                     3, 4};

    MLib::Matrix<float, 2, 2> L{}, U{};
    // Act
    MLib::Decompose_LU(matrix, L, U);
    // Assert
    EXPECT_THAT(L.values(), ElementsAre(1, 0,
                                        3, 1));

    EXPECT_THAT(U.values(), ElementsAre(1, 2,
                                        0, -2));
}

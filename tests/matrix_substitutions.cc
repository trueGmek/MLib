
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>

using ::testing::ElementsAre;

TEST(Matrix_forward_substitution, forward_substitution_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> L{1, 0,
                                2, 1};

    MLib::Matrix<float, 2, 1> values{5, 13};

    // Act
    MLib::Matrix<float, 2, 1> results{MLib::ForwardSubstitution(L, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(5, 3));
}

TEST(Matrix_forward_substitution, forward_substitution_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> L{1, 0, 0,
                                3, 1, 0,
                                1, 1, 1};

    MLib::Matrix<float, 3, 1> values{1, 5, 6};

    // Act
    MLib::Matrix<float, 3, 1> results{MLib::ForwardSubstitution(L, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(1, 2, 3));
}

TEST(Matrix_forward_substitution, forward_substitution_4x4)
{
    // Arrange
    MLib::Matrix<float, 4, 4> L{1, 0, 0, 0,
                                -10, 1, 0, 0,
                                -5, -2, 1, 0,
                                1, 1, 1, 1};

    MLib::Matrix<float, 4, 1> values{1, -8, -6, 10};

    // Act
    MLib::Matrix<float, 4, 1> results{MLib::ForwardSubstitution(L, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(1, 2, 3, 4));
}

TEST(Matrix_forward_substitution, forward_substitution_5x5)
{
    // Arrange
    MLib::Matrix<float, 5, 5> L{1, 0, 0, 0, 0,
                                1, 1, 0, 0, 0,
                                1, 2, 1, 0, 0,
                                5, -1, -1, 1, 0,
                                1, 1, -1, 1, 1};

    MLib::Matrix<float, 5, 1> values{1, 3, 8, 4, 9};

    // Act
    MLib::Matrix<float, 5, 1> results{MLib::ForwardSubstitution(L, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(1, 2, 3, 4, 5));
}

TEST(Matrix_forward_substitution, forward_substitution_6x6)
{
    // Arrange
    MLib::Matrix<float, 6, 6> L{1, 0, 0, 0, 0, 0,
                                1, 1, 0, 0, 0, 0,
                                1, 2, 1, 0, 0, 0,
                                5, -1, -1, 1, 0, 0,
                                1, 1, -1, 1, 1, 0,
                                -1, -1, -1, -1, -1, 1};

    MLib::Matrix<float, 6, 1> values{1, 3, 8, 4, 9, -9};

    // Act
    MLib::Matrix<float, 6, 1> results{MLib::ForwardSubstitution(L, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(1, 2, 3, 4, 5, 6));
}

TEST(Matrix_backward_substitution, backward_substitution_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> U{1, 2,
                                0, 1};

    MLib::Matrix<float, 2, 1> values{4, 1};

    // Act
    MLib::Matrix<float, 2, 1> results{MLib::BackwardSubstitution(U, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(2, 1));
}

TEST(Matrix_backward_substitution, backward_substitution_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> U{1, 2, 3,
                                0, 1, 2,
                                0, 0, 1};

    MLib::Matrix<float, 3, 1> values{10, 4, 1};

    // Act
    MLib::Matrix<float, 3, 1> results{MLib::BackwardSubstitution(U, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(3, 2, 1));
}

TEST(Matrix_backward_substitution, backward_substitution_4x4)
{

    // Arrange
    MLib::Matrix<float, 4, 4> U{1, 2, 3, 4,
                                0, 1, 2, 3,
                                0, 0, 1, 2,
                                0, 0, 0, 1};

    MLib::Matrix<float, 4, 1> values{20, 10, 4, 1};

    // Act
    MLib::Matrix<float, 4, 1> results{MLib::BackwardSubstitution(U, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(4, 3, 2, 1));
}

TEST(Matrix_backward_substitution, backward_substitution_5x5)
{

    // Arrange
    MLib::Matrix<float, 5, 5> U{1, -3, 5, 7, 9,
                                0, 1, 3, 5, -7,
                                0, 0, 1, 3, 5,
                                0, 0, 0, 1, 3,
                                0, 0, 0, 0, 1};

    MLib::Matrix<float, 5, 1> values{31, 16, 14, 5, 1};

    // Act
    MLib::Matrix<float, 5, 1> results{MLib::BackwardSubstitution(U, values)};

    //Assert
    EXPECT_THAT(results.values(), ElementsAre(5, 4, 3, 2, 1));
}
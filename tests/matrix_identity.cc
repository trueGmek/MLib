
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>

using ::testing::ElementsAre;

TEST(MatrixIdentity, identity_2x2)
{
    // Arrange
    MLib::Matrix<float, 2, 2> matrix{MLib::Identity<float, 2>()};

    EXPECT_THAT(matrix.values(), ElementsAre(1, 0,
                                             0, 1));
}

TEST(MatrixIdentity, identity_3x3)
{
    // Arrange
    MLib::Matrix<float, 3, 3> matrix{MLib::Identity<float, 3>()};

    EXPECT_THAT(matrix.values(), ElementsAre(1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1));
}

TEST(MatrixIdentity, identity_4x4)
{
    // Arrange
    MLib::Matrix<float, 4, 4> matrix{MLib::Identity<float, 4>()};

    EXPECT_THAT(matrix.values(), ElementsAre(1, 0, 0, 0,
                                             0, 1, 0, 0,
                                             0, 0, 1, 0,
                                             0, 0, 0, 1));
}
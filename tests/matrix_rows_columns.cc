
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <matrix.h>
#include <array>

using ::testing::ElementsAre;

TEST(MatrixRowsFunction, row_0)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 1, 3> row = matrix.row(0);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(1, 2, 3));
}

TEST(MatrixRowsFunction, row_1)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 1, 3> row = matrix.row(1);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(4, 5, 6));
}

TEST(MatrixRowsFunction, row_3)
{
    // Arrange
    MLib::Matrix<int, 2, 4> matrix{1, 2, 3, 4,
                                   5, 6, 7, 8};
    // Act
    MLib::Matrix<int, 1, 4> row = matrix.row(0);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(1, 2, 3, 4));
}

TEST(MatrixRowsFunction, row_4)
{
    // Arrange
    MLib::Matrix<int, 2, 4> matrix{1, 2, 3, 4,
                                   5, 6, 7, 8};
    // Act
    MLib::Matrix<int, 1, 4> row = matrix.row(1);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(5, 6, 7, 8));
}
TEST(MatrixRowsFunction, row_5)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 1, 3> row = matrix.row(0);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(1, 2, 3));
}

TEST(MatrixRowsFunction, row_6)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 1, 3> row = matrix.row(1);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(4, 5, 6));
}

TEST(MatrixRowsFunction, row_7)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 1, 3> row = matrix.row(2);
    // Assert
    EXPECT_THAT(row.values(), ElementsAre(7, 8, 9));
}

TEST(MatrixColumnsFunction, columns_0)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 2, 1> columns = matrix.column(0);
    // Assert
    EXPECT_THAT(columns.values(), ElementsAre(1, 4));
}

TEST(MatrixColumnsFunction, columns_1)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 2, 1> columns = matrix.column(1);
    // Assert
    EXPECT_THAT(columns.values(), ElementsAre(2, 5));
}

TEST(MatrixColumnsFunction, columns_2)
{
    // Arrange
    MLib::Matrix<int, 2, 3> matrix{1, 2, 3,
                                   4, 5, 6};
    // Act
    MLib::Matrix<int, 2, 1> columns = matrix.column(2);
    // Assert
    EXPECT_THAT(columns.values(), ElementsAre(3, 6));
}

TEST(MatrixColumnsFunction, columns_3)
{
    // Arrange
    MLib::Matrix<int, 4, 2> matrix{1, 2,
                                   3, 4,
                                   5, 6,
                                   7, 8};
    // Act
    MLib::Matrix<int, 4, 1> column = matrix.column(0);
    // Assert
    EXPECT_THAT(column.values(), ElementsAre(1, 3, 5, 7));
}

TEST(MatrixColumnsFunction, columns_4)
{
    // Arrange
    MLib::Matrix<int, 4, 2> matrix{1, 2,
                                   3, 4,
                                   5, 6,
                                   7, 8};
    // Act
    MLib::Matrix<int, 4, 1> column = matrix.column(1);
    // Assert
    EXPECT_THAT(column.values(), ElementsAre(2, 4, 6, 8));
}
TEST(MatrixColumnsFunction, column_5)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 3, 1> column = matrix.column(0);
    // Assert
    EXPECT_THAT(column.values(), ElementsAre(1, 4, 7));
}

TEST(MatrixColumnsFunction, column_6)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 3, 1> column = matrix.column(1);
    // Assert
    EXPECT_THAT(column.values(), ElementsAre(2, 5, 8));
}

TEST(MatrixColumnsFunction, column_7)
{
    // Arrange
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3,
                                   4, 5, 6,
                                   7, 8, 9};
    // Act
    MLib::Matrix<int, 3, 1> column = matrix.column(2);
    // Assert
    EXPECT_THAT(column.values(), ElementsAre(3, 6, 9));
}

TEST(MatrixInsertRowFunction, insert_row_1)
{

    // Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    // Act
    matrix.insertRow({1, 1, 1}, 0);
    // Assert
    EXPECT_THAT(matrix.values(), ElementsAre(1, 1, 1,
                                             0, 0, 0,
                                             0, 0, 0));
}

TEST(MatrixInsertRowFunction, insert_row_2)
{

    // Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    // Act
    matrix.insertRow({1, 1, 1}, 1);
    // Assert
    EXPECT_THAT(matrix.values(), ElementsAre(0, 0, 0,
                                             1, 1, 1,
                                             0, 0, 0));
}

TEST(MatrixInsertRowFunction, insert_row_3)
{

    // Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    // Act
    matrix.insertRow({1, 1, 1}, 2);
    // Assert
    EXPECT_THAT(matrix.values(), ElementsAre(0, 0, 0,
                                             0, 0, 0,
                                             1, 1, 1));
}

TEST(MatrixInsertColumnFunction, insert_column_1)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    //Act
    matrix.insertColumn({1, 1, 1}, 0);
    //Assert
    EXPECT_THAT(matrix.values(), ElementsAre(1, 0, 0,
                                             1, 0, 0,
                                             1, 0, 0));
}

TEST(MatrixInsertColumnFunction, insert_column_2)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    //Act
    matrix.insertColumn({1, 1, 1}, 1);
    //Assert
    EXPECT_THAT(matrix.values(), ElementsAre(0, 1, 0,
                                             0, 1, 0,
                                             0, 1, 0));
}

TEST(MatrixInsertColumnFunction, insert_column_3)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix{};
    //Act
    matrix.insertColumn({1, 1, 1}, 2);
    //Assert
    EXPECT_THAT(matrix.values(), ElementsAre(0, 0, 1,
                                             0, 0, 1,
                                             0, 0, 1));
}
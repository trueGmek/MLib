#include <gtest/gtest.h>
#include <matrix.h> 
#include <string>
#include <iostream>

TEST(MatrixDefaultConstructorTest, def3x3Int)
{
    //Arrange
    MLib::Matrix<int, 3, 3> matrix;
    //Act
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixDefaultConstructorTest, def3x3Float)
{
    //Arrange
    MLib::Matrix<float, 3, 3> matrix;
    //Act
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixDefaultConstructorTest, def3x3sizet)
{
    //Arrange
    MLib::Matrix<size_t, 3, 3> matrix;
    //Act
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixDefaultConstructorTest, def3x3bool)
{
    //Arrange
    MLib::Matrix<bool, 3, 3> matrix;
    //Act
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array3x3Int9elements_direct)
{
    //Arrange
    std::array<int, 9> array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //Act
    MLib::Matrix<int, 3, 3> matrix{array};
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array_3x3Int_3elements_direct)
{
    //Arrange
    std::array<int, 9> array{1, 2, 3};
    //Act
    MLib::Matrix<int, 3, 3> matrix{array};
    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array_3x3Int_0elements_direct)
{
    //Arrange
    std::array<int, 9> array{};
    //Act
    MLib::Matrix<int, 3, 3> matrix{array};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array_3x3Int_0elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{{}};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array_3x3Int_4elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{{1, 2, 3, 4}};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixArrayConstructorTest, array_3x3Int_9elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixInitializerListConstructorTest, list_3x3Int_9elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixInitializerListConstructorTest, list_3x3Int_3elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{1, 2, 3};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}

TEST(MatrixInitializerListConstructorTest, list_3x3Int_0elements_indirect)
{
    //Arrange
    //Act
    MLib::Matrix<int, 3, 3> matrix{};

    //Assert
    SUCCEED();
    std::cout << matrix.ToString() << std::endl;
}
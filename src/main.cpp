#include <iostream>
#include <array>
#include <matrix.h>

int main()
{
    std::array<int, 9> a1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MLib::Matrix<int, 3, 3> m{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << m.ToString() << std::endl;

    return 0;
}

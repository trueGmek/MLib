#pragma once

#include <array>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <math.h>
#include <cassert>


namespace MLib
{
    template <class Type_, size_t Rows_, size_t Columns_>
    class Matrix
    {
        static_assert(Rows_ > 0, "Rows have to be > 0");
        static_assert(Columns_ > 0, "Columns have to be > 0");
        static_assert(std::is_arithmetic_v<Type_> == true, "Type has to be arithetic");

    private:
        size_t _rows{Rows_};
        size_t _columns{Columns_};
        std::array<Type_, Rows_ * Columns_> m_values;

        int getMultIndex(int i, size_t m, size_t columns)
        {
            return m * floor(i / columns);
        }

    public:
        Matrix(std::array<Type_, Rows_ * Columns_> v) : m_values{v}
        {
        }

        Matrix() : m_values{std::array<Type_, Rows_ * Columns_>()}
        {
        }

        // TODO: Add assert for incorrect number of arguments
        Matrix(std::initializer_list<Type_> list)
        {
            int count{0};

            for (Type_ element : list)
            {
                m_values[count++] = element;
            }
        }

        ~Matrix()
        {
            std::cout << "Destroying matrix" << std::endl;
            std::cout << this->ToString() << std::endl;
        }

        std::array<Type_, Rows_ * Columns_> values() const
        {
            return m_values;
        }

        Matrix<Type_, 1, Columns_> row(int index) const
        {
            Matrix<Type_, 1, Columns_> row{};
            size_t offset = index * Columns_;

            for (size_t i = 0; i < Columns_; i++)
            {
                row(0, i) = m_values[i + offset];
            }

            return row;
        }
        void insertRow(std::array<Type_, Rows_> row, size_t index)
        {
            size_t offset = index * Columns_;

            for (size_t i = 0; i < Columns_; i++)
            {
                m_values[i + offset] = row[i];
            }
        }

        Matrix<Type_, Rows_, 1> column(int index) const
        {
            Matrix<Type_, Rows_, 1> column{};

            for (size_t i = 0; i < Rows_; i++)
            {
                column(i, 0) = m_values[i * Columns_ + index];
            }

            return column;
        }

        void insertColumn(std::array<Type_, Columns_> column, size_t index)
        {
            for (size_t i = 0; i < Rows_; i++)
            {
                m_values[i * Columns_ + index] = column[i];
            }
        }

        std::string ToString() const
        {
            std::string str{};
            size_t sizeT = sizeof(Type_);

            for (size_t row = 0; row < _rows; row++)
            {
                for (size_t column = 0; column < _columns; column++)
                {
                    str += std::to_string(m_values[row * _columns + column]);
                    str += '\t';
                }
                str += '\n';
            }

            return str;
        }

        bool IsInvertable() const
        {
            return true;
        }

        Type_ &operator()(size_t row, size_t column)
        {
            assert(column >= 0 && column < Columns_);
            assert(row >= 0 && row < Rows_);

            return m_values[row * _columns + column];
        }

        Type_ operator()(size_t row, size_t column) const
        {
            assert(column >= 0 && column < Columns_);
            assert(row >= 0 && row < Rows_);

            return m_values[row * _columns + column];
        }

        bool operator==(const Matrix<Type_, Rows_, Columns_> &rhs) const
        {
            std::array<Type_, Rows_ * Columns_> rhs_values{rhs.values()};

            for (size_t i = 0; i < rhs_values.size(); i++)
            {
                if (m_values[i] != rhs_values[i])
                {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Matrix<Type_, Rows_, Columns_> &rhs) const
        {
            std::array<Type_, Rows_ * Columns_> rhs_values{rhs.values()};

            for (size_t i = 0; i < rhs_values.size(); i++)
            {
                if (m_values[i] != rhs_values[i])
                {
                    return true;
                }
            }
            return false;
        }

        Matrix<Type_, Rows_, Columns_> operator+(const Matrix<Type_, Rows_, Columns_> &rhs) const
        {
            std::array<Type_, Rows_ * Columns_> resultValues{};
            std::array<Type_, Rows_ * Columns_> rhsValues{rhs.values()};

            for (size_t i = 0; i < Rows_ * Columns_; i++)
            {
                resultValues[i] = m_values[i] + rhsValues[i];
            }

            return Matrix<Type_, Rows_, Columns_>{resultValues};
        }

        Matrix<Type_, Rows_, Columns_> operator-(const Matrix<Type_, Rows_, Columns_> &rhs) const
        {
            std::array<Type_, Rows_ * Columns_> resultValues{};
            std::array<Type_, Rows_ * Columns_> rhsValues{rhs.values()};

            for (size_t i = 0; i < Rows_ * Columns_; i++)
            {
                resultValues[i] = m_values[i] - rhsValues[i];
            }

            return Matrix<Type_, Rows_, Columns_>{resultValues};
        }

        Matrix<Type_, Rows_, Columns_> operator+(Type_ scalar) const
        {
            std::array<Type_, Rows_ * Columns_> resultValues{};

            for (size_t i = 0; i < Rows_ * Columns_; i++)
            {
                resultValues[i] = m_values[i] + scalar;
            }

            return Matrix<Type_, Rows_, Columns_>{resultValues};
        }

        Matrix<Type_, Rows_, Columns_> operator-(Type_ scalar) const
        {
            std::array<Type_, Rows_ * Columns_> resultValues{};

            for (size_t i = 0; i < Rows_ * Columns_; i++)
            {
                resultValues[i] = m_values[i] - scalar;
            }

            return Matrix<Type_, Rows_, Columns_>{resultValues};
        }

        template <size_t Columns_2>
        Matrix<Type_, Rows_, Columns_2> operator*(const Matrix<Type_, Columns_, Columns_2> &matrix)
        {
            std::array<Type_, Rows_ * Columns_2> resultValues{};
            std::array<Type_, Columns_ * Columns_2> matrixValues{matrix.values()};

            for (size_t i = 0; i < resultValues.size(); i++)
            {
                for (size_t k = 0; k < Columns_; k++)
                {
                    resultValues[i] += m_values[getMultIndex(i, Columns_, Columns_2) + k] * matrixValues[i % Columns_2 + Columns_2 * k];
                }
            }

            return Matrix<Type_, Rows_, Columns_2>{resultValues};
        }
    };

    template <class Type_, size_t Rows_, size_t Columns_>
    static Matrix<Type_, Rows_, Columns_> operator+(Type_ scalar, const Matrix<Type_, Rows_, Columns_> &matrix)
    {
        return matrix + scalar;
    }

    template <class Type_, size_t Rows_, size_t Columns_>
    std::ostream &operator<<(std::ostream &os, const Matrix<Type_, Rows_, Columns_> &matrix)
    {
        return os << matrix.ToString();
    }

    //Returns an identity matrix
    //
    //Example for 3x3 matrix:
    //  ┌─────┐
    //  │1 0 0│
    //  │0 1 0│
    //  │0 0 1│
    //  └─────┘
    template <class Type_, size_t N>
    static Matrix<Type_, N, N> Identity()
    {
        Matrix<Type_, N, N> identity{};

        for (size_t i = 0; i < N; i++)
        {
            identity(i, i) = 1;
        }

        return identity;
    }

    template <class Type_, size_t Rows_, size_t Columns_>
    static Matrix<Type_, Columns_, Rows_> Transpose(const Matrix<Type_, Rows_, Columns_> &matrix)
    {
        std::array<Type_, Rows_ * Columns_> transposedEntries{};
        std::array<Type_, Rows_ * Columns_> inputValues{matrix.values()};
        int k{0};

        for (size_t i = 0; i < Columns_; i++)
        {
            for (size_t j = 0; j < Rows_; j++)
            {
                transposedEntries[k++] = inputValues[i + j * Columns_];
            }
        }

        return Matrix<Type_, Columns_, Rows_>{transposedEntries};
    }

    /* 
    Decomposes a given matrix into two triangular matrices

    Mathematical interpretation:
    ┌─────┐   ┌─────┐   ┌─────┐
    |x x x│   │1 0 0│   │u u u│
    │x x x│ = │l 1 0│ * │0 u u│
    │x x x│   │l l 1│   │0 0 u│
    └─────┘   └─────┘   └─────┘
    */
    template <class Type_, class Type_2, size_t N>
    static void Decompose_LU(const Matrix<Type_, N, N> &matrix,
                             Matrix<Type_2, N, N> &lower,
                             Matrix<Type_2, N, N> &upper)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = i; j < N; j++)
            {
                upper(i, j) = matrix(i, j);

                for (size_t k = 0; k < i; k++)
                {
                    upper(i, j) = upper(i, j) - lower(i, k) * upper(k, j);
                }
            }

            for (size_t j = i; j < N; j++)
            {
                if (i == j)
                    lower(i, i) = 1; // Diagonal as 1
                else
                {
                    lower(j, i) = matrix(j, i);
                    for (size_t k = 0; k < i; k++)
                    {
                        lower(j, i) = lower(j, i) - lower(j, k) * upper(k, i);
                    }

                    lower(j, i) /= upper(i, i);
                }
            }
        }
    }

    /*
    Mathematical interpretation:
        ┌─────┐-1
        │x x x│
        │x x x│
        │x x x│
        └────┘
    */
    template <class Type_, size_t N>
    static Matrix<Type_, N, N> Invert(const Matrix<Type_, N, N> &matrix)
    {
        Matrix<Type_, N, N> identity{Identity<Type_, N>()};

        Matrix<Type_, N, N> L{}, inv_L{};
        Matrix<Type_, N, N> U{}, inv_U{};

        std::array<Type_, N> column_of_inv_L, column_of_inv_U;

        Decompose_LU(matrix, L, U);

        for (size_t i = 0; i < N; i++)
        {
            column_of_inv_L = ForwardSubstitution(L, identity.column(i)).values();
            inv_L.insertColumn(column_of_inv_L, i);

            column_of_inv_U = BackwardSubstitution(U, identity.column(i)).values();
            inv_U.insertColumn(column_of_inv_U, i);
        }

        Matrix<Type_, N, N> invU{inv_U};
        Matrix<Type_, N, N> invL{inv_L};

        return invU * invL;
    }

    template <class Type_, size_t N>
    static float Determinant(const Matrix<Type_, N, N> &matrix)
    {
        Matrix<Type_, N, N> L{}, U{};
        Decompose_LU(matrix, L, U);

        float determinant{1};

        for (size_t i = 0; i < N; i++)
        {
            determinant *= L(i, i) * U(i, i);
        }

        return determinant;
    }

    template <class Type_, size_t Rows_, size_t Columns_>
    static Matrix<Type_, Rows_, 1> ForwardSubstitution(const Matrix<Type_, Rows_, Columns_> &lower,
                                                       const Matrix<Type_, Rows_, 1> &values)
    {
        Matrix<Type_, Rows_, 1> solutions{};
        float sum{0};

        solutions(0, 0) = values(0, 0) / lower(0, 0);

        for (size_t m = 1; m < Rows_; m++)
        {
            sum = 0;
            for (size_t i = 0; i < m; i++)
            {
                sum += lower(m, i) * solutions(i, 0);
            }

            solutions(m, 0) = (values(m, 0) - sum) / lower(m, m);
        }

        return solutions;
    }

    template <class Type_, size_t Rows_, size_t Columns_>
    static Matrix<Type_, Rows_, 1> BackwardSubstitution(const Matrix<Type_, Rows_, Columns_> &upper,
                                                        const Matrix<Type_, Rows_, 1> &values)
    {
        Matrix<Type_, Rows_, 1> solutions{};
        float sum{0};

        solutions(Rows_ - 1, 0) = values(Rows_ - 1, 0) / upper(Rows_ - 1, Rows_ - 1);

        for (int i = Rows_ - 2; i >= 0; i--)
        {
            sum = 0;
            for (size_t k = i + 1; k < Rows_; k++)
            {
                sum += upper(i, k) * solutions(k, 0);
            }

            solutions(i, 0) = (values(i, 0) - sum) / upper(i, i);
        }

        return solutions;
    }
} // MLib

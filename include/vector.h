// #include <array>
// #include <initializer_list>

// namespace MLib
// {
//     template <class Type_, size_t Size_>
//     class Vector : Matrix
//     {
//     private:
//         std::array<Type_, Size_> m_values;

//     public:
//         Vector() : m_values{std::array<Type_, Size_>{}}
//         {

//         }

//         Vector(std::array<Type_, Size_> v) : m_values{v}
//         {
//         }

//         // TODO: Add assert for incorrect number of arguments
//         Vector(std::initializer_list<Type_> list)
//         {
//             int count{0};

//             for (Type_ element : list)
//             {
//                 m_values[count++] = element;
//             }
//         }

//         ~Vector()
//         {
//             std::cout << "Destroying vector" << std::endl;
//             std::cout << m_values << std::endl;
//         }
//     };
// }
#include "../Array2D.h"
#include <iostream>

using namespace CARAMEL2026;

int main()
{
    Array2D array("tests/good_array.txt");

    for(size_t i=0; i<array.get_ni(); ++i)
    {
        for(size_t j=0; j<array.get_nj(); ++j)
            std::cout << array(i, j) << ' ';
        std::cout << std::endl;
    }

    try
    {
        Array2D bad_array("tests/bad_array.txt");
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "Exception occurred as expected with bad_array.txt" << std::endl;
    }

    return 0;
}


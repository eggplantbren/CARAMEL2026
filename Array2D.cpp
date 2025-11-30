#include "Array2D.h"
#include <fstream>

namespace CARAMEL2026
{

Array2D::Array2D(size_t ni, size_t nj)
:ni(ni)
,nj(nj)
,values(ni*nj)
{

}

Array2D::Array2D(const std::string& filename)
{
    std::ifstream fin(filename);

    if(!fin)
        throw std::runtime_error("Cannot open file " + filename);

    // TODO: Implement this

    fin.close();
}


const double& Array2D::operator()(size_t i, size_t j) const
{
    return values[i*nj + j];
}

double& Array2D::operator()(size_t i, size_t j)
{
    return values[i*nj + j];
}

} // namespace

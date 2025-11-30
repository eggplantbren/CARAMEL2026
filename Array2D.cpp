#include "Array2D.h"
#include <fstream>
#include <sstream>

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
    std::string line;
    std::vector<double> temp_data;

    // Initialise row count
    ni = 0;

    // Load the lines
    while(std::getline(fin, line))
    {
        // Skip empty lines
        if(line.empty())
            continue;

        // The line as a stringstream
        std::istringstream iss(line);

        double val;
        size_t num_values_in_line = 0;

        // Read values into the vector
        while(iss >> val)
        {
            ++num_values_in_line;
            values.push_back(val);
        }

        // If this was the first row, save number of columns
        if(ni == 0)
            nj = num_values_in_line;
        else if(num_values_in_line != nj)
        {
            std::string msg = "Inconsistent number of values on line in file "
                                + filename;
            throw std::runtime_error(msg);
        }

        // Incremement number of rows
        ++ni;
    }



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

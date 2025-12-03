#include "Continuum.h"
#include <fstream>
#include <iostream>

namespace CARAMEL2026
{


void Continuum::load_data(const std::string& filename)
{
    t.clear();
    y.clear();
    sig.clear();

    std::ifstream fin(filename);
    if(!fin)
        throw std::runtime_error("Couldn't open file " + filename + ".");

    double t_, y_, sig_;
    while(fin >> t_ && fin >> y_ && fin >> sig_)
    {
        t.push_back(t_);
        y.push_back(y_);
        sig.push_back(sig_);
    }
    std::cout << "Loaded " << t.size() << " data points from continuum file ";
    std::cout << filename << "." << std::endl;

    fin.close();
}












} // namespace

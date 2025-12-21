#include "Continuum.h"
#include <fstream>
#include <iostream>
#include <algorithm>

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

    // Compute summaries of data
    t_range = *std::max_element(t.begin(), t.end())
                - *std::min_element(t.begin(), t.end());

    double ytot = 0.0;
    double wtot = 0.0;
    for(size_t i=0; i<y.size(); ++i)
    {
        ytot += y[i];
        wtot += std::pow(sig[i], -2);
    }
    weighted_average_y = ytot/wtot;

    std::cout << "t_range = " << t_range << ".\n";
    std::cout << "weighted_average_y = " << weighted_average_y << '.';
    std::cout << std::endl;
}



void Continuum::from_prior(DNest4::RNG& rng)
{
    


    // Jitter is in magnitudes. Prior median is 0.5 magnitudes
    jitter = std::exp(std::log(0.5) + 3.0*rng.randn());
}


double Continuum::perturb(DNest4::RNG& rng)
{
    double logH = 0.0;
    

    return logH;
}






} // namespace

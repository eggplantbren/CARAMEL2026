#ifndef CARAMEL2026_Continuum_h
#define CARAMEL2026_Continuum_h

#include <RNG.h>
#include <string>
#include <vector>

namespace CARAMEL2026
{

/*
*    An object of this class contains a continuum dataset
*    as well as parameters of the CAR(1) fit to that dataset.
*/

class Continuum
{
    private:

        // GP hyperparameters
        double mu;
        double L;
        double alpha;
        double beta;
        double jitter;

        // The data
        std::vector<double> t, y, sig;

        // Summaries of data
        double weighted_average_y;
        double t_range;

    public:

        void load_data(const std::string& filename);
        void from_prior(DNest4::RNG& rng);
        double perturb(DNest4::RNG& rng);

};

} // namespace

#endif

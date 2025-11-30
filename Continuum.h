#ifndef CARAMEL2026_Continuum_h
#define CARAMEL2026_Continuum_h

#include <string>
#include <vector>

namespace CARAMEL2026
{

class Continuum
{
    private:

        // GP hyperparameters
        double mu;
        double L;
        double alpha;
        double beta;

        // The data
        std::vector<double> t, y, sig;

    public:

        void load_data(const std::string& filename);


};

} // namespace

#endif

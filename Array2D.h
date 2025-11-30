#ifndef CARAMEL2026_Array2D_h
#define CARAMEL2026_Array2D_h

#include <string>
#include <vector>

namespace CARAMEL2026
{

class Array2D
{
    private:
        size_t ni, nj;
        std::vector<double> values;

    public:
        Array2D() = delete;
        Array2D(size_t ni, size_t nj);
        Array2D(const std::string& filename);

        // Accessors
        const double& operator()(size_t i, size_t j) const;
        double& operator()(size_t i, size_t j);

        // Getters
        size_t get_ni() const { return ni; }
        size_t get_nj() const { return nj; }
};

} // namespace

#endif

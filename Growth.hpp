#ifndef GROWTH_HPP
#define GROWTH_HPP

#include <cmath>

namespace cstar {

    namespace growth {

        /**
         * von Bertalanffy growth model
         *
         * @param Linf - largest size (asymptote)
         * @param a0   - age at size 0
         * @param a    - age
         * @param k    - growth rate
         * @return 
         */
        template<typename T>
        const T Bertalanffy(const T& Linf, const T& a0, const T& a, const T& k) {
            return Linf * (1.0 - std::exp(-k * (a - a0)));
        }

        /**
         * von Bertalanffy update growth model
         *
         * @param Linf   - largest size (asymptote)
         * @param L_prev - previous size
         * @param a_prev - age at previous size
         * @param a      - age
         * @param k      - growth rate
         * @return
         */
        template<typename T>
        const T Bertalanffy_update(const T& Linf, const T& L_prev, const T& a_prev, const T& a, const T& k) {
            return Linf + ((L_prev - Linf) * std::exp(-k * (a - a_prev)));
        }

        /**
         * Richards growth model
         * 
         * @param alpha - upper asymptote
         * @param beta  - growth range
         * @param a     - age
         * @param k     - growth rate
         * @param m     - slope
         * @return 
         */
        template<typename T>
        const T Richards(const T& alpha, const T& beta, const T& a, const T& k, const T& m) {
            return alpha /std::pow((1.0 + beta * std::exp(-k * a)), (1.0 / m));
        }

        /**
         * Schnute growth model
         * 
         * @param a     - age
         * @param r0    - reference value
         * @param beta  - growth displacement
         * @param k     - growth rate
         * @param m     - slope
         * @return 
         */
        template<typename T>
        const T Schnute(const T& a, const T& r0, const T& beta, const T& k, const T& m) {
            return std::pow((r0 + beta * std::exp(k * a)), m);
        }
    }

}

#endif /* GROWTH_HPP */

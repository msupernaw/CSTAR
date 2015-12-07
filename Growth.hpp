#ifndef GROWTH_HPP
#define GROWTH_HPP

#include <cmath>

namespace cstar {


    namespace growth {

        /**
         * Logistic growth model.
         * 
         * @param P0 - initial population size
         * @param t  - time
         * @param k  - relative growth rate
         * @param K  - carrying capacity
         * @param c  - harvest rate, default = 0
         * 
         * @return 
         */
        template<typename T>
        const T Logistic(const T& P0, const T& t, const T& k, const T& K, T c = T(0)) {
            return K / (1.0 + ((K - P0) / P0) * std::exp(-k * t));
        }

        /**
         * 
         * @param Linf
         * @param t0
         * @param t
         * @param K
         * @return 
         */
        template<typename T>
        const T Bertalanffy(const T& Linf, const T& t0, const T& t, const T& K) {
            return Linf * (1.0 - std::exp(-K * (t - t0)));
        }

        /**
         * Gompertz growth model
         * 
         * @param alpha - upper asymptote
         * @param beta  - growth displacement
         * @param t     - time 
         * @param k     - growth rate
         * @return 
         */
        template<typename T>
        const T Gompertz(const T& alpha, const T& beta, const T& t, const T& k) {
            return alpha * std::exp(-beta * exp(-k * t));
        }

        /**
         * Richard growth model
         * 
         * @param alpha - upper asymptote
         * @param beta  - growth range
         * @param t     - time
         * @param k     - growth rate
         * @param m     - slope
         * @return 
         */
        template<typename T>
        const T Richard(const T& alpha, const T& beta, const T& t, const T& k, const T& m) {
            return alpha /std::pow((1.0 + beta * std::exp(-k * t)), (1.0 / m));
        }

        /**
         * Schnute growth model
         * 
         * @param t     - time
         * @param r0    - reference value
         * @param beta  - growth displacement
         * @param k     - growth rate
         * @param m     - slope
         * @return 
         */
        template<typename T>
        const T Schnute(const T& t, const T& r0, const T& beta, const T& k, const T& m) {
            return std::pow((r0 + beta * std::exp(k * t)), m);
        }
    }


}

#endif /* GROWTH_HPP */

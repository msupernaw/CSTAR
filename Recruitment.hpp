
#ifndef RECRUITMENT_HPP
#define RECRUITMENT_HPP

namespace cstar {

    namespace recruitment {

        /**
         * 
         * @param alpha -
         * @param beta  -
         * @param S     - number of spawners (adult fish)
         * @return 
         */
        template<typename T>
        const T Ricker(const T& alpha, const T& beta, const T& S) {
            return alpha * S * std::exp(-1.0 * beta * S);
        }

        /**
         * 
         * @param alpha  - maximum recruitment 
         * @param beta   - the stock level needed to produce the half of maximum recruitment
         * @param S      - 
         * @return 
         */
        template<typename T>
        const T BevertonHolt(const T& alpha, const T& beta, const T& S) {
            return (alpha * S) / (beta + S);
        }

        /**
         * 
         * @param alpha
         * @param beta
         * @param c
         * @param S
         * @return 
         */
        template<typename T>
        const T Shepard(const T& alpha, const T& beta, const T& c, const T& S) {
            return alpha * (S * S) / (1 + std::pow((S / beta), c));
        }

        /**
         * 
         * @param alpha
         * @param beta
         * @param c
         * @param S
         * @return 
         */
        template<typename T>
        const T DiRiso(const T& alpha, const T& beta, const T& c, const T& S) {
            return (alpha * S) *std::pow((1.0 - beta*c*S),1.0/c);
        }


    }
}

#endif /* RECRUITMENT_HPP */


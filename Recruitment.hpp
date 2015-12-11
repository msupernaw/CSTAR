
#ifndef RECRUITMENT_HPP
#define RECRUITMENT_HPP

namespace cstar {

    namespace recruitment {

        /**
         * Ricker S-R relationship
         *
         * @param alpha -
         * @param beta  -
         * @param S     - spawning biomass or abundance
         * @return 
         */
        template<typename T>
        const T Ricker(const T& alpha, const T& beta, const T& S) {
            return alpha * S * std::exp(-1.0 * beta * S);
        }

        /**
         * Alternative Ricker S-R relationship
         *
         * @param R0   - unfished equilibrium recruitment
         * @param phi0 - unfished spawning biomass or abundance per recruit
         * @param A    - adjustment factor
         * @param S    - spawning biomass or abundance
         * @return
         */
        template<typename T>
        const T Ricker_alt(const T& R0, const T& phi0, const T& A, const T& S) {
            return (S / phi0) * std::exp(A * (1.0 - (S / (phi0 * R0))));
        }

        /**
         * Beverton-Holt S-R relationship
         *
         * @param alpha  - maximum recruitment
         * @param beta   - the stock level needed to produce the half of maximum recruitment
         * @param S      - spawning biomass or abundance
         * @return
         */
        template<typename T>
        const T BevertonHolt(const T& alpha, const T& beta, const T& S) {
            return (alpha * S) / (beta + S);
        }

        /**
         * Alternative Beverton-Holt S-R relationship
         *
         * @param R0   - unfished equilibrium recruitment
         * @param phi0 - unfished spawning biomass or abundance per recruit
         * @param h    - steepness
         * @param S    - spawning biomass or abundance
         * @return 
         */
        template<typename T>
        const T BevertonHolt_alt(const T& R0, const T& phi0, const T& h, const T& S) {
            return (4.0 * R0 * h * S) / ((phi0 * R0 * (1.0 - h)) + (S * (5.0 * h - 1.0)));
        }

        /**
         * Depensatory Beverton-Holt S-R relationship
         *
         * @param alpha - maximum recruitment
         * @param beta  - the stock level needed to produce the half of maximum recruitment
         * @param c     - exponent
         * @param S     - spawning biomass or abundance
         * @return
         */
        template<typename T>
        const T BevertonHolt_dep(const T& alpha, const T& beta, const T& c, const T& S) {
            T S_c = std::pow(S,c);
            return (alpha * S_c) / (beta + S_c);
        }

        /**
         * Shepherd S-R relationship
         *
         * @param alpha -
         * @param beta  -
         * @param c     - exponent
         * @param S     - spawning biomass or abundance
         * @return 
         */
        template<typename T>
        const T Shepherd(const T& alpha, const T& beta, const T& c, const T& S) {
            return (alpha * S) / (1.0 + std::pow((S / beta), c));
        }

        /**
         * Deriso S-R relationship
         * 
         * @param alpha -
         * @param beta  -
         * @param c     - exponent
         * @param S     - spawning biomass or abundance
         * @return 
         */
        template<typename T>
        const T Deriso(const T& alpha, const T& beta, const T& c, const T& S) {
            return (alpha * S) * std::pow((1.0 - beta*c*S),1.0/c);
        }
    }
}

#endif /* RECRUITMENT_HPP */


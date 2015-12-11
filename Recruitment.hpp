
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
         * @param alpha -
         * @param beta  -
         * @param S     - spawning biomass or abundance
         * @return
         */
        template<typename T>
        const T Ricker_alt(const T& alpha, const T& beta, const T& S) {
            return alpha * S * std::exp(-1.0 * beta * S);
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
         * @param alpha  - maximum recruitment 
         * @param beta   - the stock level needed to produce the half of maximum recruitment
         * @param S      - spawning biomass or abundance
         * @return 
         */
        template<typename T>
        const T BevertonHolt_alt(const T& alpha, const T& beta, const T& S) {
            return (alpha * S) / (beta + S);
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
         * @param alpha
         * @param beta
         * @param c
         * @param S
         * @return 
         */
        template<typename T>
        const T Deriso(const T& alpha, const T& beta, const T& c, const T& S) {
            return (alpha * S) * std::pow((1.0 - beta*c*S),1.0/c);
        }
    }
}

#endif /* RECRUITMENT_HPP */


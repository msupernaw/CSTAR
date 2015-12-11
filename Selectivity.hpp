
#ifndef SELECTIVITY_HPP
#define SELECTIVITY_HPP

namespace cstar {

    namespace selectivity {

        namespace age {

            /**
             * 
             * Age based logistic selectivity
             * 
             * @param a50 - age of 50% selectivity 
             * @param s   - the rate of increase in selectivity at a50
             * @param a   - age
             * @return 
             */
            template<typename T>
            const T Logistic(const T& a50, const T& s, const T& a) {
                return 1.0 / (1.0 + std::exp(-s * (a - a50)));
            }

            /**
             * Age-based double logistic selectivity
             *
             * @param alpha_asc  - ascending alpha
             * @param beta_asc   - ascending beta
             * @param alpha_desc - descending alpha
             * @param beta_desc  - descending beta
             * @param a          - age
             * @return
             */
            template<typename T>
            const T DoubleLogistic(const T& alpha_asc, const T& beta_asc, const T& alpha_desc, const T& beta_desc, const T& a) {
                return (1.0 / (1.0 + std::exp(-beta_asc * (a - alpha_asc)))) * (1.0 - (1.0 / (1.0 + std::exp(-beta_desc * (a - alpha_desc)))));
            }

            template<typename T>
            const T CubicSpline() {

            }

            template<typename T>
            const T Normal() {

            }

            template<typename T>
            const T DoubleNormal() {

            }

            template<typename T>
            const T ExponentialLogistic() {

            }

            template<typename T>
            const T NonParametric() {

            }
        }

        namespace size {
        
        }
    }
}

#endif /* SELECTIVITY_HPP */


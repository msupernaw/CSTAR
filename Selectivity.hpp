
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

            template<typename T>
            const T DoubleLogistic() {

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
        }

    }

    namespace size{
        
    }

}

#endif /* SELECTIVITY_HPP */


#pragma once
#include "../../Perceptron.h"

namespace lantern
{
    namespace perceptron
    {

        namespace optimizer
        {

            class AdaptiveGradientDescent
            {
            private:
                double learning_rate = 0.01, epsilon = 1e-08;
                uint32_t iteration = 0;

            public:
                AdaptiveGradientDescent(double learning_rate = 0.01, double epsilon = 1e-08) : learning_rate(learning_rate), epsilon(epsilon) {}
                double GetDelta(const double &gradient,lantern::perceptron::Perceptron* node,const uint32_t& child_index)
                {
                    node->stack_prev_gradient[child_index] += pow(node->gradient[child_index],2);
                    return (this->learning_rate / (sqrt(node->stack_prev_gradient[child_index])+this->epsilon)) * gradient;
                }

                void SetIteration(const uint32_t& iter){
                    this->iteration = iter;
                }

                uint32_t GetIteration(){
                    return this->iteration;
                }
            };

        }
    }
}
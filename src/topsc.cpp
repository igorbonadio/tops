#include "topsc.h"

#include <iostream>
#include <vector>

#include "ProbabilisticModelCreatorClient.hpp"

using namespace tops;

extern "C" {

struct CProbabilisticModel* load_probabilistic_model(const char* filename) {
  ProbabilisticModelCreatorClient creator;
  ProbabilisticModelPtr* model = new ProbabilisticModelPtr(creator.create(std::string(filename)));
  return (CProbabilisticModel*)model;
}

double probabilistic_model_evaluate_position(
    struct CProbabilisticModel* self, unsigned int* sequence,
    unsigned int sequence_size, unsigned int i, unsigned int phase) {
  ProbabilisticModelPtr* model = (ProbabilisticModelPtr*)self;
  std::vector<int> s(sequence, sequence + sequence_size);
  return (*model)->evaluatePosition(s, i, phase);
}

void delete_probabilistic_model(struct CProbabilisticModel* self) {
  ProbabilisticModelPtr* model = (ProbabilisticModelPtr*)self;
  delete model;
}

void initialize_prefix_sum_array(struct CProbabilisticModel* self,
    unsigned int* sequence, unsigned int sequence_size, unsigned int phase) {
  ProbabilisticModelPtr* model = (ProbabilisticModelPtr*)self;
  std::vector<int> s(sequence, sequence + sequence_size);
  (*model)->initialize_prefix_sum_array(s);
}

double prefix_sum_array(struct CProbabilisticModel* self, unsigned int begin,
    unsigned int end, unsigned int phase) {
  ProbabilisticModelPtr* model = (ProbabilisticModelPtr*)self;
  double p = (*model)->prefix_sum_array_compute(begin, end, phase);
  // std::cout << "---> " << p << std::endl;
  return p;
}

double probability_of(struct CProbabilisticModel* self, int symbol) {
  ProbabilisticModelPtr* model = (ProbabilisticModelPtr*)self;
  return (*model)->log_probability_of(symbol);
}

}
#ifndef TOPSC_H_
#define TOPSC_H_

extern "C" {

struct CProbabilisticModel* load_probabilistic_model(const char* filename);

double probabilistic_model_evaluate_position(
    struct CProbabilisticModel* self, unsigned int* sequence,
    unsigned int sequence_size, unsigned int i, unsigned int phase);

void initialize_prefix_sum_array(struct CProbabilisticModel* self,
    unsigned int* sequence, unsigned int sequence_size, unsigned int phase);

double prefix_sum_array(struct CProbabilisticModel* self, unsigned int begin,
    unsigned int end, unsigned int phase);

double probability_of(struct CProbabilisticModel* self, int symbol);

}

#endif

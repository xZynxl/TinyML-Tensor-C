#include "tensor.h"

void quantize_data(float* input, int8_t* output, int size, float scale) {
    int i;
    for (i = 0; i < size; i++) {
        output[i] = (int8_t)(input[i] / scale);
    }
}

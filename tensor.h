#ifndef TENSOR_H
#define TENSOR_H
#include <stdint.h>

typedef enum { T_FLOAT32, T_INT8 } TensorType;

typedef union {
    float* f32_ptr;
    int8_t* i8_ptr;
} TensorData;

typedef struct {
    TensorData data;
    TensorType type;
    int size;
    float scale;
} Tensor;

void quantize_data(float* input, int8_t* output, int size, float scale);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

int main() {
    int i;
    int eleman_sayisi = 5;
    float ham_veriler[] = {10.5, 20.2, -5.5, 30.0, 0.5};
    float scale_degeri = 0.5;

    Tensor f_tensor;
    f_tensor.type = T_FLOAT32;
    f_tensor.size = eleman_sayisi;
    f_tensor.data.f32_ptr = (float*)malloc(eleman_sayisi * sizeof(float));

    for(i = 0; i < eleman_sayisi; i++) {
        f_tensor.data.f32_ptr[i] = ham_veriler[i];
    }

    Tensor q_tensor;
    q_tensor.type = T_INT8;
    q_tensor.size = eleman_sayisi;
    q_tensor.data.i8_ptr = (int8_t*)malloc(eleman_sayisi * sizeof(int8_t));

    quantize_data(f_tensor.data.f32_ptr, q_tensor.data.i8_ptr, eleman_sayisi, scale_degeri);

    printf("TinyML Tensor C Uygulamasi (Gomulu Sistemler)\n");
    printf("--------------------------------------------\n");
    for(i = 0; i < eleman_sayisi; i++) {
        printf("Orijinal Float: %.1f -> Quantized Int8: %d\n", f_tensor.data.f32_ptr[i], q_tensor.data.i8_ptr[i]);
    }

    free(f_tensor.data.f32_ptr);
    free(q_tensor.data.i8_ptr);
    
    printf("\nIslem Basarili! Cikmak icin Enter'a basin...");
    getchar();
    return 0;
}

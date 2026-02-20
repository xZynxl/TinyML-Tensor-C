# TinyML Dynamic Tensor Management in C

Bu proje, kaynakları kısıtlı gömülü sistemler (mikrodenetleyiciler) üzerinde Yapay Zeka (TinyML) modellerini çalıştırmak için bellek dostu bir dinamik tensör (Tensor) yapısı sunmaktadır. 

## 📌 Proje Amacı
Standart 32-bit (Float) dizilerin kısıtlı RAM'e sahip cihazlarda yarattığı bellek darboğazını aşmak amacıyla; duruma göre 32-bit Float veya 8-bit Integer (Quantized) verileri aynı bellek alanında saklayabilen bir mimari C dilinde "Agentic Kodlama" yaklaşımıyla geliştirilmiştir.

## ⚙️ Teknik Mimari ve Kullanılan Yapılar
* **Dinamik Tip Yönetimi (Union):** `TensorData` adındaki `union` yapısı sayesinde, bellek üzerinde aynı adres bloğu hem `float*` hem de `int8_t*` pointer'ları tarafından paylaşılır. Bu sayede bellek kullanımı optimize edilmiştir.
* **Tip Güvenliği (Enum & Struct):** Hangi verinin aktif olduğunu takip etmek için `TensorType` enum yapısı ve genel verileri sarmalamak için `Tensor` struct yapısı kullanılmıştır.
* **Quantization (Nicemleme):** Geliştirilen `quantize_data` fonksiyonu, 32-bit kayan noktalı sayıları belirli bir `scale` değeri üzerinden 8-bit tam sayılara dönüştürerek bellek alanından %75 oranında tasarruf sağlar.

## 🚀 Çalıştırma (Build & Run)
Proje modüler bir yapıda (Header ve Source dosyaları ayrılarak) tasarlanmıştır. GCC derleyicisi ile aşağıdaki komut kullanılarak derlenebilir:
`gcc main.c tensor.c -o tinyml_tensor`
`./tinyml_tensor`

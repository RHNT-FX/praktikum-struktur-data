# Hash Table Notes

## Konsep Dasar
- Hash function memetakan key → indeks slot.
- Tujuan: distribusi merata, deterministik, cepat.
- Collision (tabrakan) terjadi bila dua key jatuh ke slot yang sama.

## Separate Chaining
- Setiap slot menyimpan list (linked list/ vector) dari pasangan key-value.
- Insert/search: O(1) rata-rata jika load factor rendah.
- Kelebihan: mudah menangani banyak collision, rehash tidak wajib besar.
- Kekurangan: butuh memori ekstra untuk pointer/list.

## Linear Probing (Open Addressing)
- Semua data disimpan dalam satu array.
- Jika slot penuh, probe slot berikutnya (idx+1, idx+2, ...).
- Perlu status slot (empty/occupied/deleted).
- Load factor tinggi membuat probing panjang (degradasi performa).

## Load Factor
- `load factor = jumlah elemen / kapasitas`.
- Jaga di bawah batas (misal 0.6–0.7); jika melebihi, lakukan rehash (perbesar tabel).

## Perbandingan Singkat
| Metode             | Memori | Kinerja ketika collision | Kesulitan implementasi |
|--------------------|--------|--------------------------|------------------------|
| Separate chaining  | lebih besar (list) | stabil, list panjang jika load tinggi | mudah |
| Linear probing     | hemat (satu array) | degrade saat load tinggi (clustering) | perlu penanganan deleted |

## Penggunaan
- Struktur data set/map (dictionary), cache, counting frequency.
- Di C++ standar: `unordered_map`, `unordered_set` (menggunakan hashing).

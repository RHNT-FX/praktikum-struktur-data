# Perbandingan Linked List vs Array/Vector

## 1. Akses Elemen
- Array/Vector: O(1) — langsung via indeks `arr[i]`
- Linked List: O(n) — harus traverse dari head ke posisi

## 2. Insert di Depan
- Array/Vector: O(n) — perlu geser semua elemen ke kanan
- Linked List: O(1) — cukup ubah pointer `head`

## 3. Insert di Tengah
- Array/Vector: O(n) — geser elemen setelah posisi
- Linked List: O(n) — traverse ke posisi, lalu O(1) untuk sisip pointer

## 4. Delete
- Array/Vector: O(n) — geser elemen setelah posisi
- Linked List: O(n) — traverse ke posisi, lalu O(1) untuk hubungkan ulang pointer

## 5. Memori
- Array/Vector: kontigu di memori (cache-friendly)
- Linked List: tersebar (scattered), ada overhead pointer (prev/next)

## 6. Ukuran Dinamis
- Array/Vector: dapat `resize` (mungkin reallocate & copy)
- Linked List: mudah tambah/kurang node tanpa reallocate blok besar

## Kesimpulan
- Pakai Array/Vector jika butuh akses acak cepat dan ukuran relatif stabil.
- Pakai Linked List jika sering insert/delete di tengah dan ukuran sangat dinamis.

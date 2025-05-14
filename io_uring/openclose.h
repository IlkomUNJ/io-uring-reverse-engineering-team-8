// SPDX-License-Identifier: GPL-2.0

int __io_close_fixed(struct io_ring_ctx *ctx, unsigned int issue_flags,
             unsigned int offset);
/**
 * Tutup file tetap berdasarkan offset.
 * Menangani penutupan file yang terdaftar dalam konteks io_uring.
 */

int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi openat.
 * Menginisialisasi struktur permintaan untuk membuka file.
 */

int io_openat(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi openat.
 * Membuka file berdasarkan permintaan yang telah disiapkan.
 */

void io_open_cleanup(struct io_kiocb *req);
/**
 * Bersihkan sumber daya setelah operasi openat.
 * Membebaskan memori atau buffer yang digunakan.
 */

int io_openat2_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi openat2.
 * Menginisialisasi struktur permintaan untuk membuka file dengan opsi tambahan.
 */

int io_openat2(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi openat2.
 * Membuka file dengan opsi tambahan berdasarkan permintaan.
 */

int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi close.
 * Menginisialisasi struktur permintaan untuk menutup file.
 */

int io_close(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi close.
 * Menutup file berdasarkan permintaan yang telah disiapkan.
 */

int io_install_fixed_fd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pemasangan file descriptor tetap.
 * Menginisialisasi struktur permintaan untuk memasang file descriptor tetap.
 */

int io_install_fixed_fd(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi pemasangan file descriptor tetap.
 * Memasang file descriptor tetap ke dalam konteks io_uring.
 */

// SPDX-License-Identifier: GPL-2.0

int io_nop_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi NOP (no operation).
 * Menginisialisasi struktur permintaan tanpa melakukan operasi.
 */

int io_nop(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi NOP (no operation).
 * Tidak melakukan apa-apa dan langsung menyelesaikan permintaan.
 */

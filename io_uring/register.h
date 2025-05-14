// SPDX-License-Identifier: GPL-2.0
#ifndef IORING_REGISTER_H
#define IORING_REGISTER_H

int io_eventfd_unregister(struct io_ring_ctx *ctx);
/**
 * Batalkan pendaftaran eventfd dari konteks io_uring.
 * Membersihkan eventfd yang terdaftar untuk operasi io_uring.
 */

int io_unregister_personality(struct io_ring_ctx *ctx, unsigned id);
/**
 * Batalkan pendaftaran personality dari konteks io_uring.
 * Menghapus personality yang terkait dengan ID tertentu.
 */

struct file *io_uring_register_get_file(unsigned int fd, bool registered);
/**
 * Dapatkan file yang terdaftar di io_uring berdasarkan file descriptor.
 * Mengembalikan pointer ke struktur file jika ditemukan.
 */

#endif

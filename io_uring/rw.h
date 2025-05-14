// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>
#include <linux/pagemap.h>

struct io_meta_state {
	u32			seed;
	struct iov_iter_state	iter_meta;
};

struct io_async_rw {
	struct iou_vec			vec;
	size_t				bytes_done;

	struct_group(clear,
		struct iov_iter			iter;
		struct iov_iter_state		iter_state;
		struct iovec			fast_iov;
		/*
		 * wpq is for buffered io, while meta fields are used with
		 * direct io
		 */
		union {
			struct wait_page_queue		wpq;
			struct {
				struct uio_meta			meta;
				struct io_meta_state		meta_state;
			};
		};
	);
};

int io_prep_read_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pembacaan dengan buffer tetap.
 * Menginisialisasi struktur permintaan untuk pembacaan data.
 */

int io_prep_write_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penulisan dengan buffer tetap.
 * Menginisialisasi struktur permintaan untuk penulisan data.
 */

int io_prep_readv_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pembacaan dengan buffer tetap menggunakan vektorisasi.
 * Menginisialisasi struktur permintaan untuk pembacaan data dengan vektorisasi.
 */

int io_prep_writev_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penulisan dengan buffer tetap menggunakan vektorisasi.
 * Menginisialisasi struktur permintaan untuk penulisan data dengan vektorisasi.
 */

int io_prep_readv(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pembacaan menggunakan vektorisasi.
 * Menginisialisasi struktur permintaan untuk pembacaan data dengan vektorisasi.
 */

int io_prep_writev(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penulisan menggunakan vektorisasi.
 * Menginisialisasi struktur permintaan untuk penulisan data dengan vektorisasi.
 */

int io_prep_read(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pembacaan.
 * Menginisialisasi struktur permintaan untuk pembacaan data.
 */

int io_prep_write(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penulisan.
 * Menginisialisasi struktur permintaan untuk penulisan data.
 */

int io_read(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Lakukan operasi pembacaan.
 * Mengambil data dari sumber dan menyimpannya dalam buffer yang ditentukan.
 */

int io_write(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Lakukan operasi penulisan.
 * Mengambil data dari buffer yang ditentukan dan menulisnya ke tujuan.
 */

int io_read_fixed(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Lakukan operasi pembacaan dengan buffer tetap.
 * Mengambil data dari sumber dan menyimpannya dalam buffer tetap yang ditentukan.
 */

int io_write_fixed(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Lakukan operasi penulisan dengan buffer tetap.
 * Mengambil data dari buffer tetap yang ditentukan dan menulisnya ke tujuan.
 */

void io_readv_writev_cleanup(struct io_kiocb *req);
/**
 * Bersihkan sumber daya yang digunakan oleh operasi pembacaan/penulisan vektorisasi.
 * Menghapus semua buffer yang dialokasikan dan mengembalikan status kesalahan jika ada.
 */

void io_rw_fail(struct io_kiocb *req);
/**
 * Gagal pada operasi pembacaan/penulisan.
 * Menghapus semua buffer yang dialokasikan dan mengembalikan status kesalahan.
 */

void io_req_rw_complete(struct io_kiocb *req, io_tw_token_t tw);
/**
 * Lengkapi operasi pembacaan/penulisan.
 * Mengembalikan status kesalahan jika ada dan menghapus semua buffer yang dialokasikan.
 */

int io_read_mshot_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi pembacaan dengan mshot.
 * Menginisialisasi struktur permintaan untuk pembacaan data dengan mshot.
 */

int io_read_mshot(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Lakukan operasi pembacaan dengan mshot.
 * Mengambil data dari sumber dan menyimpannya dalam buffer yang ditentukan dengan mshot.
 */

void io_rw_cache_free(const void *entry);
/**
 * Bebaskan cache yang digunakan oleh operasi pembacaan/penulisan.
 * Menghapus semua buffer yang dialokasikan dan mengembalikan status kesalahan jika ada.
 */

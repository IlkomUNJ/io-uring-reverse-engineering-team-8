// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>

#define IO_POLL_ALLOC_CACHE_MAX 32

enum {
	IO_APOLL_OK,
	IO_APOLL_ABORTED,
	IO_APOLL_READY
};

struct io_poll {
	struct file			*file;
	struct wait_queue_head		*head;
	__poll_t			events;
	int				retries;
	struct wait_queue_entry		wait;
};

struct async_poll {
	struct io_poll		poll;
	struct io_poll		*double_poll;
};

/*
 * Must only be called inside issue_flags & IO_URING_F_MULTISHOT, or
 * potentially other cases where we already "own" this poll request.
 */
static inline void io_poll_multishot_retry(struct io_kiocb *req)
/**
 * Tingkatkan referensi untuk permintaan poll multishot.
 * Digunakan untuk menangani ulang permintaan poll multishot.
 */
{
    atomic_inc(&req->poll_refs);
}

int io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penambahan poll.
 * Menginisialisasi struktur permintaan untuk operasi poll.
 */

int io_poll_add(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Tambahkan operasi poll ke antrean.
 * Mendaftarkan event poll untuk file yang terkait dengan permintaan.
 */

int io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi penghapusan poll.
 * Menginisialisasi struktur permintaan untuk menghapus event poll.
 */

int io_poll_remove(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Hapus operasi poll dari antrean.
 * Membatalkan event poll yang sebelumnya terdaftar.
 */

struct io_cancel_data;
int io_poll_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
           unsigned issue_flags);
/**
 * Batalkan operasi poll yang sedang berlangsung.
 * Membatalkan event poll berdasarkan data pembatalan yang diberikan.
 */

int io_arm_poll_handler(struct io_kiocb *req, unsigned issue_flags);
/**
 * Pasang handler untuk operasi poll.
 * Mengatur event poll untuk menangani kondisi tertentu.
 */

bool io_poll_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
            bool cancel_all);
/**
 * Hapus semua operasi poll yang terkait dengan konteks.
 * Membatalkan semua event poll jika cancel_all diatur ke true.
 */

void io_poll_task_func(struct io_kiocb *req, io_tw_token_t tw);
/**
 * Fungsi tugas untuk menangani event poll.
 * Menangani event poll yang dipicu untuk permintaan tertentu.
 */
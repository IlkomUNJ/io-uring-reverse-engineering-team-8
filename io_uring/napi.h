/* SPDX-License-Identifier: GPL-2.0 */

#ifndef IOU_NAPI_H
#define IOU_NAPI_H

#include <linux/kernel.h>
#include <linux/io_uring.h>
#include <net/busy_poll.h>

#ifdef CONFIG_NET_RX_BUSY_POLL

void io_napi_init(struct io_ring_ctx *ctx);
/**
 * Inisialisasi pengaturan napi dalam konteks io-uring.
 * Mengatur daftar napi, kunci spin, dan preferensi busy poll.
 */
void io_napi_free(struct io_ring_ctx *ctx);
/**
 * Bebaskan daftar napi dan tabel hash dalam konteks io-uring.
 * Membersihkan semua entri napi yang terdaftar.
 */

int io_register_napi(struct io_ring_ctx *ctx, void __user *arg);
/**
 * Daftarkan napi dalam konteks io-uring.
 * Mengatur pengaturan busy poll dan mode pelacakan napi.
 */
int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg);
/**
 * Batalkan pendaftaran napi dalam konteks io-uring.
 * Menghapus pengaturan busy poll dan mode pelacakan napi.
 */

int __io_napi_add_id(struct io_ring_ctx *ctx, unsigned int napi_id);
/**
 * Tambahkan napi_id ke dalam konteks io-uring.
 * Mengembalikan 0 jika berhasil, atau kode kesalahan jika gagal.
 */

void __io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq);
/**
 * Lakukan busy loop pada napi yang terdaftar.
 * Menggunakan preferensi busy poll dan batasan anggaran.
 */
int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx);
/**
 * Lakukan busy poll pada napi yang terdaftar dalam mode SQPOLL.
 * Menggunakan preferensi busy poll dan batasan anggaran.
 */

static inline bool io_napi(struct io_ring_ctx *ctx)
/**
 * Periksa apakah daftar napi tidak kosong.
 * Mengembalikan true jika ada entri napi, false jika tidak.
 */
{
	return !list_empty(&ctx->napi_list);
}

static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
				     struct io_wait_queue *iowq)
/**
 * Jalankan loop busy poll jika daftar napi tidak kosong.
 * Memanggil fungsi __io_napi_busy_loop untuk eksekusi.
 */
{
	if (!io_napi(ctx))
		return;
	__io_napi_busy_loop(ctx, iowq);
}

/*
 * io_napi_add() - Add napi id to the busy poll list
 * @req: pointer to io_kiocb request
 *
 * Add the napi id of the socket to the napi busy poll list and hash table.
 */
static inline void io_napi_add(struct io_kiocb *req)
/**
 * Tambahkan napi id dari socket ke daftar napi.
 * Hanya berlaku jika mode pelacakan napi adalah dinamis.
 */
{
	struct io_ring_ctx *ctx = req->ctx;
	struct socket *sock;

	if (READ_ONCE(ctx->napi_track_mode) != IO_URING_NAPI_TRACKING_DYNAMIC)
		return;

	sock = sock_from_file(req->file);
	if (sock && sock->sk)
		__io_napi_add_id(ctx, READ_ONCE(sock->sk->sk_napi_id));
}

#else

static inline void io_napi_init(struct io_ring_ctx *ctx)
/**
 * Inisialisasi pengaturan napi dalam konteks io-uring.
 * Tidak melakukan apa-apa jika tidak ada dukungan untuk busy poll.
 */
{
}

static inline void io_napi_free(struct io_ring_ctx *ctx)
/**
 * Bebaskan daftar napi dan tabel hash dalam konteks io-uring.
 * Tidak melakukan apa-apa jika tidak ada dukungan untuk busy poll.
 */
{
}

static inline int io_register_napi(struct io_ring_ctx *ctx, void __user *arg)
/**
 * Daftarkan napi dalam konteks io-uring.
 * Tidak melakukan apa-apa jika tidak ada dukungan untuk busy poll.
 */
{
	return -EOPNOTSUPP;
}

static inline int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg)
/**
 * Fungsi dummy untuk membatalkan pendaftaran napi jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan.
 * Mengembalikan -EOPNOTSUPP.
 */
{
	return -EOPNOTSUPP;
}

static inline bool io_napi(struct io_ring_ctx *ctx)
/**
 * Fungsi dummy untuk memeriksa napi jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan.
 * Selalu mengembalikan false.
 */
{
	return false;
}

static inline void io_napi_add(struct io_kiocb *req)
/**
 * Fungsi dummy untuk menambahkan napi id jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan.
 * Tidak melakukan apa-apa.
 */
{
}

static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
				     struct io_wait_queue *iowq)
/**
 * Fungsi dummy untuk menjalankan busy loop jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan.
 */				
{
}

static inline int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx)
/**
 * Fungsi dummy untuk busy poll sqpoll jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan.
 * Selalu mengembalikan 0.
 */
{
	return 0;
}
#endif /* CONFIG_NET_RX_BUSY_POLL */

#endif

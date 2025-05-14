// SPDX-License-Identifier: GPL-2.0

#include <linux/net.h>
#include <linux/uio.h>
#include <linux/io_uring_types.h>

struct io_async_msghdr {
#if defined(CONFIG_NET)
	struct iou_vec				vec;

	struct_group(clear,
		int				namelen;
		struct iovec			fast_iov;
		__kernel_size_t			controllen;
		__kernel_size_t			payloadlen;
		struct sockaddr __user		*uaddr;
		struct msghdr			msg;
		struct sockaddr_storage		addr;
	);
#else
	struct_group(clear);
#endif
};

#if defined(CONFIG_NET)

int io_shutdown_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi shutdown.
 * Menginisialisasi struktur permintaan untuk menutup koneksi.
 */

int io_shutdown(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi shutdown.
 * Menutup koneksi berdasarkan permintaan yang telah disiapkan.
 */

void io_sendmsg_recvmsg_cleanup(struct io_kiocb *req);
/**
 * Bersihkan sumber daya setelah operasi sendmsg atau recvmsg.
 * Membebaskan memori atau buffer yang digunakan.
 */

int io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi sendmsg.
 * Menginisialisasi struktur permintaan untuk mengirim pesan.
 */

int io_sendmsg(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi sendmsg.
 * Mengirim pesan berdasarkan permintaan yang telah disiapkan.
 */

int io_send(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi send.
 * Mengirim data melalui koneksi yang ada.
 */

int io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi recvmsg.
 * Menginisialisasi struktur permintaan untuk menerima pesan.
 */

int io_recvmsg(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi recvmsg.
 * Menerima pesan berdasarkan permintaan yang telah disiapkan.
 */

int io_recv(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi recv.
 * Menerima data melalui koneksi yang ada.
 */

void io_sendrecv_fail(struct io_kiocb *req);
/**
 * Tangani kegagalan operasi send atau recv.
 * Menandai permintaan sebagai gagal dan melakukan pembersihan.
 */

int io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi accept.
 * Menginisialisasi struktur permintaan untuk menerima koneksi baru.
 */

int io_accept(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi accept.
 * Menerima koneksi baru berdasarkan permintaan yang telah disiapkan.
 */

int io_socket_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi socket.
 * Menginisialisasi struktur permintaan untuk membuat socket baru.
 */

int io_socket(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi socket.
 * Membuat socket baru berdasarkan permintaan yang telah disiapkan.
 */

int io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi connect.
 * Menginisialisasi struktur permintaan untuk menghubungkan socket.
 */

int io_connect(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi connect.
 * Menghubungkan socket ke alamat yang ditentukan.
 */

int io_send_zc(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi send dengan zerocopy.
 * Mengirim data menggunakan mekanisme zerocopy.
 */

int io_sendmsg_zc(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi sendmsg dengan zerocopy.
 * Mengirim pesan menggunakan mekanisme zerocopy.
 */

int io_send_zc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi send dengan zerocopy.
 * Menginisialisasi struktur permintaan untuk pengiriman zerocopy.
 */

void io_send_zc_cleanup(struct io_kiocb *req);
/**
 * Bersihkan sumber daya setelah operasi send zerocopy.
 * Membebaskan memori atau buffer yang digunakan.
 */

int io_bind_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi bind.
 * Menginisialisasi struktur permintaan untuk mengikat socket ke alamat.
 */

int io_bind(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi bind.
 * Mengikat socket ke alamat yang ditentukan.
 */

int io_listen_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan operasi listen.
 * Menginisialisasi struktur permintaan untuk mendengarkan koneksi masuk.
 */

int io_listen(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Eksekusi operasi listen.
 * Mendengarkan koneksi masuk pada socket yang ditentukan.
 */

void io_netmsg_cache_free(const void *entry);
/**
 * Bebaskan cache pesan jaringan.
 * Membersihkan entri cache yang tidak lagi diperlukan.
 */
#else
static inline void io_netmsg_cache_free(const void *entry)
{
}
#endif

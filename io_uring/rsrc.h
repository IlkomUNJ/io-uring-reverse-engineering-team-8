// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_RSRC_H
#define IOU_RSRC_H

#include <linux/io_uring_types.h>
#include <linux/lockdep.h>

#define IO_VEC_CACHE_SOFT_CAP		256

enum {
	IORING_RSRC_FILE		= 0,
	IORING_RSRC_BUFFER		= 1,
};

struct io_rsrc_node {
	unsigned char			type;
	int				refs;

	u64 tag;
	union {
		unsigned long file_ptr;
		struct io_mapped_ubuf *buf;
	};
};

enum {
	IO_IMU_DEST	= 1 << ITER_DEST,
	IO_IMU_SOURCE	= 1 << ITER_SOURCE,
};

struct io_mapped_ubuf {
	u64		ubuf;
	unsigned int	len;
	unsigned int	nr_bvecs;
	unsigned int    folio_shift;
	refcount_t	refs;
	unsigned long	acct_pages;
	void		(*release)(void *);
	void		*priv;
	bool		is_kbuf;
	u8		dir;
	struct bio_vec	bvec[] __counted_by(nr_bvecs);
};

struct io_imu_folio_data {
	/* Head folio can be partially included in the fixed buf */
	unsigned int	nr_pages_head;
	/* For non-head/tail folios, has to be fully included */
	unsigned int	nr_pages_mid;
	unsigned int	folio_shift;
	unsigned int	nr_folios;
};

bool io_rsrc_cache_init(struct io_ring_ctx *ctx);
/**
 * Inisialisasi cache sumber daya untuk io_uring.
 * Mengalokasikan memori untuk cache sumber daya.
 */

void io_rsrc_cache_free(struct io_ring_ctx *ctx);
/**
 * Bebaskan cache sumber daya untuk io_uring.
 * Membersihkan semua entri dalam cache sumber daya.
 */

struct io_rsrc_node *io_rsrc_node_alloc(struct io_ring_ctx *ctx, int type);
/**
 * Alokasikan node sumber daya baru.
 * Mengembalikan pointer ke node yang dialokasikan.
 */

void io_free_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node);
/**
 * Bebaskan node sumber daya.
 * Mengurangi referensi dan membebaskan memori jika tidak ada referensi lagi.
 */

void io_rsrc_data_free(struct io_ring_ctx *ctx, struct io_rsrc_data *data);
/**
 * Bebaskan data sumber daya.
 * Membersihkan semua node yang terkait dengan data sumber daya.
 */

int io_rsrc_data_alloc(struct io_rsrc_data *data, unsigned nr);
/**
 * Alokasikan data sumber daya.
 * Mengatur jumlah node yang diperlukan untuk sumber daya.
 */

struct io_rsrc_node *io_find_buf_node(struct io_kiocb *req,
                      unsigned issue_flags);
/**
 * Temukan node buffer yang sesuai dengan permintaan.
 * Mengembalikan pointer ke node buffer jika ditemukan.
 */

int io_import_reg_buf(struct io_kiocb *req, struct iov_iter *iter,
            u64 buf_addr, size_t len, int ddir,
            unsigned issue_flags);
/**
 * Impor buffer terdaftar untuk operasi IO.
 * Mengatur iterasi IO berdasarkan buffer yang diberikan.
 */

int io_import_reg_vec(int ddir, struct iov_iter *iter,
            struct io_kiocb *req, struct iou_vec *vec,
            unsigned nr_iovs, unsigned issue_flags);
/**
 * Impor vektor buffer terdaftar untuk operasi IO.
 * Mengatur iterasi IO berdasarkan vektor buffer yang diberikan.
 */

int io_prep_reg_iovec(struct io_kiocb *req, struct iou_vec *iv,
            const struct iovec __user *uvec, size_t uvec_segs);
/**
 * Siapkan vektor IO untuk operasi IO.
 * Menginisialisasi struktur vektor IO berdasarkan input pengguna.
 */

int io_register_clone_buffers(struct io_ring_ctx *ctx, void __user *arg);
/**
 * Daftarkan buffer kloning untuk io_uring.
 * Mengkloning buffer yang ada untuk digunakan dalam operasi IO.
 */

int io_sqe_buffers_unregister(struct io_ring_ctx *ctx);
/**
 * Batalkan pendaftaran buffer SQE.
 * Membersihkan buffer yang terdaftar dalam konteks io_uring.
 */

int io_sqe_buffers_register(struct io_ring_ctx *ctx, void __user *arg,
                unsigned int nr_args, u64 __user *tags);
/**
 * Daftarkan buffer SQE untuk io_uring.
 * Mengatur buffer yang akan digunakan dalam operasi IO.
 */

int io_sqe_files_unregister(struct io_ring_ctx *ctx);
/**
 * Batalkan pendaftaran file SQE.
 * Membersihkan file yang terdaftar dalam konteks io_uring.
 */

int io_sqe_files_register(struct io_ring_ctx *ctx, void __user *arg,
              unsigned nr_args, u64 __user *tags);
/**
 * Daftarkan file SQE untuk io_uring.
 * Mengatur file yang akan digunakan dalam operasi IO.
 */

int io_register_files_update(struct io_ring_ctx *ctx, void __user *arg,
                 unsigned nr_args);
/**
 * Perbarui file yang terdaftar dalam konteks io_uring.
 * Mengganti file yang ada dengan file baru.
 */

int io_register_rsrc_update(struct io_ring_ctx *ctx, void __user *arg,
                unsigned size, unsigned type);
/**
 * Perbarui sumber daya yang terdaftar dalam konteks io_uring.
 * Mengganti sumber daya yang ada dengan sumber daya baru.
 */

int io_register_rsrc(struct io_ring_ctx *ctx, void __user *arg,
            unsigned int size, unsigned int type);
/**
 * Daftarkan sumber daya baru untuk io_uring.
 * Mengatur sumber daya yang akan digunakan dalam operasi IO.
 */

int io_buffer_validate(struct iovec *iov);
/**
 * Validasi buffer IO.
 * Memastikan buffer memenuhi persyaratan untuk operasi IO.
 */

bool io_check_coalesce_buffer(struct page **page_array, int nr_pages,
                  struct io_imu_folio_data *data);
/**
 * Periksa apakah buffer dapat digabungkan.
 * Mengembalikan true jika buffer dapat digabungkan, false jika tidak.
 */

static inline struct io_rsrc_node *io_rsrc_node_lookup(struct io_rsrc_data *data,
						       int index)
/**
 * Cari node sumber daya berdasarkan indeks.
 * Mengembalikan pointer ke node jika ditemukan, atau NULL jika tidak.
 */
{
	if (index < data->nr)
		return data->nodes[array_index_nospec(index, data->nr)];
	return NULL;
}

static inline void io_put_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node)
/**
 * Kurangi referensi node sumber daya.
 * Bebaskan node jika tidak ada referensi yang tersisa.
 */
{
    lockdep_assert_held(&ctx->uring_lock);
    if (!--node->refs)
        io_free_rsrc_node(ctx, node);
}

static inline bool io_reset_rsrc_node(struct io_ring_ctx *ctx,
                      struct io_rsrc_data *data, int index)
/**
 * Reset node sumber daya pada indeks tertentu.
 * Mengembalikan true jika node berhasil direset, false jika tidak.
 */
{
    struct io_rsrc_node *node = data->nodes[index];

    if (!node)
        return false;
    io_put_rsrc_node(ctx, node);
    data->nodes[index] = NULL;
    return true;
}

static inline void io_req_put_rsrc_nodes(struct io_kiocb *req)
/**
 * Bebaskan semua node sumber daya yang terkait dengan permintaan.
 * Mengurangi referensi dan membersihkan node sumber daya.
 */
{
    if (req->file_node) {
        io_put_rsrc_node(req->ctx, req->file_node);
        req->file_node = NULL;
    }
    if (req->flags & REQ_F_BUF_NODE) {
        io_put_rsrc_node(req->ctx, req->buf_node);
        req->buf_node = NULL;
    }
}

static inline void io_req_assign_rsrc_node(struct io_rsrc_node **dst_node,
                       struct io_rsrc_node *node)
/**
 * Tetapkan node sumber daya ke permintaan.
 * Menambahkan referensi ke node sumber daya.
 */
{
    node->refs++;
    *dst_node = node;
}

static inline void io_req_assign_buf_node(struct io_kiocb *req,
                      struct io_rsrc_node *node)
/**
 * Tetapkan node buffer ke permintaan.
 * Menambahkan referensi ke node buffer dan menandai permintaan.
 */
{
    io_req_assign_rsrc_node(&req->buf_node, node);
    req->flags |= REQ_F_BUF_NODE;
}

int io_files_update(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Perbarui file yang terkait dengan permintaan.
 * Mengganti file yang ada dengan file baru.
 */

int io_files_update_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Siapkan pembaruan file untuk permintaan.
 * Menginisialisasi struktur permintaan untuk pembaruan file.
 */

int __io_account_mem(struct user_struct *user, unsigned long nr_pages);
/**
 * Akun memori yang digunakan oleh pengguna.
 * Menambahkan jumlah halaman yang digunakan ke akun pengguna.
 */

static inline void __io_unaccount_mem(struct user_struct *user,
                      unsigned long nr_pages)
/**
 * Kurangi akun memori yang digunakan oleh pengguna.
 * Mengurangi jumlah halaman yang digunakan dari akun pengguna.
 */
{
    atomic_long_sub(nr_pages, &user->locked_vm);
}

void io_vec_free(struct iou_vec *iv);
/**
 * Bebaskan vektor IO.
 * Membersihkan semua entri dalam vektor IO.
 */

int io_vec_realloc(struct iou_vec *iv, unsigned nr_entries);
/**
 * Alokasikan ulang vektor IO.
 * Mengatur ulang jumlah entri dalam vektor IO.
 */

static inline void io_vec_reset_iovec(struct iou_vec *iv,
                      struct iovec *iovec, unsigned nr)
/**
 * Reset vektor IO ke nilai awal.
 * Mengatur ulang vektor IO dengan entri baru.
 */
{
    io_vec_free(iv);
    iv->iovec = iovec;
    iv->nr = nr;
}

static inline void io_alloc_cache_vec_kasan(struct iou_vec *iv)
/**
 * Alokasikan ulang cache vektor IO jika KASAN diaktifkan.
 * Membersihkan vektor IO sebelum alokasi ulang.
 */
{
    if (IS_ENABLED(CONFIG_KASAN))
        io_vec_free(iv);
}

#endif

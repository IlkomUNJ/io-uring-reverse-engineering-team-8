# Task 3: Data Structure Investigation
The objective of this task is to document all internal data structures defined in io_uring. 

Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_ev_fd       | io_uring/eventfd.c | eventfd_ctx, uint, uint, refcount_t, atomic_t, rcu_head | io_eventfd_free | io_uring/eventfd.c | local variable
| | | | io_eventfd_put | io_uring/eventfd.c | function parameter
| | | | io_eventfd_do_signal | io_uring/eventfd.c | local variable, function parameter
| | | | __io_eventfd_signal | io_uring/eventfd.c | function parameter
| | | | io_eventfd_grab | io_uring/eventfd.c | return value, local variable
| | | | io_eventfd_signal | io_uring/eventfd.c | local variable 
| | | | io_eventfd_flush_signal | io_uring/eventfd.c | local variable
| | | | io_eventfd_register | io_uring/eventfd.c | local variable
| | | | io_eventfd_unregister | io_uring/eventfd.c | function parameter

If the following row value in a column is missing, assume the value is the same with the previous row in the same column. 
Continue until all data structures documented properly.

### advise
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_fadvise     | io_uring/advise.c | file, u64, u64, u32 | io_fadvise_force_async | io_uring/advise.c | function parameter
| | | | io_fadvise_prep | io_uring/advise.c | local variable, function parameter
| | | | io_fadvise | io_uring/advise.c | local variable, function parameter
io_madvise     | io_uring/advise.c | file, u64, u64, u32 | io_madvise_prep | io_uring/advise.c | local variable, function parameter
| | | | io_madvise | io_uring/advise.c | local variable, function parameter

### alloc_cache
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### cancel
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_cancel     | io_uring/cancel.c | file, u64, u32, s32, u8 | io_async_cancel_prep | io_uring/cancel.c | local variabel, function parameter
| | | | io_async_cancel | io_uring/cancel.c | local variable, function parameter
io_cancel_data | io_uring/cancel.h | io_ring_ctx, union, u64, file, u8, u32, int | io_try_cancel | io_uring/cancel.h | function parameter
| | | | io_cancel_req_match | io_uring/cancel.h | function parameter
| | | | io_cancel_req_match | io_uring/cancel.c | function parameter
| | | | io_cancel_remove | io_uring/cancel.h | function parameter
| | | | io_cancel_remove | io_uring/cancel.c | function parameter
| | | | io_cancel_cb | io_uring/cancel.c | local variable
| | | | io_async_cancel_one | io_uring/cancel.c | function parameter
| | | | io_try_cancel | io_uring/cancel.c | function parameter
| | | | __io_async_cancel | io_uring/cancel.c | function parameter
| | | | io_async_cancel | io_uring/cancel.c | local variable
| | | | __io_sync_cancel | io_uring/cancel.c | function parameter
| | | | io_sync_cancel | io_uring/cancel.c | local variable
| | | | io_futex_cancel | io_uring/futex.c | function parameter
| | | | io_futex_cancel | io_uring/futex.h | function parameter
| | | | io_poll_find | io_uring/poll.c | function parameter
| | | | io_poll_file_find | io_uring/poll.c | function parameter
| | | | __io_poll_cancel | io_uring/poll.c | function parameter
| | | | io_poll_cancel | io_uring/poll.c | function parameter
| | | | io_poll_cancel | io_uring/poll.h | function parameter
| | | | io_poll_remove | io_uring/poll.c | local variable
| | | | io_waitid_cancel | io_uring/waitid.c | function parameter
| | | | io_timeout_cancel | io_uring/timeout.h | function parameter 
| | | | io_timeout_extract | io_uring/timeout.c | function parameter 
| | | | io_timeout_cancel | io_uring/timeout.c | function parameter 
| | | | io_req_task_link_timeout | io_uring/timeout.c | local variable
| | | | io_timeout_update | io_uring/timeout.c | local variable
| | | | io_timeout_remove | io_uring/timeout.c | local variable

### epoll
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_epoll       | io_uring/epoll.c | file, int, int, int, epoll_event | io_epoll_ctl_prep | io_uring/epoll.c | local variabel, function parameter
| | | | io_epoll_ctl | io_uring/epoll.c | local variable, function parameter
io_epoll_wait   | io_uring/epoll.c | file, int, epoll_event | io_epoll_wait_prep | io_uring/epoll.c | local variabel, function parameter
| | | | io_epoll_wait | io_uring/epoll.c | local variable, function parameter

### eventfd
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_ev_fd       | io_uring/eventfd.c | eventfd_ctx, uint, uint, refcount_t, atomic_t, rcu_head | io_eventfd_free | io_uring/eventfd.c | local variable, function parameter
| | | | io_eventfd_put | io_uring/eventfd.c | function parameter
| | | | io_eventfd_do_signal | io_uring/eventfd.c | local variable, function parameter
| | | | io_eventfd_release | io_uring/eventfd.c | function parameter
| | | | __io_eventfd_signal | io_uring/eventfd.c | function parameter
| | | | io_eventfd_trigger | io_uring/eventfd.c | function parameter
| | | | io_eventfd_grab | io_uring/eventfd.c | return value, local variable
| | | | io_eventfd_signal | io_uring/eventfd.c | local variable 
| | | | io_eventfd_flush_signal | io_uring/eventfd.c | local variable
| | | | io_eventfd_register | io_uring/eventfd.c | local variable
| | | | io_eventfd_unregister | io_uring/eventfd.c | local variable

### fdinfo
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### filetable
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### fs
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_rename      | io_uring/fs.c | file, int, int, filename, filename, int | io_renameat_prep | io_uring/fs.c | local variable, function parameter
| | | | io_renameat | io_uring/fs.c | local variable, function parameter
| | | | io_renameat_cleanup | io_uring/fs.c | local variable, function parameter
io_unlink      | io_uring/fs.c | file, int, int, filename | io_unlinkat_prep | io_uring/fs.c | local variable, function parameter
| | | | io_unlinkat | io_uring/fs.c | local variable, function parameter
| | | | io_unlinkat_cleanup | io_uring/fs.c | local variable, function parameter
io_mkdir       | io_uring/fs.c | file, int, umode_t, filename | io_mkdirat_prep | io_uring/fs.c | local variable, function parameter
| | | | io_mkdirat | io_uring/fs.c | local variable, function parameter
| | | | io_mkdirat_cleanup | io_uring/fs.c | local variable, function parameter
io_link        | io_uring/fs.c | file, int, int, filename, filename, int | io_symlinkat_prep | io_uring/fs.c | local variable, function parameter
| | | | io_symlinkat | io_uring/fs.c | local variable, function parameter
| | | | io_linkat_prep | io_uring/fs.c | local variable, function parameter
| | | | io_linkat | io_uring/fs.c | local variable, function parameter
| | | | io_link_cleanup | io_uring/fs.c | local variable, function parameter

### futex
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_futex       | io_uring/futex.c | file, union, u32, futex_waitv, ulong, ulong, ulong, u32, uint, bool | io_futexv_complete | io_uring/futex.c | local variable, function parameter
| | | | io_futexv_claim | io_uring/futex.c | function parameter
| | | | __io_futex_cancel | io_uring/futex.c | local variable, function parameter
| | | | io_futex_prep | io_uring/futex.c | local variable, function parameter
| | | | io_futex_wakev_fn | io_uring/futex.c | local variable, function parameter
| | | | io_futexv_prep | io_uring/futex.c | local variable, function parameter
| | | | io_futexv_wait | io_uring/futex.c | local variable, function parameter
| | | | io_futex_wait | io_uring/futex.c | local variable, function parameter
| | | | io_futex_wake | io_uring/futex.c | local variable, function parameter
io_futex_data       | io_uring/futex.c | futex_q, io_kiocb | io_futex_cache_init | io_uring/futex.c | function parameter
| | | | __io_futex_cancel | io_uring/futex.c | local variable
| | | | io_futex_wake_fn | io_uring/futex.c | local variable, function parameter
| | | | io_futex_wait | io_uring/futex.c | local variable

### io_uring
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_defer_entry      | io_uring/io_uring.c | list_head, io_kiocb, u32 | io_queue_deferred | io_uring/oi_uring.c | local variable, function parameter
| | | | io_drain_req | io_uring/io_uring.c | local variable
| | | | __cold bool io_cancel_defer_files | io_uring/io_uring.c | local variable, function parameter

### io-wq
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### kbuf
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_provide_buf      | io_uring/kbuf.c | file, __u64, __u32, __u32, __u32, __u16 | io_remove_buffers_prep | io_uring/kbuf.c | local variable, function parameter
| | | | io_remove_buffers | io_uring/kbuf.c | local variable, function parameter
| | | | io_provide_buffers_prep | io_uring/kbuf.c | local variable, function parameter
| | | | io_add_buffers | io_uring/kbuf.c | function parameter
| | | | io_provide_buffers | io_uring/kbuf.c | local variable, function parameter
io_buffer_list      | io_uring/kbuf.h | list_head, oi_uring_buf_ring, __u16, __u16, __u16, __u16, __u16, __u16, io_mapped_region | io_kbuf_commit | io_uring/kbuf.h | function parameter
| | | | io_kbuf_inc_commit | io_uring/kbuf.c | function parameter
| | | | io_kbuf_commit | io_uring/kbuf.c | function parameter
| | | | io_buffer_get_list | io_uring/kbuf.c | local variable
| | | | io_buffer_add_list | io_uring/kbuf.c | function parameter
| | | | io_kbuf_recycle_legacy | io_uring/kbuf.c | local variable
| | | | io_provided_buffer_select | io_uring/kbuf.c | function parameter
| | | | io_provided_buffers_select | io_uring/kbuf.c | function parameter
| | | | io_ring_buffer_select | io_uring/kbuf.c | function parameter
| | | | io_buffer_select | io_uring/kbuf.c | local variable
| | | | io_ring_buffers_peek | io_uring/kbuf.c | function parameter
| | | | io_buffers_select | io_uring/kbuf.c | local variable
| | | | io_buffers_peek | io_uring/kbuf.c | local variable
| | | | __io_put_kbuf_ring | io_uring/kbuf.c | local variable
| | | | __io_remove_buffers | io_uring/kbuf.c | function parameter
| | | | io_put_bl | io_uring/kbuf.c | function parameter
| | | | io_destroy_buffers | io_uring/kbuf.c | local variable
| | | | io_destroy_bl | io_uring/kbuf.c | function parameter
| | | | io_remove_buffers | io_uring/kbuf.c | local variable
| | | | io_add_buffers | io_uring/kbuf.c | function parameter
| | | | io_provide_buffers | io_uring/kbuf.c | local variable
| | | | io_register_pbuf_ring | io_uring/kbuf.c | local variable
| | | | io_unregister_pbuf_ring | io_uring/kbuf.c | local variable
| | | | io_register_pbuf_status | io_uring/kbuf.c | local variable
| | | | io_pbuf_get_region | io_uring/kbuf.c | local variable
io_buffer        | io_uring/kbuf.h | list_head, __u64, __u32, __u16, __u16 | io_kbuf_recycle_legacy | io_uring/kbuf.h | local variable
| | | | io_provided_buffer_select | io_uring/kbuf.c | local variable, function parameter
| | | | __io_remove_buffers | io_uring/kbuf.c | local variable, function parameter
| | | | io_add_buffers | io_uring/kbuf.c | local variable
buf_sel_arg      | io_uring/kbuf.h | iovec, size_t, size_t, ushort, ushort | io_ring_buffers_peek | io_uring/kbuf.c | function parameter
| | | | io_buffers_select | io_uring/kbuf.c | function parameter
| | | | io_buffers_peek | io_uring/kbuf.c | function parameter
| | | | io_buffers_select | io_uring/kbuf.h | function parameter
| | | | io_buffers_peek | io_uring/kbuf.h | function parameter
| | | | io_send_select_buffer | io_uring/net.c | local variable
| | | | io_recv_buf_select | io_uring/net.c | local variable

### memmap
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### msg_ring
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_msg         | io_uring/msg_ring.c | file, file, callback_head, u64, u32, u32, u32, u32, u32, u32 | io_msg_ring_cleanup | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_data_remote | io_uring/msg_ring.c | function parameter
| | | | __io_msg_ring_data | io_uring/msg_ring.c | function parameter
| | | | io_msg_ring_data | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_grab_file | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_install_complete | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_tw_fd_complete | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_fd_remote | io_uring/msg_ring.c | local variable, function parameter
| | | | io_msg_send_fd | io_uring/msg_ring.c | local variable, function parameter
| | | | __io_msg_ring_prep | io_uring/msg_ring.c | function parameter
| | | | io_msg_ring_prep | io_uring/msg_ring.c | function parameter
| | | | io_msg_ring | io_uring/msg_ring.c | local variable, function 
| | | | io_uring_sync_msg_ring | io_uring/msg_ring.c | local variable
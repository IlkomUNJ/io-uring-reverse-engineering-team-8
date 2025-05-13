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

### napi - rw

### splice
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_splice      | io_uring/splice.c | struct file, loff_t, loff_t, u64, int, unsigned int,struct io_rsrc_node | __io_splice_prep | io_uring/splice.c | local variable, return value
| | | | io_splice_cleanup| io_uring/splice.c | local variable
| | | | io_splice_get_file | io_uring/splice.c | local variable
| | | | io_tee | io_uring/splice.c | local variable
| | | | io_splice_prep | io_uring/splice.c | local variable
| | | | io_splice | io_uring/splice.c | local variable

### sqpoll
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_sq_data      | io_uring/sqpoll.h| refcount_t, atomic_t, struct mutex	, struct list_head, struct task_struct, struct wait_queue_head,unsigned, int, pid_t, pid_t, u64, unsigned long, struct completion| io_sq_thread_stop | io_uring/sqpoll.h | function parammeter
| | | | io_sq_thread_park | io_uring/sqpoll.h| function parameter
| | | | io_sq_thread_unpark | io_uring/sqpoll.h| function parameter
| | | | io_put_sq_data | io_uring/sqpoll.h| function parameter
| | | | io_sq_thread_unpark | io_uring/sqpoll.c| function parameter
| | | | io_sq_thread_park | io_uring/sqpoll.c| function parameter
| | | | io_sq_thread_stop | io_uring/sqpoll.c| function parameter
| | | | io_put_sq_data | io_uring/sqpoll.c| function parameter
| | | | io_sqd_update_thread_idle | io_uring/sqpoll.c| function parameter
| | | |  io_sq_thread_finish | io_uring/sqpoll.c| local variable
| | | | io_attach_sq_data | io_uring/sqpoll.c| local variable
| | | | io_get_sq_data | io_uring/sqpoll.c| local parameter
| | | | bool io_sqd_events_pending | io_uring/sqpoll.c| function parameter
| | | | io_sqd_handle_event | io_uring/sqpoll.c| function parameter
| | | | io_sq_tw_pending | io_uring/sqpoll.c| function parameter
| | | | io_sq_tw_pending | io_uring/sqpoll.c| local variable
| | | |  io_sq_offload_create | io_uring/sqpoll.c| local variable
| | | |  io_sqpoll_wq_cpu_affinity | io_uring/sqpoll.c| local variable

### statx
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_statx      | io_uring/statx.c | struct file, int, unsigned int, unsigned int, struct filename, struct statx_user | io_statx_prep | io_uring/statx.c | local variable, function parameter
| | | | io_statx | io_uring/statx.c | local variable, function parameter
| | | | io_statx_cleanup | io_uring/statx.c | local variable, function parameter

### sync
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_sync      | io_uring/sync.c | struct file, int, int, loff_t,  loff_t |  io_sfr_prep | io_uring/sync.c | local variable, function parameter
| | | | io_sync_file_range | io_uring/sync.c | local variable, function parameter
| | | | io_fsync_prep | io_uring/sync.c | local variable, function parameter
| | | | io_fsync | io_uring/sync.c | local variable, function parameter
| | | | io_fallocate_prep | io_uring/sync.c | local variable, function parameter
| | | | io_fallocate | io_uring/sync.c | local variable, function parameter

### tctx
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_tctx_node      | io_uring/tctx.h | struct list_head, struct task_struct, struct io_ring_ctx | __io_uring_free | io_uring/tctx.c | local variable
| | | | __io_uring_add_tctx_node| io_uring/tctx.c | local variable
| | | | io_uring_del_tctx_node| io_uring/tctx.c | local variable
| | | | io_uring_clean_tctx| io_uring/tctx.c | local variable

### timeout
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_timeout      | io_uring/timeout.c| struct file	, u32, struct list_head,  struct io_kiocb	 | io_is_timeout_noseq | io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_finish| io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_complete| io_uring/timeout.c | local variable
| | | | io_flush_killed_timeouts| io_uring/timeout.c | local variable, function parameter
| | | | io_kill_timeout| io_uring/timeout.c | local variablec, function parameter
| | | | io_flush_timeouts| io_uring/timeout.c | local variable
| | | | __io_disarm_linked_timeout| io_uring/timeout.c | local variablec, function parameter
| | | | io_timeout_fn| io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_extract| io_uring/timeout.c | local variable, function parameter
| | | | io_req_task_link_timeout| io_uring/timeout.c | local variable, function parameter
| | | | io_link_timeout_fn| io_uring/timeout.c | local variablec, function parameter
| | | | io_linked_timeout_update| io_uring/timeout.c | local variable
| | | | io_timeout_update| io_uring/timeout.c | local variablec, function parameter
| | | | __io_timeout_prep| io_uring/timeout.c | local variablec, function parameter
| | | | io_timeout | io_uring/timeout.c | local variablec, function parameter
| | | | list_for_each_prev| io_uring/timeout.c | local variablec, function parameter
| | | | io_queue_linked_timeout| io_uring/timeout.c | local variablec, function parameter
| | | | io_kill_timeouts| io_uring/timeout.c | local variable
io_timeout_rem      | io_uring/timeout.c| struct file	, u64, struct timespec64,  u32, bool | io_timeout_remove_prep | io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_remove| io_uring/timeout.c | local variable, function parameter
io_timeout_data      | io_uring/timeout.h | sstruct io_kiocb, struct hrtimer, struct timespec64, enum hrtimer_mode, u32 | io_is_timeout_noseq | io_uring/timeout.c | local variable
| | | | io_timeout_finish| io_uring/timeout.c | function parameter
| | | | io_timeout_complete| io_uring/timeout.c | local variable
| | | | io_kill_timeout| io_uring/timeout.c | local variable
| | | | __io_disarm_linked_timeout| io_uring/timeout.c | local variable
| | | | io_timeout_fn| io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_extract| io_uring/timeout.c | local variable
| | | | io_link_timeout_fn| io_uring/timeout.c | function parameter, local variable
| | | | io_timeout_get_clock| io_uring/timeout.c | function parameter
| | | | io_linked_timeout_update| io_uring/timeout.c | local variable
| | | | io_timeout_update| io_uring/timeout.c | local variable
| | | | __io_timeout_prep| io_uring/timeout.c | local variable
| | | | io_timeout| io_uring/timeout.c | local variable
| | | | io_queue_linked_timeout| io_uring/timeout.c | local variable
io_ftrunc      | io_uring/truncate.c| struct file, loff_t | io_ftruncate_prep | io_uring/truncate.c | local variable, function parameter
| | | | io_ftruncate| io_uring/truncate.c | local variable, function parameter

### truncate
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_ftrunc      | io_uring/truncate.c| struct file, loff_t | io_ftruncate_prep | io_uring/truncate.c | local variable, function parameter
| | | | io_ftruncate| io_uring/truncate.c | local variable, function parameter

### uring_cmd
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_async_cmd      | io_uring/uring_cmd.h| struct io_uring_cmd_data, struct iou_vec, struct io_uring_sqe | io_cmd_cache_free | io_uring/uring_cmd.c | local variable, function parameter
| | | | io_req_uring_cleanup| io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_prep_setup| io_uring/uring_cmd.c | local variable, function parameter
| | | | io_uring_cmd_import_fixed_vec| io_uring/uring_cmd.c | local variable,

### waitid
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_waitid_async      | io_uring/waitid.h| struct io_kiocb, struct wait_opts | io_waitid_free | io_uring/waitid.c | local variable
| | | | __io_waitid_cancel| io_uring/waitid.c | local variable
| | | | io_waitid_remove_all| io_uring/waitid.c | local variable
| | | | io_waitid_cb| io_uring/waitid.c | local variable
| | | | io_waitid_wait| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid_prep| io_uring/waitid.c | local variable
| | | | io_waitid| io_uring/waitid.c | local variable
io_waitid      | io_uring/waitid.c| struct file, int which, pid_t upid, int options, atomic_t refs, struct wait_queue_head, struct siginfo __user, struct waitid_info | io_waitid_copy_si | io_uring/waitid.c | local variable, funstion parameter
| | | | io_waitid_complete| io_uring/waitid.c | local variable, function parameter
| | | | __io_waitid_cancel| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid_drop_issue_ref| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid_cb| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid_wait| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid_prep| io_uring/waitid.c | local variable, function parameter
| | | | io_waitid| io_uring/waitid.c | local variable, function parameter

### xattr
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_xattr      | io_uring/xattr.c| struct file, struct kernel_xattr_ctx, struct filename | io_xattr_cleanup | io_uring/xattr.c | local variable, funstion parameter
| | | | __io_getxattr_prep| io_uring/xattr.c | local variable, function parameter
| | | | io_fgetxattr| io_uring/xattr.c | local variable, function parameter
| | | | io_getxattr| io_uring/xattr.c | local variable, function parameter
| | | | __io_setxattr_prep| io_uring/xattr.c | local variable, function parameter
| | | | io_setxattr_prep| io_uring/xattr.c | local variable, function parameter
| | | | io_fsetxattr| io_uring/xattr.c | local variable, function parameter
| | | | io_setxattr| io_uring/xattr.c | local variable, function parameter

### zcrx
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_zcrx_area      | io_uring/zcrx.h| struct net_iov_area, struct io_zcrx_ifq, atomic_t, bool, u16, struct page, spinlock_t, u32  | __io_zcrx_unmap_area | io_uring/zcrx.c | function parameter
| | | | io_zcrx_unmap_area| io_uring/zcrx.c | function parameter
| | | | io_zcrx_map_area| io_uring/zcrx.c | function parameter
| | | | io_get_user_counter| io_uring/zcrx.c | local variable
| | | | io_zcrx_iov_page| io_uring/zcrx.c | local parameter
| | | | io_zcrx_free_area| io_uring/zcrx.c | function parameter
| | | | io_zcrx_create_area| io_uring/zcrx.c | local variable
| | | | __io_zcrx_get_free_niov| io_uring/zcrx.c | function parameter
| | | | io_zcrx_return_niov_freelist| io_uring/zcrx.c | local variable
| | | | io_zcrx_scrub| io_uring/zcrx.c | local variable
| | | | io_zcrx_ring_refill| io_uring/zcrx.c | local variable
| | | | io_zcrx_refill_slow| io_uring/zcrx.c | local variable
| | | | io_pp_zc_destroy| io_uring/zcrx.c | local variable
| | | | io_zcrx_queue_cqe| io_uring/zcrx.c | local variable
| | | | io_zcrx_alloc_fallback| io_uring/zcrx.c | function parameter
| | | | io_zcrx_copy_chunk| io_uring/zcrx.c | local variable
io_zcrx_areaio_zcrx_ifq      | io_uring/zcrx.h| struct io_ring_ctx, struct io_zcrx_area, struct io_uring, struct io_uring_zcrx_rqe, u32, spinlock_t, struct device, struct net_device, netdevice_tracker, spinlock_t | __io_zcrx_unmap_area | io_uring/zcrx.c | function parameter
| | | | io_zcrx_unmap_area| io_uring/zcrx.c | function parameter
| | | | io_zcrx_map_area| io_uring/zcrx.c | function parameter
| | | | io_allocate_rbuf_ring| io_uring/zcrx.c | function parameter
| | | | io_free_rbuf_ring| io_uring/zcrx.c | function parameter
| | | | io_zcrx_create_area| io_uring/zcrx.c | function parameter
| | | | io_zcrx_ifq_alloc| io_uring/zcrx.c | local variable
| | | | io_zcrx_drop_netdev| io_uring/zcrx.c | function parameter
| | | | io_close_queue| io_uring/zcrx.c | function parameter
| | | | io_zcrx_ifq_free| io_uring/zcrx.c | function parameter
| | | | io_register_zcrx_ifq| io_uring/zcrx.c | local variable
| | | | io_unregister_zcrx_ifqs| io_uring/zcrx.c | local variable
| | | | io_zcrx_scrub| io_uring/zcrx.c | function parameter
| | | | io_zcrx_rqring_entries| io_uring/zcrx.c | function parameter
| | | | io_zcrx_get_rqe| io_uring/zcrx.c | function parameter
| | | | io_zcrx_ring_refill| io_uring/zcrx.c | local variable
| | | | io_zcrx_refill_slow| io_uring/zcrx.c | function parameter
| | | | io_pp_zc_alloc_netmems| io_uring/zcrx.c | local variable
| | | | io_pp_zc_init| io_uring/zcrx.c | local variable
| | | | io_pp_zc_destroy| io_uring/zcrx.c | local variable
| | | | io_pp_uninstall| io_uring/zcrx.c | local variable
| | | | io_zcrx_queue_cqe| io_uring/zcrx.c | function parameter
| | | | io_zcrx_copy_chunk| io_uring/zcrx.c | function parameter
| | | | io_zcrx_copy_frag| io_uring/zcrx.c | function parameter
| | | | io_zcrx_recv_skb| io_uring/zcrx.c | local variable
| | | | io_zcrx_tcp_recvmsg| io_uring/zcrx.c | function parameter
| | | | io_zcrx_recv| io_uring/zcrx.c | function parameter
io_zcrx_args   | io_uring/zcrx.c| struct io_kiocb, struct io_zcrx_ifq, struct socket, unsigned| io_zcrx_recv_skb | io_uring/zcrx.c | local parameter
| | | | io_zcrx_tcp_recvmsg| io_uring/zcrx.c | local parameter
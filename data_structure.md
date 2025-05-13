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

### cancel
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_cancel      | io_uring/cancel.c | file, u64, u32, s32, u8 | io_async_cancel_prep | io_uring/cancel.c | local variabel, function parameter
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
io_defer_entry | io_uring/io_uring.c | list_head, io_kiocb, u32 | io_queue_deferred | io_uring/oi_uring.c | local variable, function parameter
| | | | io_drain_req | io_uring/io_uring.c | local variable
| | | | io_cancel_defer_files | io_uring/io_uring.c | local variable, function parameter
ext_arg        | io_uring/io_uring.c | size_t, timespec64, sigset_t, ktime_t, bool, bool |  __io_cqring_wait_schedule | io_uring/oi_uring.c | function parameter
| | | | io_cqring_wait_schedule | io_uring/io_uring.c | function parameter
| | | | io_cqring_wait | io_uring/io_uring.c | function parameter
| | | | io_get_ext_arg | io_uring/io_uring.c | function parameter
| | | | SYSCALL_DEFINE6 | io_uring/io_uring.c | local variable
io_tctx_exit   | io_uring/io_uring.c | callback_head, completion, io_ring_ctx |  io_tctx_exit_cb | io_uring/oi_uring.c | local variable, function parameter
| | | | io_ring_exit_work | io_uring/io_uring.c | local variable
io_task_cancel | io_uring/io_uring.c | io_uring_task, bool | io_cancel_task_cb | io_uring/io_uring.c | local variable 
| | | | io_uring_try_cancel_requests | io_uring/io_uring.c | local variable 
io_wait_queue  | io_uring/io_uring.h | wait_queue_entry, io_ring_ctx,  unsigned, unsigned, unsigned, int, ktime_t, ktime_t, hrtimer | io_should_wake | io_uring/io_uring.h | function parameter
| | | | io_wake_function | io_uring/io_uring.c | local variable, function parameter
| | | | io_cqring_timer_wakeup | io_uring/io_uring.c | local variable, function parameter
| | | | io_cqring_min_timer_wakeup | io_uring/io_uring.c | local variable, function parameter
| | | | io_cqring_schedule_timeout | io_uring/io_uring.c | function parameter
| | | | __io_cqring_wait_schedule | io_uring/io_uring.c | function parameter
| | | | io_cqring_wait_schedule | io_uring/io_uring.c | function parameter
| | | | io_cqring_wait | io_uring/io_uring.c | local variable
| | | | io_napi_busy_loop_should_end | io_uring/napi.c | local variable 
| | | | io_napi_blocking_busy_loop | io_uring/napi.c | function parameter
| | | | __io_napi_busy_loop | io_uring/napi.c | function parameter
| | | | __io_napi_busy_loop | io_uring/napi.h | function parameter
| | | | io_napi_busy_loop | io_uring/napi.h | function parameter

### io-wq
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_wq_hash     | io_uring/io-wq.h | refcount_t refs, unsigned long, struct wait_queue_head | io_wq_put_hash | io_uring/io-wq.h | function parameter
| | | | io_wq_data| io_uring/io-wq.h | local variable
| | | | io_wq| io_uring/io-wq.c | local variable
io_wq_data     | io_uring/io-wq.h | rstruct io_wq_hash, struct task_struct, io_wq_work_fn, free_work_fn | io_wq_create | io_uring/io-wq.h | function parameter
| | | | io_wq_create| io_uring/io-wq.h | local variable
io_wq          | io_uring/io-wq.c | unsigned long state, free_work_fn, io_wq_work_fn, struct io_wq_hash, atomic_t worker, struct completion, struct hlist_node, struct task_struct, struct io_wq_acct, struct wait_queue_entry, struct io_wq_work, cpumask_var_t| io_worker | io_uring/io-wq.c | local function
| | | | create_io_worker| io_uring/io-wq.c | function parameter
| | | | io_acct_cancel_pending_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_tw_create| io_uring/io-wq.c | function parameter
| | | | io_get_acct| io_uring/io-wq.c | function parameter
| | | | io_work_get_acct| io_uring/io-wq.c | function parameter
| | | | io_worker_ref_put| io_uring/io-wq.c | function parameter
| | | | io_worker_cancel_cb| io_uring/io-wq.c | local variable
| | | | io_worker_exit| io_uring/io-wq.c | local variable
| | | | io_wq_create_worker| io_uring/io-wq.c | function parameter
| | | | create_worker_cb| io_uring/io-wq.c | local variable
| | | | io_queue_worker_create| io_uring/io-wq.c | local variable
| | | | io_wq_dec_running| io_uring/io-wq.c | local variable
| | | | io_wait_on_hash| io_uring/io-wq.c | function parameter
| | | | io_get_next_work| io_uring/io-wq.c | function parameter
| | | | wq_list_for_each| io_uring/io-wq.c | function parameter
| | | | io_worker_handle_work| io_uring/io-wq.c | local variable
| | | | io_wq_worker| io_uring/io-wq.c | local variable
| | | | io_init_new_worker| io_uring/io-wq.c | function parameter
| | | | create_worker_cont| io_uring/io-wq.c | local variable
| | | | io_wq_for_each_worker| io_uring/io-wq.c | function parameter
| | | | io_run_cancel| io_uring/io-wq.c | function parameter
| | | | io_wq_insert_work| io_uring/io-wq.c | function parameter
| | | | io_wq_enqueue| io_uring/io-wq.c | function parameter
| | | | io_wq_remove_pending| io_uring/io-wq.c | function parameter
| | | | io_acct_cancel_pending_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_pending_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_running_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_cb| io_uring/io-wq.c | function parameter
| | | | io_wq_hash_wake| io_uring/io-wq.c | function parameter, local variable
| | | | io_wq_create| io_uring/io-wq.c | local variable
| | | | io_wq_exit_start| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_tw_create| io_uring/io-wq.c | function parameter
| | | | io_wq_exit_workers| io_uring/io-wq.c | function parameter
| | | | io_wq_destroy| io_uring/io-wq.c | function parameter
| | | | io_wq_put_and_exit| io_uring/io-wq.c | function parameter
| | | | __io_wq_cpu_online| io_uring/io-wq.c | function parameter
| | | | io_wq_cpu_online| io_uring/io-wq.c | function parameter
| | | | io_wq_cpu_offline| io_uring/io-wq.c | function parameter
| | | | io_wq_max_workers| io_uring/io-wq.c | function parameter
io_cb_cancel_data | io_uring/io-wq.c| rwork_cancel_fn, void, int nr_running, int nr_pending, bool cancel_all | io_acct_cancel_pending_work | io_uring/io-wq.c | function parameter
| | | | create_worker_cont| io_uring/io-wq.c | local variable
| | | | io_wq_enqueue| io_uring/io-wq.c | local variable
| | | | __io_wq_worker_cancel| io_uring/io-wq.c | function parameter
| | | | io_wq_worker_cancel| io_uring/io-wq.c | local variable
| | | | io_acct_cancel_pending_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_pending_work| io_uring/io-wq.c | function parameter
| | | | io_acct_cancel_running_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_running_work| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_cb| io_uring/io-wq.c | function parameter
| | | | io_wq_cancel_cb| io_uring/io-wq.c | local variable
| | | | io_wq_destroy| io_uring/io-wq.c | local variable
io_worker      | io_uring/io-wq.c| refcount_t, unsigned long flags, struct hlist_nulls_node nulls_node, struct list_head all_list, struct task_struct , struct io_wq, struct io_wq_acct , struct io_wq_work, raw_spinlock_t , struct completion, unsigned long create_state,struct callback_head create_work, int init_retries, union | io_wq_dec_running | io_uring/io-wq.c | function parameter
| | | | io_worker_get| io_uring/io-wq.c | function parameter
| | | | io_worker_release| io_uring/io-wq.c | function parameter
| | | | io_wq_get_acct| io_uring/io-wq.c | function parameter
| | | | io_wq_worker_stopped| io_uring/io-wq.c | local parameter
| | | | io_worker_cancel_cb| io_uring/io-wq.c | function parameter
| | | | io_task_worker_match| io_uring/io-wq.c | local variable, function parameter
| | | | io_worker_exit| io_uring/io-wq.c | function parameter
| | | | io_acct_activate_free_worker| io_uring/io-wq.c | local parameter
| | | | io_wq_inc_running| io_uring/io-wq.c | function parameter
| | | | create_worker_cb| io_uring/io-wq.c | local parametr
| | | | io_queue_worker_create | io_uring/io-wq.c | function parameter
| | | | io_wq_dec_running| io_uring/io-wq.c | function parameter
| | | | __io_worker_busy| io_uring/io-wq.c | function parameter
| | | | __io_worker_idle| io_uring/io-wq.c | function parameter
| | | | io_assign_current_work| io_uring/io-wq.c | function parameter
| | | | io_worker_handle_work| io_uring/io-wq.c | function parameter
| | | | io_wq_worker| io_uring/io-wq.c | local variable
| | | | io_wq_worker_running| io_uring/io-wq.c | local varoiable
| | | | io_wq_worker_sleeping| io_uring/io-wq.c | local variable
| | | | io_init_new_worker| io_uring/io-wq.c | function parameter
| | | | io_should_retry_thread| io_uring/io-wq.c | function parameter
| | | | queue_create_worker_retry| io_uring/io-wq.c | function parameter
| | | | create_worker_cont| io_uring/io-wq.c | local variable, function parameter
| | | | io_workqueue_create| io_uring/io-wq.c | function parameter, local variable
| | | | create_io_worker| io_uring/io-wq.c | local variable
| | | | io_acct_for_each_worker| io_uring/io-wq.c | local variable, function paraetr
| | | | io_wq_for_each_worker| io_uring/io-wq.c | function parameter
| | | | io_wq_worker_wake| io_uring/io-wq.c | function parameter
| | | | __io_wq_worker_cancel| io_uring/io-wq.c | function parameter
| | | | io_wq_worker_cancel| io_uring/io-wq.c | function parameter
| | | | io_task_work_match| io_uring/io-wq.c | local variable
| | | | io_wq_cancel_tw_create| io_uring/io-wq.c | function parameter
| | | | io_wq_worker_affinity| io_uring/io-wq.c | function parameter

### kbuf
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_provide_buf | io_uring/kbuf.c | file, __u64, __u32, __u32, __u32, __u16 | io_remove_buffers_prep | io_uring/kbuf.c | local variable, function parameter
| | | | io_remove_buffers | io_uring/kbuf.c | local variable, function parameter
| | | | io_provide_buffers_prep | io_uring/kbuf.c | local variable, function parameter
| | | | io_add_buffers | io_uring/kbuf.c | function parameter
| | | | io_provide_buffers | io_uring/kbuf.c | local variable, function parameter
io_buffer_list | io_uring/kbuf.h | list_head, oi_uring_buf_ring, __u16, __u16, __u16, __u16, __u16, __u16, io_mapped_region | io_kbuf_commit | io_uring/kbuf.h | function parameter
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
io_buffer      | io_uring/kbuf.h | list_head, __u64, __u32, __u16, __u16 | io_kbuf_recycle_legacy | io_uring/kbuf.h | local variable
| | | | io_provided_buffer_select | io_uring/kbuf.c | local variable, function parameter
| | | | __io_remove_buffers | io_uring/kbuf.c | local variable, function parameter
| | | | io_add_buffers | io_uring/kbuf.c | local variable
buf_sel_arg    | io_uring/kbuf.h | iovec, size_t, size_t, ushort, ushort | io_ring_buffers_peek | io_uring/kbuf.c | function parameter
| | | | io_buffers_select | io_uring/kbuf.c | function parameter
| | | | io_buffers_peek | io_uring/kbuf.c | function parameter
| | | | io_buffers_select | io_uring/kbuf.h | function parameter
| | | | io_buffers_peek | io_uring/kbuf.h | function parameter
| | | | io_send_select_buffer | io_uring/net.c | local variable
| | | | io_recv_buf_select | io_uring/net.c | local variable

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

### napi
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_napi_entry  | io_uring/napi.c | unsigned int, list_head, unsigned long, hlist_node, rcu_head | io_napi_hash_find | io_uring/napi.c | local variable, return value
| | | | __io_napi_add_id | io_uring/napi.c | local variable
| | | | __io_napi_del_id | io_uring/napi.c | local variable
| | | | __io_napi_remove_stale | io_uring/napi.c | local variable
| | | | static_tracking_do_busy_loop | io_uring/napi.c | local variable 
| | | | dynamic_tracking_do_busy_loop | io_uring/napi.c | local variable
| | | | io_napi_blocking_busy_loop | io_uring/napi.c | local variable
| | | | io_napi_free | io_uring/napi.c | local variable

### net
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_shutdown	| io_uring/net.c | struct file *, int | io_shutdown_prep | io_uring/net.c | Local variable
| | | | io_shutdown	| io_uring/net.c | Local variable
io_accept   | io_uring/net.c | struct file *, struct sockaddr __user *, int __user *, int, int, u32, unsigned long | io_accept_prep | io_uring/net.c | Local variable
| | | | io_accept | io_uring/net.c | Local variable
io_socket   | io_uring/net.c | struct file *, int, int, int, int, u32, unsigned long | io_socket_prep | io_uring/net.c | Local variable
| | | | io_socket	io_uring/net.c	Local variable
io_connect  | io_uring/net.c | struct file *, struct sockaddr __user *, int, bool, bool | io_connect_prep | io_uring/net.c | Local variable
| | | | io_connect | io_uring/net.c | Local variable
io_bind     | io_uring/net.c | struct file *, int | io_bind_prep | io_uring/net.c | Local variable
| | | | io_bind | io_uring/net.c | Local variable
io_listen   | io_uring/net.c | struct file *, int | io_listen_prep | io_uring/net.c | Local variable
| | | | io_listen | io_uring/net.c | Local variable
io_sr_msg   | io_uring/net.c | struct file *, union { umsg_compat *, umsg *, buf * }, int, unsigned, unsigned, unsigned, u16, u16, bool, msg_control, notif	io_sendmsg_prep | io_uring/net.c | Local variable
| | | | io_sendmsg | io_uring/net.c | Local variable
| | | | io_recvmsg_prep | io_uring/net.c | Local variable
| | | | io_recvmsg | io_uring/net.c | Local variable
| | | | io_send | io_uring/net.c | Local variable
| | | | io_recv	i | _uring/net.c | Local variable
| | | | io_send_zc_prep | io_uring/net.c | Local variable
| | | | io_send_zc | io_uring/net.c | Local variable
| | | | io_sendmsg_zc | io_uring/net.c | Local variable
io_recvzc   | io_uring/net.c | struct file *, unsigned, u16, u32, struct io_zcrx_ifq * | io_recvzc_prep | io_uring/net.c | Local variable
| | | | io_recvzc | io_uring/net.c | Local variable
io_recvmsg_multishot_hdr | io_uring/net.c | struct io_uring_recvmsg_out, struct sockaddr_storage | io_recvmsg_multishot | io_uring/net.c | Local variable
io_async_msghdr | io_uring/net.h | iou_vec, int, iovec, controllen, payloadlen, sockaddr *, msghdr, sockaddr_storage | io_msg_alloc_async | io_uring/net.c | Return value
| | | | io_send_setup | io_uring/net.c | Function parameter
| | | | io_sendmsg_setup | io_uring/net.c | Function parameter
| | | | io_recvmsg_prep_setup | io_uring/net.c | Function parameter
| | | | io_send_zc_prep | io_uring/net.c | Local variable

### nop
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### notif
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### opdef
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### openclose
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### poll
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### refs
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### register
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### rsrc
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### rw
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

### slist 
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------

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
io_sq_data     | io_uring/sqpoll.h| refcount_t, atomic_t, struct mutex	, struct list_head, struct task_struct, struct wait_queue_head,unsigned, int, pid_t, pid_t, u64, unsigned long, struct completion| io_sq_thread_stop | io_uring/sqpoll.h | function parammeter
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
io_statx       | io_uring/statx.c | struct file, int, unsigned int, unsigned int, struct filename, struct statx_user | io_statx_prep  | io_uring/statx.c | local variable, function parameter
| | | | io_statx | io_uring/statx.c | local variable, function parameter
| | | | io_statx_cleanup | io_uring/statx.c | local variable, function parameter

### sync
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_sync        | io_uring/sync.c | struct file, int, int, loff_t,  loff_t |  io_sfr_prep | io_uring/sync.c | local variable, function parameter
| | | | io_sync_file_range | io_uring/sync.c | local variable, function parameter
| | | | io_fsync_prep | io_uring/sync.c | local variable, function parameter
| | | | io_fsync | io_uring/sync.c | local variable, function parameter
| | | | io_fallocate_prep | io_uring/sync.c | local variable, function parameter
| | | | io_fallocate | io_uring/sync.c | local variable, function parameter

### tctx
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_tctx_node   | io_uring/tctx.h | struct list_head, struct task_struct, struct io_ring_ctx | __io_uring_free | io_uring/tctx.c | local variable
| | | | __io_uring_add_tctx_node| io_uring/tctx.c | local variable
| | | | io_uring_del_tctx_node| io_uring/tctx.c | local variable
| | | | io_uring_clean_tctx| io_uring/tctx.c | local variable

### timeout
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_timeout     | io_uring/timeout.c| struct file	, u32, struct list_head,  struct io_kiocb	 | io_is_timeout_noseq | io_uring/timeout.c | local variable, function parameter
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
io_timeout_rem  | io_uring/timeout.c| struct file	, u64, struct timespec64,  u32, bool | io_timeout_remove_prep | io_uring/timeout.c | local variable, function parameter
| | | | io_timeout_remove| io_uring/timeout.c | local variable, function parameter
io_timeout_data     | io_uring/timeout.h | sstruct io_kiocb, struct hrtimer, struct timespec64, enum hrtimer_mode, u32 | io_is_timeout_noseq | io_uring/timeout.c | local variable
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
io_async_cmd   | io_uring/uring_cmd.h| struct io_uring_cmd_data, struct iou_vec, struct io_uring_sqe | io_cmd_cache_free | io_uring/uring_cmd.c | local variable, function parameter
| | | | io_req_uring_cleanup| io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_prep_setup| io_uring/uring_cmd.c | local variable, function parameter
| | | | io_uring_cmd_import_fixed_vec| io_uring/uring_cmd.c | local variable,

### waitid
Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_waitid_async | io_uring/waitid.h| struct io_kiocb, struct wait_opts | io_waitid_free | io_uring/waitid.c | local variable
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
io_xattr       | io_uring/xattr.c| struct file, struct kernel_xattr_ctx, struct filename | io_xattr_cleanup | io_uring/xattr.c | local variable, funstion parameter
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
io_zcrx_area   | io_uring/zcrx.h| struct net_iov_area, struct io_zcrx_ifq, atomic_t, bool, u16, struct page, spinlock_t, u32  | __io_zcrx_unmap_area | io_uring/zcrx.c | function parameter
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
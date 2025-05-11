# Task 2: Dependency Injection
For this assigment, we want a little clarity regarding what kind of functions being imported and used on each source. Do note, we record all function actually being used by the source including function defined by itself if actually used inside the file. For the sake of completion, it's better if you straight disregard include list on the source. Instead, trace each function being used to the declared source.

Source | Libary | Function utilized | Time Used
-------|--------|--------------| ------------------
alloc_cache.h | /include/linux/kasan.h | kasan_mempool_unpoison_object | 1
| | arch/x86/include/asm/string_64.h| memset | 1
| | alloc_cache.h | io_alloc_cache_get | 1
| | alloc_cache.h | io_cache_alloc_new | 1
| | alloc_cache.h | io_alloc_cache_put | 1
| | linux/mm/slub.c | kfree | 1
alloc_cache.c | include/linux/slab.h | kvmalloc_array | 1 |
| | drivers/vdpa/mlx5/core/mr.c | kvfree | 1 |
| | arch/alpha/include/asm/string.h | memset | 1 |
| | include/linux/slab.h | kmalloc | 1 |
| | io_uring/alloc_cache.h | io_alloc_cache_get | 1 |
| | arch/alpha/kernel/pci_iommu.c | free | 1 |
cancel.h | io_uring/cancel.c | io_cancel_remove | 1 |
cancel.c | include/linux/atomic/atomic-instrumented.h | atomic_inc_return | 3 |
| | fs/file_table.c | fput | 1 |
| | include/linux/compiler.h | unlikely | 2 |
| | io_uring/io-wq.c | io_wq_cancel_cb | 1 |
| | io_uring/cancel.h | io_cancel_match_sequence | 1 |
| | arch/mips/boot/tools/relocs.h | ARRAY_SIZE | 2 |
| | include/linux/wait.h | DEFINE_WAIT | 1 |
| | io_uring/cancel.c | __io_sync_cancel | 2 |
| | drivers/gpu/drm/radeon/mkregtable.c | container_of | 1 |
| | io_uring/futex.c | io_futex_cancel | 1 |
| | include/linux/list.h | hlist_for_each_entry_safe | 2 |
| | include/linux/spinlock.h | spin_unlock | 1 |
| | io_uring/io-wq.h | io_wq_current_is_worker | 1 |
| | io_uring/rsrc.h | io_rsrc_node_lookup | 1 |
| | kernel/sched/wait.c | prepare_to_wait | 1 |
| | drivers/block/drbd/drbd_int.h | cancel | 2 |
| | io_uring/io_uring.h | req_set_fail | 1 |
| | include/asm-generic/rwonce.h | READ_ONCE | 4 |
| | include/linux/ktime.h | ktime_add_ns | 1 |
| | drivers/gpu/drm/radeon/mkregtable.c | list_for_each_entry | 1 |
| | include/linux/ktime.h | timespec64_to_ktime | 1 |
| | include/linux/io_uring_types.h | io_kiocb_to_cmd | 2 |
| | io_uring/cancel.c | io_async_cancel_one | 2 |
| | io_uring/io_uring.h | io_ring_submit_unlock | 2 |
| | include/asm-generic/bug.h | WARN_ON_ONCE | 1 |
| | io_uring/cancel.c | io_cancel_req_match | 2 |
| | kernel/sched/wait.c | finish_wait | 1 |
| | io_uring/io_uring.h | io_ring_submit_lock | 2 |
| | include/linux/uaccess.h | copy_from_user | 1 |
| | io_uring/waitid.c | io_waitid_cancel | 1 |
| | arch/alpha/kernel/osf_sys.c | fget | 1 |
| | include/linux/list.h | hlist_del_init | 1 |
| | io_uring/cancel.c | io_try_cancel | 1 |
| | include/linux/mutex.h | mutex_lock | 2 |
| | io_uring/timeout.c | io_timeout_cancel | 1 |
| | io_uring/io_uring.c | io_match_task_safe | 1 |
| | drivers/gpu/drm/msm/disp/dpu1/dpu_crtc.h | spin_lock | 1 |
| | include/linux/mutex.h | mutex_unlock | 1 |
| | io_uring/io_uring.c | io_file_get_fixed | 1 |
| | include/linux/timekeeping.h | ktime_get_ns | 1 |
| | io_uring/poll.c | io_poll_cancel | 1 |
| | io_uring/io_uring.c | io_run_task_work_sig | 1 |
| | io_uring/io_uring.c | io_file_get_normal | 1 |
| | include/linux/lockdep.h | lockdep_assert_held | 1 |
| | kernel/time/sleep_timeout.c | schedule_hrtimeout | 1 |
| | io_uring/io_uring.h | io_req_set_res | 1 |
| | drivers/block/aoe/aoenet.c | __must_hold | 1 |
| | io_uring/cancel.c | __io_async_cancel | 2 |
| | io_uring/filetable.h | io_slot_file | 1 |
advise.c | io_uring/advise.c | io_fadvise_force_async | 2 |
| | mm/madvise.c | do_madvise | 1 |
| | io_uring/io_uring.h | io_req_set_res | 2 |
| | io_uring/io_uring.h | req_set_fail | 1 |
| | include/asm-generic/rwonce.h | READ_ONCE | 8 |
| | include/linux/io_uring_types.h | io_kiocb_to_cmd | 4 |
| | include/asm-generic/bug.h | WARN_ON_ONCE | 2 |
| | mm/fadvise.c | vfs_fadvise | 1 |

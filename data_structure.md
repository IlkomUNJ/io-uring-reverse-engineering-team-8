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
| | | | ??? | io_uring/opdef.c | array??
io_madvise     | io_uring/advise.c | file, u64, u64, u32 | io_madvise_prep | io_uring/advise.c | local variable, function parameter
| | | | io_madvise | io_uring/advise.c | local variable, function parameter
| | | | ??? | io_uring/opdef.c | array??
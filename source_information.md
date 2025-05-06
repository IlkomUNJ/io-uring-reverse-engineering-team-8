# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

## another source

### epoll.c

### eventfd.c

### fdinfo.c

### filrtable.c

### fs.c

### futex.c

### io_uring.c

### io-wq.c

### kbuf.c

### memmap.c

### msg_ring.c

### napi.c

### net.c

### nop.c

### notif.c

### opdef.c

### openclose.c

### zcrx.c

### poll.c

### register.c

### rsrc.c

### rw.c

### splice.c

### sqpoll.c

### ststx.c

### sync.c 

### tctx.c 

### timeout.c

### truncate.c

### uring_cmd.c

### waitid.c

### xattr.c

### zcrx.c


## Headers
Just declare the function specification. 

### advice.h

### epoll.h

### eventfd.h

### fdinfo.h

### filrtable.h

### fs.h

### futex.h

### io_uring.h

### io-wq.h

### kbuf.h

### memmap.h

### msg_ring.h

### napi.h

### net.h

### nop.h

### notif.h

### opdef.h

### openclose.h

### zcrx.h

### openclose.h

### poll.h

### refs.h

### register.h

### rsrc.h

### rw.h

### slist.h

### splice.h

### sqpoll.h

### statx.h

### sync.h

### tctx.h

### timeout.h

### truncate.h

### uring_cmd.h

### waitid.h

### xattr.h
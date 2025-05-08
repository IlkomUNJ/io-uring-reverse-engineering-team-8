# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

## another source
### alloc_cache.c

### cancel.c

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
file ini berisi implementasi operasi splice dan tree dalam konteks io_uring, yang memungkinkan untuk memindahkan dan menyalin data antar file descriptor secara asinkron. Fungsi-fungsi dalam kode ini memastikan bahwa file descriptor dan offset yang digunakan valid dan bahwa data dipindahkan secara efisien tanpa perlu menggunakan buffer tambahan di ruang pengguna.

### sqpoll.c
file ini berisikan mekanisme polling untuk submission queue dalam io_uring, yang memungkinkan aplikasi melakukan operasi I/O dengan latensi rendah dan efisiensi tinggi. Operasi in berkaitan dengan pembuatan dan pengelolaan thread kernel melalui antrian I/O anpa membuat aplikasi harus menunggu secara aktif, dan memaksimalkan penggunaan sumber daya CPU dengan pengaturan CPU affinity dan thread management. Tujuannya adalah untuk menangani operasi I/O secara efisien dengan meng-offload pekerjaan dari aplikasi ke kernel menggunakan io_uring yang lebih cepat dibandingkan model I/O tradisional.

### ststx.c
file ini digunakan dalam io_uring untuk melakukan metadata query terhadap file secara asinkron dan mengambil info file secara efisien tanpa syscall blocking biasa.

### sync.c 
file ini berisi implementasi sistem operasi linux, tepatnya untuk subsystem io_uring, yang merupakan antarmuka I/O (input/output) asinkron efisien di kernel Linux. 

### tctx.c 
file ini menangani manajemen hubungan antara proses dan ring io_uring yang memungkinkan efisiensi tinggi dengan menghindari syscall tambahan saat mengakses ring. selain itu file ini juga mengelola kontekstual data io uring antar thread dan memastikan alokasi dan pembersihan dilakukan dengan benar.

### timeout.c

### truncate.c
file ini berisi implementasi sistelI/O asinkron di linux, khususnya untuk memotong dan memperluas panjang file dengan sistem call. file ini juga memberi efisiensi tinggi untuk operasi I/O tanpa perlu memblokir proses pengguna.

### uring_cmd.c
file ini adalah bagian dari implementasi IO-uring di kernel Linux, yang berfungsi untuk menangani perintah-perintah terkait dengan socket dan IO asinkron lainnya melalui io_uring. 

### waitid.c
File ini bertujuan untuk menyediakan dukungan untuk operasi waitid yang asinkron menggunakan IO-uring, yang memungkinkan aplikasi untuk menunggu status proses anak tanpa memblokir thread utama. Operasi ini sangat berguna untuk aplikasi yang membutuhkan efisiensi tinggi dalam pengelolaan I/O, terutama dalam konteks pengelolaan proses anak di Linux.

### xattr.c
file ini berfungsi untuk mengimplementasikan fungsionalitas extended attributes (xattr) menggunakan IO-uring di linux. file ini menyediakan antarmuka untuk mengakses dan mengelola xattr secara asinkron melalui IO-uring.

### zcrx.c
file ini berisi mekanisme yang memungkinkan data dari jaringan diterima langsung ke memori pengguna tanpa disalin (zero-copy), sehingga menghemat waktu dan sumber daya CPU.

## Headers
Just declare the function specification. 

### advice.h

### alloc_cache.h

### cancel.h

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
file ini berisi operasi yang dapat meningkatkan efisiensi tranfer data antara file descripptor tanpa melibatkan salinan ke memori pengguna

### sqpoll.h
file ini berisi fungsi dan struktur io_sq_data yang memungkinkan io_uring untuk mengelola polling submission queue secara efisien dengan menggunakan thread kernel untuk mengelola dan memproses antrian I?O. Fungsi dan struktur ini digunakan untuk mengelola antrian pengajuan (submission queue) dan pengolahan tugas I/O asinkron dalam kernel dengan menggunakan polling untuk meningkatkan efisiensi dan mengurangi latensi. Tujuannya adalah untuk mengurangi latensi dan meningkatkan throughput I/O dengan meminimalkan waktu tunggu aplikasi.

### statx.hy
file ini memungkinkan aplikasi di user space menggunakan io_uring untuk mengakses data file tanpa bloking

### sync.h
file ini memungkinkan operasi seperti fsync(), sync_file_range(), dan fallocate(). Semua fungsi ini merupakan bagian dari implementasi io_uring untuk menangani operasi sinkron file dalam kernel Linux.

### tctx.h
file ini menangani relasi internal antara proses dan ring agar kernel tahu ring mana saja yang digunakan oleh prosess dan melakukan concelation, pembersihan otomatis dan registrasi ringfd secara efisien

### timeout.h
file ini berisi mekanisme timeout dalam io uring di kernel, digunakan untuk mengatur waktu suatu operasi I/O, membatalkan permintaan jika sudah melebihi batas waktu, dan mengelola linked timeout.

### truncate.h
file ini berisi deklarasi fungsi dalam kernel yang memberitahukan compiler bahwa dua fungsi bernama io_ftruncate_prep() dan io_ftruncate() tersedia untuk digunakan di tempat lain. Bagian ini memungkinkan IO-uring mendukung sistem call ftruncate() secara asinkron, sebagai bagian dari peningkatan performa I/O di Linux.

### uring_cmd.h
file ini adalah bagian dari implementasi IO-uring di kernel Linux, yang bertugas mengelola dan menangani perintah-perintah I/O asinkron melalui struktur seperti io_uring_cmd. Fungsinya meliputi persiapan, eksekusi, pembatalan, dan pembersihan perintah-perintah tersebut, memungkinkan aplikasi untuk melakukan operasi I/O dengan cara yang lebih efisien dan asinkron.

### waitid.h
file ini memungkinkan aplikasi untuk menunggu status proses anak dalam konteks asinkron dengan cara yang efisien, tanpa menghalangi eksekusi thread lain atau memblokir aplikasi, menggunakan IO-uring untuk memfasilitasi operasi tersebut.

### xattr.h
file ini memberikan dukungan untuk operasi xattr (baik membaca maupun menulis) pada file menggunakan mekanisme IO-uring di kernel Linux, dengan pengelolaan sumber daya yang efisien dan asinkron. 

### zcrx.h
file ini adalah header file untuk implementasi Zero-Copy Receive (ZCRX) dalam konteks IO-uring di Linux bertujuan untuk mengoptimalkan penerimaan data jaringan tanpa salinan ke memori pengguna, yang mengurangi overhead CPU.

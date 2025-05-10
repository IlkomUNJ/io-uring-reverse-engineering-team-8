# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

## another source
### alloc_cache.c
File ini mengelola cache alokasi memori untuk meningkatkan efisiensi penggunaan memori dalam io_uring. Fungsi io_alloc_cache_init menginisialisasi cache, io_alloc_cache_free membersihkan cache, dan io_cache_alloc_new mengalokasikan objek baru dengan opsi inisialisasi memori. File ini menggunakan fungsi kernel seperti kvmalloc_array dan kvfree untuk memastikan pengelolaan memori yang efisien.

### cancel.c
File ini menangani pembatalan permintaan asinkron dalam io_uring. Fungsi seperti io_async_cancel_one dan io_try_cancel membatalkan permintaan berdasarkan file descriptor, data pengguna, atau opcode. Pembatalan sinkron dilakukan melalui io_sync_cancel. File ini terintegrasi dengan subsistem seperti polling, timeout, dan futex untuk memastikan pembatalan aman dan sumber daya dibersihkan dengan benar.

### epoll.c
File ini digunakan untuk menangani operasi epoll dalam io_uring, seperti menambah, menghapus, atau mengubah event file descriptor secara asinkron. Struktur io_epoll menyimpan informasi fd, jenis operasi, dan event, sementara io_epoll_wait digunakan untuk menunggu event. Fungsi io_epoll_ctl_prep membaca data dari SQE dan menyiapkan operasi epoll, memungkinkan eksekusi tanpa blocking.

### eventfd.c
File ini mengelola integrasi eventfd dalam io_uring untuk notifikasi sinkronisasi. Struktur io_ev_fd menyimpan konteks eventfd dan status operasi. Fungsi seperti io_eventfd_put dan io_eventfd_free memastikan manajemen memori yang aman, sementara io_eventfd_do_signal mengirim notifikasi saat diperlukan. File ini memastikan eventfd bekerja efisien dan aman dalam io_uring.

### fdinfo.c
File ini digunakan untuk menampilkan informasi detail file descriptor io_uring melalui procfs. Fungsi io_uring_show_fdinfo mencetak status antrian SQ dan CQ, buffer pengguna, file pengguna, dan daftar operasi. Jika fitur NAPI aktif, status pelacakan NAPI juga ditampilkan. Sinkronisasi menggunakan mutex dan spinlock memastikan data aman, berguna untuk debugging dan pemantauan io_uring.

### filetable.c
File ini mengelola tabel file tetap dalam io_uring, memungkinkan file descriptor digunakan ulang untuk operasi I/O secara efisien. Fungsi seperti io_fixed_fd_install memasang file descriptor, sementara io_fixed_fd_remove menghapusnya. Alokasi slot dilakukan dinamis menggunakan bitmap, dengan validasi input dan sinkronisasi untuk mencegah konflik.

### fs.c
File ini menangani operasi file system dalam io_uring, seperti rename, unlink, mkdir, symlink, dan link. Fungsi seperti io_renameat dan io_unlinkat memproses operasi secara asinkron, dengan pengelolaan nama file menggunakan getname dan putname. Validasi input dan sinkronisasi memastikan operasi aman dan bebas konflik.

### futex.c
File ini menangani operasi futex (fast userspace mutex) dalam io_uring, seperti wait dan wake, secara asinkron. Fungsi io_futex_wait menunggu kondisi tertentu, sedangkan io_futex_wake membangunkan thread. Operasi ini menggunakan struktur io_futex dan memastikan pengelolaan memori aman melalui cache alokasi serta sinkronisasi dengan futex_queue dan futex_unqueue.

### io_uring.c
File ini bertanggung jawab atas inisialisasi dan pengelolaan utama sistem io_uring. Fungsi io_uring_setup membuat konteks io_uring, mengatur antrian SQ dan CQ, serta mendukung fitur seperti SQPOLL dan IOPOLL. Inisialisasi dilakukan melalui io_uring_init, yang mengatur cache memori, workqueue, dan sinkronisasi menggunakan spinlock dan mutex.

### io-wq.c
File ini mengelola worker thread pool untuk operasi asinkron dalam io_uring. Fungsi seperti create_io_worker dan io_wq_exit_workers digunakan untuk membuat dan menghentikan worker. Worker dikelompokkan menjadi bounded dan unbounded, dengan hashing untuk mencegah pekerjaan dengan hash sama berjalan paralel. Sinkronisasi dilakukan menggunakan spinlock dan RCU untuk menjaga konsistensi data.

### kbuf.c
File ini bertujuan untuk mengelola buffer untuk operasi I/O dalam io_uring, memungkinkan aplikasi melakukan I/O secara efisien tanpa blocking. File ini mendukung pendaftaran, pemilihan, dan penghapusan buffer, yang sangat berguna untuk aplikasi dengan kebutuhan I/O tinggi seperti server atau pengolahan data besar.

### memmap.c
File ini menangani pemetaan memori dalam io_uring, baik untuk alokasi memori kernel maupun pemetaan memori pengguna. Fungsi seperti io_uring_mmap dan io_create_region digunakan untuk memvalidasi dan mengelola region memori. File ini mendukung arsitektur dengan atau tanpa MMU, memastikan keamanan melalui validasi input dan sinkronisasi menggunakan mmap_lock.

### msg_ring.c
File ini mendukung pengiriman pesan efisien dalam lingkungan I/O asinkron dengan pemrosesan data dan file secara aman antar konteks. Fungsi io_msg_ring memungkinkan pengiriman data atau file descriptor dengan perintah seperti IORING_MSG_DATA. Validasi memastikan hanya operasi valid yang diproses, dan sinkronisasi menggunakan mutex serta spinlock menjaga konsistensi data.

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
File ini berisi implementasi operasi splice dan tree dalam konteks io_uring, yang memungkinkan untuk memindahkan dan menyalin data antar file descriptor secara asinkron. Fungsi-fungsi dalam kode ini memastikan bahwa file descriptor dan offset yang digunakan valid dan bahwa data dipindahkan secara efisien tanpa perlu menggunakan buffer tambahan di ruang pengguna.

### sqpoll.c
File ini berisikan mekanisme polling untuk submission queue dalam io_uring, yang memungkinkan aplikasi melakukan operasi I/O dengan latensi rendah dan efisiensi tinggi. Operasi in berkaitan dengan pembuatan dan pengelolaan thread kernel melalui antrian I/O anpa membuat aplikasi harus menunggu secara aktif, dan memaksimalkan penggunaan sumber daya CPU dengan pengaturan CPU affinity dan thread management. Tujuannya adalah untuk menangani operasi I/O secara efisien dengan meng-offload pekerjaan dari aplikasi ke kernel menggunakan io_uring yang lebih cepat dibandingkan model I/O tradisional.

### ststx.c
File ini digunakan dalam io_uring untuk melakukan metadata query terhadap file secara asinkron dan mengambil info file secara efisien tanpa syscall blocking biasa.

### sync.c 
File ini berisi implementasi sistem operasi linux, tepatnya untuk subsystem io_uring, yang merupakan antarmuka I/O (input/output) asinkron efisien di kernel Linux. 

### tctx.c 
File ini menangani manajemen hubungan antara proses dan ring io_uring yang memungkinkan efisiensi tinggi dengan menghindari syscall tambahan saat mengakses ring. selain itu file ini juga mengelola kontekstual data io uring antar thread dan memastikan alokasi dan pembersihan dilakukan dengan benar.

### timeout.c
File ini mengelola operasi timeout di io_uring, termasuk penjadwalan, pembatalan, dan pembaruan timer. File ini memastikan proses timeout berjalan efisien dan sinkron dengan mekanisme io_uring.

### truncate.c
File ini berisi implementasi sistem I/O asinkron di linux, khususnya untuk memotong dan memperluas panjang file dengan sistem call. file ini juga memberi efisiensi tinggi untuk operasi I/O tanpa perlu memblokir proses pengguna.

### uring_cmd.c
File ini adalah bagian dari implementasi IO-uring di kernel Linux, yang berfungsi untuk menangani perintah-perintah terkait dengan socket dan IO asinkron lainnya melalui io_uring. 

### waitid.c
File ini bertujuan untuk menyediakan dukungan untuk operasi waitid yang asinkron menggunakan IO-uring, yang memungkinkan aplikasi untuk menunggu status proses anak tanpa memblokir thread utama. Operasi ini sangat berguna untuk aplikasi yang membutuhkan efisiensi tinggi dalam pengelolaan I/O, terutama dalam konteks pengelolaan proses anak di Linux.

### xattr.c
File ini berfungsi untuk mengimplementasikan fungsionalitas extended attributes (xattr) menggunakan IO-uring di linux. file ini menyediakan antarmuka untuk mengakses dan mengelola xattr secara asinkron melalui IO-uring.

### zcrx.c
File ini berisi mekanisme yang memungkinkan data dari jaringan diterima langsung ke memori pengguna tanpa disalin (zero-copy), sehingga menghemat waktu dan sumber daya CPU.

## Headers
Just declare the function specification. 

### advice.h
File ini berisi fungsi untuk mendukung operasi madvise dan fadvise dalam konteks io_uring. Fungsi-fungsi ini memungkinkan pengelolaan memori dan pola akses file secara efisien dengan cara memberikan saran kepada kernel.

### alloc_cache.h
File ini menyediakan fungsi untuk caching alokasi memori di io_uring. Fungsi fungsi di dalamnya juga mendukung keamanan memori dengan KASAN  (Kernel Address Sanitizer).

### cancel.h
File ini mendefinisikan fungsi-fungsi untuk menangani pembatalan operasi di io_uring dengan efisien.

### epoll.h
File ini berisi fungsi-fungsi yang digunakan untuk mengelola (ctl) dan menunggu (wait) event pada file descriptor menggunakan mekanisme epoll. Fungsi-fungsi ini hanya akan tersedia jika konfigurasi CONFIG_EPOLL diaktifkan. 

### eventfd.h
File ini berisi fungsi-fungsi untuk mengelola eventfd dalam konteks io_uring. Fungsi-fungsi ini juga digunakan untuk menangani notifikasi berbasis eventfd di io_uring.

### fdinfo.h
File ini mendefinisikan fungsi io_uring_show_fdinfo, yang digunakan untuk menampilkan informasi file descriptor (fd) terkait io_uring, biasanya untuk keperluan debugging.

### filetable.h
File ini berisi fungsi-fungsi untuk mengelola tabel file dalam io_uring. Fungsi-fungsi ini dirancang untuk mengelola file descriptor tetap dan tabel file dengan efisien dalam operasi io_uring.

### fs.h
File ini berisi fungsi untuk operasi sistem file dalam io_uring. Fungsi didalamnya mencakup persiapan, eksekusi, dan pembersihan operasi.

### futex.h
File ini berisi fungsi-fungsi untuk operasi futex dalam io_uring. Fungsi tersebut dioptimalkan untuk mendukung operasi sinkronisasi berbasis futex di io_uring. 

### io_uring.h
File ini mendefinisikan berbagai fungsi, struktur, dan makro yang menjadi inti dari implementasi io_uring. Berbagai fungsi tersebut dirancang untuk mendukung operasi asinkron yang efisien dalam io_uring.

### io-wq.h
File ini berisi struktur dan fungsi untuk mengelola worker queue (WQ) dalam io_uring. Fungsi ini dirancang untuk mendukung eksekusi pekerjaan asinkron secara efisien di io_uring.

### kbuf.h
File ini berisi struktur dan fungsi untuk mengelola buffer kernel dalam io_uring. Fungsinya mencakup pendaftaran, pemilihan, dan penghapusan buffer untuk mendukung operasi I/O yang efisien tanpa blocking.

### memmap.h
File ini berisi fungsi untuk mengelola pemetaan memori di io_uring, seperti memetakan halaman memori pengguna, menangani operasi mmap, dan mengelola region memori yang dipetakan. Fungsi ini memastikan pemrosesan I/O berbasis memori berjalan efisien dan aman.

### msg_ring.h
File ini berisi fungsi untuk mengelola pengiriman pesan antar ring di io_uring. Fungsinya mencakup sinkronisasi, persiapan, eksekusi, dan pembersihan operasi pesan, memungkinkan komunikasi antar ring berjalan efisien.

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
File ini berisi operasi yang dapat meningkatkan efisiensi transfer data antara file descripptor tanpa melibatkan salinan ke memori pengguna.

### sqpoll.h
File ini berisi fungsi dan struktur io_sq_data yang memungkinkan io_uring untuk mengelola polling submission queue secara efisien dengan menggunakan thread kernel untuk mengelola dan memproses antrian I/O. Fungsi dan struktur ini digunakan untuk mengelola antrian pengajuan (submission queue) dan pengolahan tugas I/O asinkron dalam kernel dengan menggunakan polling untuk meningkatkan efisiensi dan mengurangi latensi. Tujuannya adalah untuk mengurangi latensi dan meningkatkan throughput I/O dengan meminimalkan waktu tunggu aplikasi.

### statx.hy
File ini memungkinkan aplikasi di user space menggunakan io_uring untuk mengakses data file tanpa bloking.

### sync.h
File ini memungkinkan operasi seperti fsync(), sync_file_range(), dan fallocate(). Semua fungsi ini merupakan bagian dari implementasi io_uring untuk menangani operasi sinkron file dalam kernel Linux.

### tctx.h
File ini menangani relasi internal antara proses dan ring agar kernel tahu ring mana saja yang digunakan oleh prosess dan melakukan concelation, pembersihan otomatis dan registrasi ringfd secara efisien.

### timeout.h
File ini berisi mekanisme timeout dalam io uring di kernel, digunakan untuk mengatur waktu suatu operasi I/O, membatalkan permintaan jika sudah melebihi batas waktu, dan mengelola linked timeout.

### truncate.h
File ini berisi deklarasi fungsi dalam kernel yang memberitahukan compiler bahwa dua fungsi bernama io_ftruncate_prep() dan io_ftruncate() tersedia untuk digunakan di tempat lain. Bagian ini memungkinkan IO-uring mendukung sistem call ftruncate() secara asinkron, sebagai bagian dari peningkatan performa I/O di Linux.

### uring_cmd.h
File ini adalah bagian dari implementasi IO-uring di kernel Linux, yang bertugas mengelola dan menangani perintah-perintah I/O asinkron melalui struktur seperti io_uring_cmd. Fungsinya meliputi persiapan, eksekusi, pembatalan, dan pembersihan perintah-perintah tersebut, memungkinkan aplikasi untuk melakukan operasi I/O dengan cara yang lebih efisien dan asinkron.

### waitid.h
File ini memungkinkan aplikasi untuk menunggu status proses anak dalam konteks asinkron dengan cara yang efisien, tanpa menghalangi eksekusi thread lain atau memblokir aplikasi, menggunakan IO-uring untuk memfasilitasi operasi tersebut.

### xattr.h
File ini memberikan dukungan untuk operasi xattr (baik membaca maupun menulis) pada file menggunakan mekanisme IO-uring di kernel Linux, dengan pengelolaan sumber daya yang efisien dan asinkron. 

### zcrx.h
File ini adalah header file untuk implementasi Zero-Copy Receive (ZCRX) dalam konteks IO-uring di Linux bertujuan untuk mengoptimalkan penerimaan data jaringan tanpa salinan ke memori pengguna, yang mengurangi overhead CPU.

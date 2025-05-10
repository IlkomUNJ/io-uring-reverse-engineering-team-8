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
File ini mengatur integrasi NAPI (New API untuk network polling) dalam konteks io_uring, khususnya untuk optimasi busy-polling yang memungkinkan proses menunggu IO tetap aktif memantau aktivitas jaringan (tanpa langsung tidur).
File ini menangani:
- Registrasi dan penghapusan NAPI ID (__io_napi_add_id, __io_napi_del_id) ke dalam hash table dan list internal io_ring_ctx.
- Eksekusi loop busy-polling melalui __io_napi_do_busy_loop untuk dua mode: static tracking dan dynamic tracking.
- Penghapusan entri NAPI yang sudah usang (stale) berdasarkan timeout.
- Fungsi io_register_napi dan io_unregister_napi digunakan untuk mengaktifkan atau menonaktifkan tracking NAPI dari userspace.
- File ini hanya aktif bila kernel dibangun dengan flag CONFIG_NET_RX_BUSY_POLL.
Fitur ini penting agar io_uring bisa meningkatkan performa pada beban IO yang tinggi dengan meminimalkan latensi polling jaringan.

### net.c
File ini berisi implementasi lengkap untuk operasi jaringan (networking) dalam io_uring, termasuk fungsi-fungsi seperti send, recv, accept, connect, listen, bind, serta varian zero-copy (send_zc, recvzc) dan multishot. File ini menangani semua network syscall wrappers untuk IO berbasis socket, serta mengelola alokasi dan daur ulang buffer secara efisien menggunakan per-request async structures (io_async_msghdr).
Sebagian besar struktur data dalam file ini digunakan untuk menyimpan parameter dan status dari operasi IO jaringan asinkron. File ini juga berisi banyak logika pengolahan buffer selection, retry, dan multishot handling untuk performa tinggi dan efisiensi IO secara terus-menerus tanpa blocking.

### nop.c
File ini mengimplementasikan operasi NOP (No Operation) dalam io_uring, yaitu perintah yang secara teknis tidak melakukan aksi IO nyata, tetapi bisa digunakan untuk mengontrol dan menguji berbagai fitur lanjutan seperti penggunaan file descriptor tetap (FIXED_FILE), buffer tetap (FIXED_BUFFER), atau menyisipkan hasil buatan ke dalam antrian hasil (INJECT_RESULT).
File ini berguna sebagai mekanisme pengujian internal, serta untuk menyisipkan logika dummy atau kontrol dalam urutan operasi io_uring.

### notif.c
File ini menangani mekanisme notifikasi untuk zerocopy network transmission (pengiriman data tanpa penyalinan memori) dalam io_uring. Intinya, ketika data dikirim dengan zerocopy, kernel tidak langsung tahu kapan buffer bisa dibebaskan. Oleh karena itu, notifikasi diperlukan untuk memberi tahu kapan pengiriman sudah selesai dan buffer bisa digunakan ulang.
File ini penting untuk memastikan sinkronisasi dan pengelolaan memori saat menggunakan fitur zerocopy send di io_uring, yang sangat berguna untuk mengurangi beban CPU pada aplikasi jaringan throughput tinggi.

### opdef.c
File ini bertanggung jawab sebagai tabel utama definisi semua operasi (opcode) yang didukung oleh io_uring. File ini mengatur bagaimana setiap perintah seperti READ, WRITE, SEND, RECV, FSYNC, dan lain-lain dipetakan ke fungsi-fungsi pelaksana (prep dan issue) serta informasi pendukung seperti kebutuhan file, apakah operasi butuh polling, buffer tetap, dan lain-lain.

### openclose.c
File ini menangani operasi pembukaan (open) dan penutupan (close) file descriptor, termasuk juga pengelolaan file descriptor tetap (fixed FD) dalam konteks io_uring. Struktur io_open, io_close, dan io_fixed_install digunakan untuk menyimpan parameter dan status eksekusi dari masing-masing jenis operasi.
File ini penting untuk mengatur siklus hidup file descriptor dalam io_uring, terutama untuk optimasi performa melalui FD tetap dan pembukaan nonblocking yang bisa diproses secara async bila diperlukan.

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
File ini adalah header untuk fitur integrasi NAPI (New API) busy-polling dalam io_uring, dan mendeklarasikan fungsi-fungsi serta makro inline yang berkaitan dengan tracking dan penggunaan NAPI ID untuk meningkatkan performa IO jaringan, khususnya saat menggunakan IO_URING_NAPI_TRACKING_DYNAMIC.
Selain itu, file ini juga menyertakan versi fallback (fungsi kosong atau pengembalian error -EOPNOTSUPP) jika kernel tidak dikompilasi dengan CONFIG_NET_RX_BUSY_POLL.

### net.h
File ini adalah header deklarasi untuk semua operasi io_uring yang berhubungan dengan jaringan (networking). Fungsi-fungsi yang dideklarasikan di sini seperti io_send, io_recv, io_accept, io_connect, io_socket, io_bind, io_listen, dan varian zerocopy (io_send_zc, io_sendmsg_zc) adalah bagian dari lapisan abstraksi io_uring terhadap socket-based IO.
File ini berperan penting dalam menghubungkan subsistem socket Linux dengan io_uring, serta mempersiapkan operasi-operasi jaringan agar bisa dijalankan dalam mode async dan nonblocking melalui mekanisme submission queue io_uring.

### nop.h
File ini merupakan header deklarasi untuk operasi NOP (No Operation) dalam io_uring. Meskipun NOP tidak melakukan IO nyata, file ini mendeklarasikan dua fungsi utama:
- io_nop_prep(): menyiapkan struktur internal dari SQE berdasarkan flag dan parameter seperti fd, buf_index, dan len.
- io_nop(): mengeksekusi operasi NOP, yang hanya menghasilkan hasil buatan (result) dan dapat digunakan untuk menguji berbagai jalur eksekusi seperti pemakaian file descriptor tetap (FIXED_FILE) atau buffer tetap (FIXED_BUFFER).

### notif.h
File ini mendefinisikan kerangka notifikasi yang memungkinkan kernel memberi tahu io_uring bahwa buffer jaringan tertentu telah selesai digunakan—hal ini penting untuk menghindari kebocoran memori dan menjamin efisiensi dalam transfer data berskala besar menggunakan zerocopy.

### opdef.h
File ini bertugas sebagai pondasi metadata dari semua operasi io_uring, memungkinkan sistem mengenali cara menangani tiap opcode secara efisien dan aman.

### openclose.h
File ini merupakan header deklarasi untuk operasi manajemen file descriptor (FD) di io_uring, khususnya operasi open, close, dan install_fixed_fd.
Fungsi-fungsi yang dideklarasikan antara lain:
- io_openat_prep() dan io_openat2_prep() untuk menyiapkan parameter pembukaan file berdasarkan SQE.
- io_openat() dan io_openat2() untuk benar-benar membuka file dengan berbagai mode (seperti O_TMPFILE, O_CLOEXEC) dan menangani pemasangan file descriptor tetap (fixed file slot).
- io_close_prep() dan io_close() untuk menutup FD, baik normal maupun fixed, serta memastikan keamanan dalam konteks multithread (files_struct).
- io_install_fixed_fd_prep() dan io_install_fixed_fd() untuk menerima FD dari syscall receive_fd dan memasangnya sebagai fixed FD dalam konteks io_uring.
Fungsi-fungsi ini mendukung optimalisasi IO dengan menghindari overhead lookup file descriptor berulang, serta memungkinkan kontrol penuh terhadap manajemen FD dari userspace.

### zcrx.h
File ini merupakan header untuk implementasi zero-copy receive (ZC RX) di io_uring, yaitu mekanisme untuk menerima data jaringan tanpa menyalin ke memori pengguna, melainkan langsung memetakan memori kernel ke aplikasi.
File ini bertanggung jawab untuk mendukung IO jaringan ultra-efisien, khususnya untuk aplikasi berperforma tinggi seperti jaringan 100G yang memerlukan latensi rendah dan pemrosesan data langsung dari kernel.

### openclose.h
File ini menyusun fondasi untuk pengelolaan file descriptor secara eksplisit dan efisien dalam io_uring, termasuk untuk skenario penggunaan ulang FD tanpa lookup serta pembukaan file nonblocking yang bisa diproses async.

### poll.h
File ini mendeklarasikan struktur dan fungsi untuk mengelola operasi polling (pemantauan readiness IO) dalam io_uring, terutama untuk FD (file descriptor) yang mendukung operasi nonblocking.
File ini memungkinkan io_uring memantau readiness tanpa blocking, menghemat syscall dan latency, serta penting dalam aplikasi skala besar seperti server jaringan atau event-loop berbasis epoll yang kini digantikan oleh io_uring.

### refs.h
File ini berisi fungsi-fungsi manajemen reference counter untuk objek permintaan (io_kiocb) dalam io_uring. Reference counting digunakan untuk melacak jumlah referensi aktif terhadap request, sehingga objek hanya akan dibebaskan ketika tidak lagi digunakan di jalur eksekusi manapun.
File ini menyediakan mekanisme reference counting yang efisien dan aman untuk memori dan sinkronisasi di lingkungan yang sangat konkuren seperti io_uring, terutama saat permintaan bisa diakses dari berbagai thread atau task work secara asinkron.

### register.h
File ini merupakan header deklarasi untuk fungsi-fungsi terkait registrasi dan pengelolaan sumber daya (resource) dalam io_uring, terutama yang berkaitan dengan eventfd dan personality.
File ini adalah bagian dari lapisan abstraksi registrasi resource yang memungkinkan io_uring melakukan optimisasi melalui pra-pendaftaran dan akses langsung terhadap file atau kredensial, tanpa harus melakukan syscall tambahan saat runtime.

### rsrc.h
File ini mendefinisikan struktur data dan fungsi-fungsi terkait yang digunakan untuk mengelola sumber daya input/output (I/O) dalam konteks I/O asinkron menggunakan io_uring. File ini mencakup pengelolaan berbagai jenis sumber daya seperti file dan buffer yang digunakan dalam operasi I/O, serta alokasi dan pembebasan memori untuk sumber daya tersebut. Beberapa fungsi yang terdapat dalam file ini bertanggung jawab untuk menangani registrasi, pembaruan, dan pembebasan sumber daya, serta pengelolaan referensi untuk mencegah kebocoran memori. Ada juga struktur yang mengatur buffer dan vektor yang digunakan untuk memanipulasi data selama operasi I/O. Penggunaan struktur io_rsrc_node dan io_mapped_ubuf membantu dalam menyimpan informasi tentang buffer dan file yang terkait dengan I/O.

### rw.h
File ini mengelola operasi baca/tulis asinkron menggunakan io_uring, termasuk persiapan dan eksekusi operasi I/O untuk buffer dan file. Struktur io_async_rw menyimpan informasi terkait vektor I/O, status iterasi, dan metadata. Fungsi-fungsinya menangani operasi baca/tulis, pembersihan, serta penanganan kesalahan dan cache memori untuk efisiensi.

### slist.h
File ini berisi operasi untuk mengelola daftar terhubung (linked list) yang digunakan dalam konteks antrian tugas asinkron di io_uring. Fungsi-fungsi dalam file ini memungkinkan penambahan, penghapusan, pemotongan, dan pemindahan elemen dalam daftar, baik di awal, tengah, atau akhir daftar. Operasi tersebut dirancang untuk efisiensi dalam penanganan elemen yang akan dieksekusi, seperti penjadwalan tugas I/O. Struktur data yang digunakan adalah io_wq_work_node dan io_wq_work_list, yang berfungsi untuk mengelola antrian kerja dalam sistem.

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

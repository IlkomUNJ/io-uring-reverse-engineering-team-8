# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

## another source
### alloc_cache.c

### cancel.c

### epoll.c
File ini digunakan untuk menangani operasi epoll dalam io_uring, seperti menambah, menghapus, atau mengubah event file descriptor (fd) yang ingin dipantau. Ada 2 struktur utama yaitu: io_epoll dan io_epoll_wait. Struktur io_epoll menyimpan informasi seperti fd tujuan, jenis operasi (seperti EPOLL_CTL_ADD), dan event yang akan dipasang. Fungsi io_epoll_ctl_prep() akan membaca data dari SQE (submission queue entry), lalu menyimpan nilai-nilai tersebut ke dalam struktur. Jika operasi membutuhkan event, event tersebut juga akan disalin dari user space. Fungsi ini membantu agar operasi epoll bisa dilakukan secara asynchronous lewat io_uring, tanpa perlu blocking seperti biasanya.

### eventfd.c
File ini mengatur bagaimana io_uring menangani eventfd, yaitu mekanisme sinkronisasi sederhana di Linux yang sering digunakan untuk notifikasi antar proses atau thread. Di sini, struktur io_ev_fd menyimpan informasi tentang konteks eventfd, status operasi, dan referensi yang dipakai untuk manajemen memori. Fungsi-fungsi seperti io_eventfd_put() dan io_eventfd_free() digunakan untuk mengelola siklus hidup (lifetime) dari struktur ini, memastikan bahwa memori dibebaskan dengan aman setelah tidak digunakan lagi. Selain itu, ada fungsi io_eventfd_do_signal() yang bertugas untuk mengirim sinyal (notifikasi) ketika dibutuhkan. Semua ini digunakan agar eventfd dapat bekerja secara aman dan efisien dalam ekosistem io_uring.

### fdinfo.c
File ini digunakan untuk menampilkan informasi detail dari file descriptor io_uring lewat sistem /proc, khususnya di /proc/<pid>/fdinfo/<fd>. Fungsi utama dalam file ini adalah io_uring_show_fdinfo(), yang bertugas mencetak data internal seperti status antrian SQ (submit queue) dan CQ (completion queue), termasuk nilai head, tail, serta isi dari SQEs dan CQEs yang sedang diproses. Selain itu, jika io_uring berjalan dalam mode polling (IORING_SETUP_SQPOLL), file ini juga menampilkan informasi tentang thread yang menangani polling, termasuk PID dan CPU tempat thread itu berjalan. File ini juga menunjukkan daftar file dan buffer yang sedang digunakan oleh aplikasi melalui io_uring, serta informasi identitas pengguna (disebut “personalities”) yang mungkin berbeda tergantung operasi yang dijalankan. Di akhir, terdapat juga daftar permintaan I/O yang sedang dipantau (poll list), serta hasil I/O yang sempat tidak muat di antrian (cq overflow). Semua informasi ini sangat berguna untuk keperluan debugging dan pemantauan performa aplikasi yang menggunakan io_uring.

### filetable.c
File ini menangani pengelolaan file descriptor tetap (fixed file descriptors) untuk io_uring. File descriptor tetap memungkinkan aplikasi mendaftarkan file sekali dan menggunakannya berulang kali untuk operasi I/O tanpa membuka-tutup ulang, sehingga lebih efisien. Fungsi utamanya mencakup alokasi dan pembebasan tabel file (io_alloc_file_tables, io_free_file_tables), pencarian slot kosong dalam bitmap (io_file_bitmap_get), pemasangan file ke slot (__io_fixed_fd_install, io_fixed_fd_install), serta penghapusan file dari slot (io_fixed_fd_remove). Ada juga fitur untuk mengatur rentang slot yang boleh dialokasikan otomatis (io_register_file_alloc_range). Secara keseluruhan, file ini membantu meningkatkan kinerja dan efisiensi I/O di io_uring.

### fs.c
File ini berisi kode C untuk menangani berbagai operasi file system (seperti rename, unlink, mkdir, symlink, dan link) dengan menggunakan API **io\_uring**, yang memungkinkan operasi I/O dilakukan secara asinkron dan lebih efisien di Linux. Setiap operasi memiliki struktur data sendiri untuk menyimpan informasi terkait file, seperti nama file, flags, dan descriptor file. Fungsi utama dalam kode ini dibagi menjadi tiga bagian: persiapan (prep), eksekusi (do\_<operation>), dan pembersihan (cleanup). Fungsi persiapan bertugas untuk memvalidasi parameter dan menyiapkan data yang diperlukan, seperti mengonversi alamat file atau path menjadi format yang bisa diproses. Eksekusi melakukan operasi file system yang sebenarnya (misalnya, mengubah nama file atau menghapus file), sementara pembersihan membersihkan sumber daya yang digunakan setelah operasi selesai.

Dengan menggunakan **io\_uring**, kode ini memungkinkan operasi file dilakukan secara asinkron, mengurangi overhead I/O, dan meningkatkan efisiensi dalam menangani file system. Alur kerjanya dimulai dengan mempersiapkan data, kemudian menjalankan operasi, dan akhirnya membersihkan sumber daya setelah operasi selesai.

### futex.c
Kode ini mengimplementasikan beberapa operasi terkait **futex** dalam konteks **io\_uring**, yang merupakan API I/O asinkron di Linux. Futex adalah mekanisme sinkronisasi yang digunakan untuk menunggu dan membangunkan proses berdasarkan nilai tertentu di memori, sering kali digunakan untuk menghindari busy-waiting dalam program multithreading. Dalam kode ini, beberapa struktur data seperti `io_futex` dan `io_futex_data` digunakan untuk menyimpan informasi terkait dengan operasi futex, seperti alamat futex, nilai yang digunakan untuk membandingkan, dan berbagai flag futex. Fungsi utama dalam kode ini meliputi `io_futex_prep` yang menyiapkan data untuk operasi futex, `io_futex_wait` dan `io_futexv_wait` yang menangani penundaan (wait) pada futex, serta `io_futex_wake` yang digunakan untuk membangunkan proses yang sedang menunggu futex tersebut. Semua operasi ini dioptimalkan dengan menggunakan mekanisme **io\_uring**, yang memungkinkan I/O dilakukan secara asinkron tanpa memblokir thread, sehingga meningkatkan performa dalam aplikasi yang membutuhkan banyak operasi I/O. Fungsi-fungsi tersebut juga mencakup validasi data input untuk memastikan bahwa alamat dan nilai yang digunakan dalam operasi futex sesuai dengan yang diharapkan. Jika diperlukan, kode ini juga mendukung pembatalan operasi futex melalui fungsi seperti `io_futex_cancel`. Secara keseluruhan, kode ini berfokus pada penyempurnaan operasi futex dengan memanfaatkan keunggulan **io\_uring** untuk mencapai efisiensi tinggi dalam sistem Linux.

### io_uring.c


### io-wq.c


### kbuf.c
Secara keseluruhan, kode ini bertujuan untuk mengelola buffer yang digunakan dalam operasi I/O di kernel Linux dengan menggunakan io_uring, yang membantu aplikasi melakukan I/O dengan cara yang lebih efisien, tanpa harus melakukan blocking pada thread atau proses utama. Hal ini sangat berguna untuk aplikasi yang memerlukan I/O dalam jumlah besar, seperti server atau aplikasi yang bekerja dengan data besar, di mana performa sangat penting.

Dengan kata lain, io_uring ini memungkinkan operasi I/O yang lebih cepat dan lebih efisien di tingkat sistem operasi, dengan meminimalkan overhead yang terjadi akibat operasi I/O yang memblokir proses utama.

### memmap.c
Kode yang diberikan adalah bagian dari implementasi **io\_uring** di kernel Linux, yang bertujuan untuk mengelola memori secara efisien dalam operasi I/O asinkron. Fungsi utama dari kode ini adalah untuk mengalokasikan dan memetakan memori, baik dari kernel maupun dari memori pengguna, ke dalam ruang alamat yang dapat diakses oleh sistem I/O. Halaman-halaman memori pengguna dapat "dipin" atau dipertahankan agar tidak dipindahkan oleh sistem, sementara memori lainnya dialokasikan secara dinamis. Selain itu, kode ini juga menangani pembebasan memori dan pemetaan untuk operasi `mmap`, yang memungkinkan aplikasi mengakses memori secara langsung melalui memori virtual. Semua ini bertujuan untuk meningkatkan efisiensi dalam proses I/O yang lebih cepat dan terisolasi antar konteks.

### msg_ring.c
Kode ini adalah bagian dari implementasi **io\_uring** di Linux, yang menangani komunikasi pesan antar konteks I/O secara asinkron. Fungsinya meliputi pengelolaan pengiriman data dan file descriptor antara konteks yang berbeda, baik secara lokal maupun remote. Dengan menggunakan struktur data `io_msg`, kode ini mengatur pesan, file sumber, dan berbagai flag serta command yang relevan. Sinkronisasi dilakukan dengan mutex dan spinlock untuk menghindari kondisi race, sedangkan verifikasi parameter dilakukan sebelum eksekusi. Fungsi seperti `io_msg_ring_data` dan `io_msg_send_fd` menangani pengiriman pesan, sementara pengelolaan file dilakukan melalui operasi `get_file` dan `fput`. Secara keseluruhan, kode ini mendukung pengiriman pesan efisien dalam lingkungan I/O asinkron dengan pemrosesan data dan file secara aman antar konteks.


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
io_madvise_prep and io_fadvise_prep are preparation functions that likely set up the necessary information for issuing a madvise or fadvise operation.

io_madvise and io_fadvise are functions that actually issue the madvise or fadvise operation, likely handling the I/O with the appropriate flags and completing the task.

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

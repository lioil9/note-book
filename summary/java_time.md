## java中日期时间的使用注意

- SimpleDateTime 是线程不安全的，一般如果设置为局部变量时，每次都会new一个对象，较为消耗内存资源

- 所以应当使用LocalDateTime来代替使用，一般 LocalDate可以表示日期而LocalTime可以表示时间，则用LocalDateTime来表示
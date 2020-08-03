## java中日期时间的使用注意

- SimpleDateTime 是线程不安全的，一般如果设置为局部变量时，每次都会new一个对象，较为消耗内存资源

- 所以应当使用LocalDateTime来代替使用，一般 LocalDate可以表示日期而LocalTime可以表示时间，则用LocalDateTime来表示



今天我和大家一起聊一聊SimpleDateFormat ，这都2020年了，怎么还在用SimpleDateFormat ？

其实，作为一名Java 程序员，我们会经常在编程时候和时间打交道，比如要把某一个时间存储到数据库中去，而我们直接使用

Datedate = newDate(); System.out.println(date);

得到的时间都是这样的

SunJun 07 17:22:52CST 2020

因此，我们经常需要把时间进行格式化处理，然后在进行存储，方便阅读。这个时候我们就会使用到SimpleDateFormat 类，比如使用下面的代码来获取当前时间，并调用SimpleDateFormat 对时间进行格式化：

Date date = newDate(); SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式String datestr = df.format(date);System.out.println(datestr);

最终输出的时间为

2020-06-07 16:45:58

由于在java 8之前 SimpleDateFormat 是一个比较常用的类，但是我还是在这里要建议开发者不要用 SimpleDateForma。原因有两点:

**首先，通过new 一个对象来操作对象，占用内存大**，如果每处理一个时间信息的时候，就需要new一个SimpleDateFormat实例对象，然后再丢弃这个对象。大量的对象就这样被创建出来，占用大量的内存和 jvm空间。

那么很多人就会想，既然new 代价太大， 不如我们使用 static 将其设置为共享变量，这样就可以减小频繁创建对象带来的内存开销啦,真的是机智如我。

privatestatic SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

但是这样操作在并发量非常大的情况下，由于 SimpleDateFormat 是线程不安全的，这也是第二点原因，这个在JDK文档中已经明确表明了SimpleDateFormat不应该用在多线程场景中：

Date formats are not synchronized. It is recommended to create separate format instances for each thread. If multiple threads access a format concurrently, it must be synchronized externally.

在《阿里巴巴 Java 开发手册》中也明确表示不要定义SimpleDateFormat 为static 变量，如果定义static 必须要加锁。

![img](https://pics2.baidu.com/feed/d833c895d143ad4b6cba8416e5728ba9a60f06c3.png?token=0e7cb3d1b060850b8f1b73807db2a8fa)

这背后的原因是由于 SimpleDateFormat 中的format方法在执行过程中，会使用一个成员变量calendar来保存时间。

private StringBuffer format(Date date, StringBuffer toAppendTo, FieldDelegate delegate) {this.calendar.setTime(date); boolean useDateFormatSymbols = this.useDateFormatSymbols();int i = 0; ……

由于在声明SimpleDateFormat的时候，使用的是static定义的。那么这个SimpleDateFormat就是一个共享变量，SimpleDateFormat 中的calendar也就可以被多个线程访问到。

举个例子：假设一个线程A刚执行完calendar.setTime把时间设置成2020-05-07，这个线程还没执行完，线程B又执行了calendar.setTime把时间改成了2020-06-07。这时候线程A继续往下执行，拿到的calendar.getTime得到的时间就是线程B改过之后的。

除了format方法以外，SimpleDateFormat的parse方法也有同样的问题。

所以，不要把SimpleDateFormat作为一个共享变量使用。

那么如何解决这样的问题呢？如果你使用的是Java 8 之前的JDK，那么上面的《阿里巴巴Java 开发手册》已经给出了解决方案，那就是使SimpleDateFormat 变成线程安全的，通过加锁的方式来解决

privatestatic ThreadLocal<DateFormat> threadLocal = new ThreadLocal<DateFormat>() {@Overrideprotected DateFormat initialValue(){returnnew SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); } };

而如果你使用的是Java 8 + 的版本，那么你完全可以抛弃这种线程不安全的时间格式化方法。可以使用DateTimeFormatter代替SimpleDateFormat，这是一个线程安全的格式化工具类。

***\*LocalDate 和LocalDateTime\****

Java 8开始，明确了日期时间概念，例如：瞬时（instant）、 长短（duration）、日期、时间、时区和周期。

同时继承了Joda 库按人类语言和计算机各自解析的时间处理方式。不同于老版本，新API基于ISO标准日历系统，java.time包下的所有类都是不可变类型而且线程安全。

**关键类**

Instant：瞬时实例。LocalDate：本地日期，不包含具体时间 例如：2014-01-14 可以用来记录生日、纪念日、加盟日等。LocalTime：本地时间，不包含日期。LocalDateTime：组合了日期和时间，但不包含时差和时区信息。ZonedDateTime：最完整的日期时间，包含时区和相对UTC或格林威治的时差。新API还引入了 ZoneOffSet 和 ZoneId 类，使得解决时区问题更为简便。解析、格式化时间的 DateTimeFormatter 类也全部重新设计。

例如，我们使用LocalDate 代替Date，使用DateTimeFormatter 代替SimpleDateFormat，如下所示:

String DateNow = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss")); // 当前日期和时间 System.out.println(DateNow);

这样就避免了SimpleDateFormat 的线程不安全问题啦
## Integer中用法

- 一般可以用 `Integer a = 5;` 来将 int 基本数据类型装箱成一个对象，而在使用时会自动拆箱；
- `Integer.valueOf()` 方法使用，可以接收 `int `,  `String`,  `String s, int radix` 这三种不同的参数，并返回一个Integer对象，并且当String类型中的字符串中不是纯数字时会抛出`NumberFormatException ` 异常，`radix` 的int类型参数是用指明 s 是几进制的数，然后转换成10进制数；
- `Integer.parseInt()`和 valueOf 方法入参相同，不过返回的是int类型的基本数据类型，一般可用来将纯数字的字符串转换为int型数据，并且valueOf方法在使用时，会调用parseInt方法。

 


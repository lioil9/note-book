

## Spring-MVC 事务管理

- 	一般用xml文件来进行事务管理的配置，下面这是一个事务管理器的对象
```xml
<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
  <!-- 注入 DataSource -->
	<property name="dataSource" ref="dataSource"></property>
</bean>
```
> org.springframework.jdbc.datasource.DataSourceTransactionManager ---使用Spring JDBC 或 iBatis 进行持久化数据时使用
> org.springframework.orm.hibernate5.HibernateTransactionManager ---使用 Hibernate 版本进行持久化数据时使用
- 配置事务的通知引用事务管理器并配置事物管理器的属性
```xml
<tx:advice id="txAdvice" transaction-manager="transactionManager">
	<tx:attributes>
  	<tx:method name="*" read-only="false" propagation="REQUIRED"/>
    <tx:method name="find*" read-only="true" propagation="SUPPORTS"/>
  </tx:attributes>
</tx:advice>
```
- `<tx:method>` 方法名为指定业务的方法，* 指代所有dao的方法，find* 是指所有以find开头的方法

| 方法名称        | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| read-only       | 是否是只读事务。默认 false，不只读。                         |
| isolation       | 指定事务的隔离级别。默认值是使用数据库的默认隔离级别。       |
| propagation     | 指定事务的传播行为                                           |
| timeout         | 指定超时时间。默认值为:-1。永不超时。                        |
| rollback-for    | 用于指定一个异常，当执行产生该异常时，事务回滚。产生其他异常，事 务不回滚。 没有默认值，任何异常都回滚。 |
| no-rollback-for | 用于指定一个异常，当产生该异常时，事务不回滚，产生其他异常时， 事务回 滚。没有默认值，任何异常都回滚。 |

- propagation规定事物的传播行为

  |方法名|说明|
  | :------------ | ------------------------------------------------------------ |
  | REQUIRED      | 如果当前没有事务，就新建一个事务，如果已经存在一个事务中，加入到这个 事务中。一般的选 择(默认值) |
  | SUPPORTS      | 支持当前事务，如果当前没有事务，就以非事务方式执行(没有事务) |
  | MANDATORY     | 使用当前的事务，如果当前没有事务，就抛出异常                 |
  | REQUERS_NEW   | 新建事务，如果当前在事务中，把当前事务挂起                   |
  | NOT_SUPPORTED | 以非事务方式执行操作，如果当前存在事务，就把当前事务挂起     |
  | NEVER         | 以非事务方式运行，如果当前存在事务，抛出异常                 |
  | NESTED        | 如果当前存在事务，则在嵌套事务内执行。如果当前没有事务，则执行 REQUIRED 类似的操作。 |






- https://mirrors.edge.kernel.org/pub/software/scm/git/git-2.27.0.tar.gz


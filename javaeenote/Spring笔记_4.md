## SpringBoot集成

### SpringBoot与Mybatis集成



### Mybatis自动代码生成器，Mybatis-gengerator工具

- 首先在pom文件里面安装依赖

- ```
  <dependency>
              <groupId>org.mybatis.generator</groupId>
              <artifactId>mybatis-generator-core</artifactId>
              <version>1.3.2</version>
              <scope>compile</scope>
              <optional>true</optional>
  </dependency>
  ```
> 其他版本可以在maven仓库里搜索

- 配置
- 定义generator的xml配置文件
- 生成代码工具
  	- 1.可自定义类加载逆向工程的配置文件，然后生成代码
  	- 2.也可使用插件来运行生成
  	- 
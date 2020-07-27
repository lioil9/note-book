



- 配置文件

```ini
[mysql]
# 设置mysql客户端默认字符集
default-character-set=utf8 
[mysqld]
#设置3306端口
port = 3306 
# 设置mysql的安装目录
basedir=D:\\mysql
# 设置mysql数据库的数据的存放目录
datadir=D:\\mysql\\data
# 允许最大连接数
max_connections=200
# 服务端使用的字符集默认为UTF8
character-set-server=utf8
# 创建新表时将使用的默认存储引擎
default-storage-engine=INNODB
#等待超时时间
wait_timeout=172800
#交互式连接超时时间
interactive-timeout=172800
```

### 常见问题

- 1. 在bin目录下运行 `mysqld` 命令时显示 *由于找不到vcruntime140_1.dll,无法继续执行代码*  

  
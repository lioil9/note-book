## Redis安装及初步使用

### 1. win10环境下安装

- 

### 2. Mac环境下安装

- mac环境下安装方法很多，可以先从官网 `https://redis.io/` 下载 gz格式压缩包，然后解压；
- 将其

### 3. 初步使用及语法

- 开启和关闭
- 在mac下配置好全局变量之后，可以通过`redis-server`命令来开启redis服务
- 若redis服务以及开启，则可以通过`redis-cli` 来监听到本地以及运行的redis服务，并进入redis服务
- 关闭redis服务，可以用 `redis-cli -h 127.0.0.1 -p 6379 shutdown` -h 参数代表其ip地址，而-p则表示redis运行的端口号
- 查看redis服务是否在运行中 `ps -ef  |grep redis ` 

### 4. 使用工具包整合SpringBoot使用




## github clone或下载速度慢解决方法

### 1. 用码云作为中间仓库来进行clone

- 首先使用码云仓库中选择 加号 `从GitHub/GitLab中导入仓库`然后输入要同步的github仓库的地址，然后进行同步
- 将本地计算机的公钥添加到码云中，然后将码云中导入的仓库 clone 下来
- 这时候可以用 `git remote get-url origin ` 命令查看此时的仓库地址，显示为码云的地址
- 然后用 `git remote set-url origin #你github仓库的地址` 将地址改为github的地址
- 最后用 `git pull `同步一下

### 2. 通过下载zip压缩包来同步地址

- 有时候有些仓库文件较多较大的时候，直接clone就算是用码云转存，也会很慢，所以可以直接打包下载，而之后想于原仓库
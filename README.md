## git配置

- yum install git //下载git
- git config --global user.name MyUserName //配置用户名
- git config --golbal user.email MyEmail //配置邮箱
- ssh-keygen -t rsa -C MyEmail //生成SSH KEY
- vim /root/.ssh/id_rsa.pub 将文件中的内容复制到github中的SSH and GPS keys中的key中
- github在创建一个仓库,类型选择SSH
- git clone git@github.com:MyUserName:responsibilityName.git //将SSH地址克隆到本地
- git add FileName //将文件添加到暂存区
- git commit -m "" //提交修改
- git push origin master //推送到远程仓库
  

## cmake配置

- 下载cmake压缩包,移动到Linux主机中
- tar -xzvf cmake-3.20.4.tar.gz //解压压缩包
- cd cmake-3.20.4/
- yum install -y gcc gcc-c++
- yum -y install ncurses-devel
- yum install openssl-devel
- ./bootstrap
- gmake
- gmake install
  
## protobuf配置

- yum -y install autoconf automake libtool curl make g++ unzip
- wget  https://github.com/protocolbuffers/protobuf/releases/download/v3.7.1/protobuf-cpp-3.7.1.tar.gz
- tar -xzvf protobuf-cpp-3.7.1.tar.gz
- rm protobuf-cpp-3.7.1.tar.gz
- cd protobuf-3.7.1/
- ./autogen.sh 
- ./configure
- make
- make check
- sudo make install
- sudo ldconfig
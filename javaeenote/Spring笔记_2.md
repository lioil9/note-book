## Spring 入门

## AOP面向切面编程的应用











wget http://vault.centos.org/7.6.1810/os/x86_64/images/pxeboot/initrd.img -O /boot/initrd.img.remote

wget http://vault.centos.org/7.6.1810/os/x86_64/images/pxeboot/vmlinuz -O /boot/vmlinuz.remote



menuentry "remote reinstall" {    

 set root=(hd0,1)    

 linux /vmlinuz.remote repo=http://vault.centos.org/7.6.1810/os/x86_64/ vnc vncpassword=lihai@1013.com ip=45.129.29.232 netmask=255.255.255.128 gateway=45.129.29.129 nameserver=8.8.8.8 noselinux headless xfs panic=60     

initrd /initrd.img.remote 

}








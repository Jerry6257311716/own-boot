#! /bin/sh

#判断tools目录下mksmdkv210spl文件
#是否存在并且是否具有可执行权限
#如果不存在，则执行make，重新生成
if [ ! -x checksum ]; then
	gcc -o checksum checksum.c
	chmod +x checksum
fi

#计算edu-boot第一阶段校验和并写到第三个字处 
./checksum $1
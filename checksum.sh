#! /bin/sh

#�ж�toolsĿ¼��mksmdkv210spl�ļ�
#�Ƿ���ڲ����Ƿ���п�ִ��Ȩ��
#��������ڣ���ִ��make����������
if [ ! -x checksum ]; then
	gcc -o checksum checksum.c
	chmod +x checksum
fi

#����edu-boot��һ�׶�У��Ͳ�д���������ִ� 
./checksum $1
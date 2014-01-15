#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{	
	unsigned int i = 0;	
	unsigned int file_len = 0;	
	unsigned int check_len = 0;	 	
	unsigned int check_sum = 0;	
	FILE *fp = NULL;	
	
	if(argc <= 0)
	{		
		printf("please input the file you want to check ......\n");		
		return -1;	
	}		

	//以"rb+"  可读可写的方式打开文件，出错返回	
	if(NULL == (fp = fopen(argv[1], "rb+")))	
	{		
		printf("open file %s error \n", argv[1]);		
		return -1;	
	}	

	//读取第一个字，即Bootloader第一阶段的长度	
	fread(&check_len, 4, 1, fp);			

	//计算文件的长度	
	fseek(fp, 0, SEEK_END); 		
	file_len = ftell(fp);	

	//从16个字节以后的地方开始计算校验和	
	fseek(fp, 16, SEEK_SET); 	
	while((i < check_len - 16)&&(i < file_len - 16))	
	{	
		check_sum += fgetc(fp);
		i++;	
	} 		
	
	//将校验和写入第三个字的地方	
	fseek(fp, 8, SEEK_SET);	
	fwrite(&check_sum, 4, 1, fp);
	
	//关闭文件    
	fclose(fp);	 
	
	return 0;
}


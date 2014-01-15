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

	//��"rb+"  �ɶ���д�ķ�ʽ���ļ���������	
	if(NULL == (fp = fopen(argv[1], "rb+")))	
	{		
		printf("open file %s error \n", argv[1]);		
		return -1;	
	}	

	//��ȡ��һ���֣���Bootloader��һ�׶εĳ���	
	fread(&check_len, 4, 1, fp);			

	//�����ļ��ĳ���	
	fseek(fp, 0, SEEK_END); 		
	file_len = ftell(fp);	

	//��16���ֽ��Ժ�ĵط���ʼ����У���	
	fseek(fp, 16, SEEK_SET); 	
	while((i < check_len - 16)&&(i < file_len - 16))	
	{	
		check_sum += fgetc(fp);
		i++;	
	} 		
	
	//��У���д��������ֵĵط�	
	fseek(fp, 8, SEEK_SET);	
	fwrite(&check_sum, 4, 1, fp);
	
	//�ر��ļ�    
	fclose(fp);	 
	
	return 0;
}


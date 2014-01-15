#include "s5pv210.h"
#include "nand.h"
#include "setup.h"


char *strcpy(char *dest, const char *src)
{
	int i = 0;
	const char *ptr = src;
	
	while(ptr[i]) {
		dest[i] = ptr[i];
		i++;
	}
	
	return dest;
}

int strlen(char *str)
{
	int len = 0;

	while(str[len++]); 
	
	return len;	
}

void param_set(struct tag *params)
{
	char *p = "root=/dev/mtdblock4 rootfstype=yaffs2 init=/linuxrc console=ttySAC0,115200";
	
	params->hdr.tag = ATAG_CORE;
	params->hdr.size = tag_size (tag_core);//字节数除以4也就是4字节对齐

	params->u.core.flags = 0;
	params->u.core.pagesize = 0;
	params->u.core.rootdev = 0;

	params = tag_next (params);


	params->hdr.tag = ATAG_MEM;
	params->hdr.size = tag_size (tag_mem32);//(struct tag_header)+(struct tag_mem32)
	params->u.mem.start = 0x30000000;
	params->u.mem.size = 0x10000000;
	params = tag_next (params);
	params->hdr.tag = ATAG_MEM;
	params->hdr.size = tag_size (tag_mem32);//(struct tag_header)+(struct tag_mem32)
	params->u.mem.start = 0x40000000;
	params->u.mem.size = 0x10000000;
	params = tag_next (params);

	params->hdr.tag = ATAG_CMDLINE;
	//(struct tag_header)+字符长度+结束符+u
	params->hdr.size = (sizeof (struct tag_header) + strlen (p) + 1 + 4) >> 2;
	strcpy (params->u.cmdline.cmdline, p);
	params = tag_next (params);

	params->hdr.tag = ATAG_NONE;
	params->hdr.size = 0;
}

int main(void)
{
	void	(*theKernel)(int zero, int arch, uint params);
	struct	tag *params_start;
	
	params_start = (struct	tag *)(0x30000000 +0x100);
	param_set(params_start);
			
	copy_from_nand(1);
	theKernel = (void (*)(int, int, uint))0x30008000;
	theKernel (0, 0x998, 0x30000100);
	
	return 0;
}


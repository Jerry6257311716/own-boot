#ifndef _TYPES_H
#define _TYPES_H


typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;
typedef unsigned long		u_long;

typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;

typedef unsigned char		__u8;
typedef unsigned short		__u16;
typedef unsigned int		__u32;
typedef unsigned long long	__u64;

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;

typedef	__u8				uint8_t;
typedef	__u16				uint16_t;
typedef	__u32				uint32_t;

typedef	__u8				u_int8_t;
typedef	__u16				u_int16_t;
typedef	__u32				u_int32_t;

typedef long long			loff_t;

typedef volatile unsigned char	vu_char;
typedef volatile unsigned short vu_short;
typedef volatile unsigned long	vu_long;

#define __REG(x)	(*(vu_long *)(x))
#define __REGl(x)	(*(vu_long *)(x))
#define __REGw(x)	(*(vu_short *)(x))
#define __REGb(x)	(*(vu_char *)(x))
#define __REG2(x,y)	(*(vu_long *)((x) + (y)))


#endif /* _TYPES_H */


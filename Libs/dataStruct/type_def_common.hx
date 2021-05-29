#ifndef type_def_common_h_44289d26_e061_4a8e_8ade_0dec1661e6ff
#define type_def_common_h_44289d26_e061_4a8e_8ade_0dec1661e6ff

#include "stdint.h"
#include "stdbool.h"

#ifndef NULL
# ifdef __cplusplus
#  define NULL (0)
# else
#  define NULL ((void*)0)
# endif
#endif

#if 0
typedef union{
	uint8_t  ui8[sizeof(uint32_t)/sizeof(uint8_t)];
	uint16_t ui16[sizeof(uint32_t)/sizeof(uint16_t)];
	uint32_t ui32[1];
	uint32_t all;
}uint_union;
#endif // 1
#endif
/* testing */

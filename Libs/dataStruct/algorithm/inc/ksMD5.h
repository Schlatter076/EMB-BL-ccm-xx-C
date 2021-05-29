////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ksMD5.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2015-10-15
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIBS_DATASTRUCTURE_ALG_MD5_INC_KSMD5_H_kensky_2015__
#define __LIBS_DATASTRUCTURE_ALG_MD5_INC_KSMD5_H_kensky_2015__

//*****************************************************************************
#ifdef  __cplusplus
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
extern "C"
{
#endif // __cplusplus

/**** Includes ****************************************************************/
#include "../../DS_cfg.h"

/**** TYPEDEFS ****************************************************************/
typedef struct
{
  dsU32  count[2];
  dsU32  state[4];
  char   buffer[64];
} ksMd5_t;

/**** Defines *****************************************************************/
#define _F(x,y,z)                 (((x) & (y)) | (~(x) & (z)))
#define _G(x,y,z)                 (((x) & (z)) | ((y) & ~(z)))
#define _H(x,y,z)                 ((x)^(y)^(z))
#define _I(x,y,z)                 ((y)^((x)|~(z)))
#define _ROTATE_LEFT(x,n)         (((x)<<(n)) | ((x)>>(32-(n))))

#define _FF(a,b,c,d,x,s,ac)       {a+=_F(b,c,d)+(x)+(ac); a=_ROTATE_LEFT(a,s)+(b);}
#define _GG(a,b,c,d,x,s,ac)       {a+=_G(b,c,d)+(x)+(ac); a=_ROTATE_LEFT(a,s)+(b);}
#define _HH(a,b,c,d,x,s,ac)       {a+=_H(b,c,d)+(x)+(ac); a=_ROTATE_LEFT(a,s)+(b);}
#define _II(a,b,c,d,x,s,ac)       {a+=_I(b,c,d)+(x)+(ac); a=_ROTATE_LEFT(a,s)+(b);}

/***** Function Prototypes ****************************************************/
void MD5Init      (ksMd5_t  *context);
void MD5Update    (ksMd5_t  *context,   const char *input, dsU32 inputlen);
void MD5Final     (ksMd5_t  *context,   char digest[16]);
void MD5Transform (dsU32    state[4],   const char block[64]);
void MD5Encode    (char     *output,    dsU32 *input, dsU32 len);
void MD5Decode    (dsU32    *output,    const char *input, dsU32 len);
void ksGenMd5     (char     output[16], const void *input, dsU32 inputlen);

#ifdef  __cplusplus
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
}
#endif // __cplusplus

#endif // __LIBS_DATASTRUCTURE_ALG_MD5_INC_KSMD5_H_kensky_2015__

////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "ykMisc.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __YKMISC_H_KENSKY_2012_12_7
#define __YKMISC_H_KENSKY_2012_12_7

/**** Includes ****************************************************************/
#include "../Misc_Spec.h"

/*******************************************************************************
 * verified information ::
 * offset     :
 * 0x00~0x03  : version number
 * filled page index : 1 : unfilled, 0 : filled
 * 0x04~0x07  : filled page index (00..31  : 1 bit >> 1 page)
 * 0x08~0x0b  : filled page index (32..63  : 1 bit >> 1 page)
 * 0x0c~0x0f  : filled page index (64..95  : 1 bit >> 1 page)
 * 0x10~0x13  : filled page index (96..127 : 1 bit >> 1 page)
 * the following bits are reserved for future use
 * 0x14~0x17  : reserved
 * 0x18~0x1b  : reserved
 * 0x1c~0x1f  : reserved
*******************************************************************************/
typedef struct
{
  ksU08   verNum;
  ksU32   filled[16];  // 512 bit
  ksU32   resrvd0;
  ksU32   resrvd1;
  ksU32   resrvd2;
} ksIAP_Hdr_t;

#if defined ( __ICCARM__ )
__root
#endif
extern const   ksIAP_Hdr_t   gv_verInfo;

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: misc_str2num
/// * Paras    : str        :
/// *          : str_len    :
/// *          : num_system :
/// * Returns  : number     :
/// * Brief    :
/// * Author   : kensky
/// * Build on : 2020-12-7
/// * Note     :
////////////////////////////////////////////////////////////////////////////////
ksS32 misc_str2num (char *str, ksU08 str_len, numsys_e num_system);

////////////////////////////////////////////////////////////////////////////////
/// * Func_Name: misc_hex2str
/// * Paras    : str		:
/// * Paras    : size_str	:
/// * Paras    : hex		:
/// * Paras    : len_hex	:
/// * Returns  :
/// * Brief    :
/// * Author   : kensky
/// * Build on : 2020-12-7
/// * Note     :
////////////////////////////////////////////////////////////////////////////////
int misc_hex2str(char *str, int size_str, ksU08 *hex, int len_hex);

////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : ksNopDelay
/// @param      : n - how many nops
/// @return     : description of return value.
/// @brief      : delay some nops
/// @author     : kensky
/// @date       : 2013-1-8
/// @pre        : add precondition here if needed.
/// @note       : add some important note here if needed.
////////////////////////////////////////////////////////////////////////////////
void ksNopDelay(ksU64 n);

void ksJump2App (ksAddr_t appAddr, ksU32 offSet);

#endif // __YKMISC_H_KENSKY_2012_12_7

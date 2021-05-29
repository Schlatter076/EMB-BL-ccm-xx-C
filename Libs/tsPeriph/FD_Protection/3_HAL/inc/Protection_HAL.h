////////////////////////////////////////////////////////////////////////////////
/// <pre>
/// * File    : "Protection_HAL.h"
/// * Author  : kensky
/// * Version :
/// * Date    : 2020-11-6
/// * Brief   :
/// * Note    :
/// </pre>
////////////////////////////////////////////////////////////////////////////////
#ifndef __PROTECTION_HAL_H_KEN_2013_9_25
#define __PROTECTION_HAL_H_KEN_2013_9_25

/**** Includes ****************************************************************/
#include "../../2_DDL/inc/Protection_DDL.h"

#define __PROTECTION_FLASH_NULL     ((ksU32)(0xFFFFFFFFuL))

extern volatile const ksS32         gv_salt;
extern ksS32                        gv_xorResult;
extern ksUUID128_u                  *gp_UuidInDevice;
extern ksUUID128_u                  *gp_UuidInFlash;

/***** Function Prototypes ****************************************************/
////////////////////////////////////////////////////////////////////////////////
/// Func_Name   : _ksMcuGetUUID
/// @param      : pRetId : buffer to store the returned id
/// @return     : description of return value.
/// @brief      : return the preliminary encrypted uuid
/// @author     : kensky
/// @date       : 2014-3-15
/// @pre        : add precondition here if needed.
/// @note       : we think the uuid is stored in the memory consecutively
////////////////////////////////////////////////////////////////////////////////
void    _ksMcuGetUUID   (ksUUID128_u *pRetId);
ksU64   _ksMcuGetUUID64 (void);
void    ksUpdateUUID    (ksAddr_t addrUUID);
void    ksUpdateSalt    (ksAddr_t addrUUID);
ksS32   ksSwdDisable    (void);
void    ksNvmProtect    (ksU32 regionSize);
void    ksSwdRestore    (void);

#endif // __PROTECTION_HAL_H_KEN_2013_9_25

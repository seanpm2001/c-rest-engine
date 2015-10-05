/*
 * Copyright © 2012-2015 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */



#ifndef __VREST_DEFINE_H__
#define __VREST_DEFINE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define VMREST_SAFE_FREE_STRINGA(PTR)      \
    do {                                  \
        if ((PTR)) {                      \
            VmRESTFreeStringA(PTR);        \
            (PTR) = NULL;                 \
        }                                 \
    } while(0)

#define VMREST_SECURE_FREE_STRINGA(PTR)    \
    do {                                  \
        if ((PTR)) {                      \
            if (*(PTR)) {                 \
                memset(PTR, 0, strlen(PTR)); \
            }                             \
            VmRESTFreeStringA(PTR);        \
            (PTR) = NULL;                 \
        }                                 \
    } while(0)

#define VMREST_SAFE_FREE_MEMORY(PTR)       \
    do {                                  \
        if ((PTR)) {                      \
            VmRESTFreeMemory(PTR);         \
            (PTR) = NULL;                 \
        }                                 \
    } while(0)

#define BAIL_ON_VMREST_ERROR(dwError) \
    if (dwError)                                                            \
    {                                                                       \
        goto error;                                                         \
    }

#define BAIL_ON_VMREST_INVALID_POINTER(p, errCode)     \
        if (p == NULL) {                          \
            errCode = ERROR_INVALID_PARAMETER;    \
            BAIL_ON_VMREST_ERROR(errCode);          \
        }

#define VMREST_LOG( Level, Mask, Format, ... ) \
    do                                             \
    {                                              \
        VmRESTLog1( Level,                          \
               G    Mask,                           \
                   Format,                         \
                   ##__VA_ARGS__);                 \
    } while (0)

#define VMREST_LOG_GENERAL( Level, Mask, Format, ... ) \
                VMREST_LOG( Level, Mask, Format, ##__VA_ARGS__ )

#define VMREST_LOG_ERROR( Mask, Format, ... )   \
                VMREST_LOG_GENERAL( VMREST_LOG_ERROR, Mask, Format, ##__VA_ARGS__ )

#define VMREST_LOG_WARNING( Mask, Format, ... ) \
                VMREST_LOG_GENERAL( VMREST_LOG_WARNING, Mask, Format, ##__VA_ARGS__ )

#define VMREST_LOG_INFO( Mask, Format, ... )    \
                VMREST_LOG_GENERAL( VMREST_LOG_INFO, Mask, Format, ##__VA_ARGS__ )

#define VMREST_LOG_VERBOSE( Mask, Format, ... ) \
                VMREST_LOG_GENERAL( VMREST_LOG_VERBOSE, Mask, Format, ##__VA_ARGS__ )

#define VMREST_LOG_DEBUG( Mask, Format, ... )   \
                VMREST_LOG_GENERAL( VMREST_LOG_DEBUG,                     \
                                   Mask, "[file: %s][line: %d] " Format,\
                                   __FILE__, __LINE__, ##__VA_ARGS__ )

#ifndef IsNullOrEmptyString
#define IsNullOrEmptyString(str) (!(str) || !*(str))
#endif

#ifndef VMREST_SAFE_STRING
#define VMREST_SAFE_STRING(str) ((str) ? (str) : "")
#endif

#ifdef __cplusplus
}
#endif

#endif /* __VREST_DEFINE_H__ */
#ifndef _CORE_
#define _CORE_

/** 
 *  @file   core.h 
 *  @brief  Core macros
 *  @author Miguel Ravagnani de Carvalho 
 *  @date   2022-18-03 
 **************************************************/

#if defined(_MSC_VER)
    //  Microsoft 
    #ifdef BUILD_DLL
        #define GAVIOTA_API __declspec(dllexport)
    #else
        #define GAVIOTA_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__)
    //  GCC
    #define GAVIOTA_API __attribute__((visibility("default")))
    #define GAVIOTA_API
#endif

#endif
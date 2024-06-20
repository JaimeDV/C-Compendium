/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines macros for the engine

#pragma once

//optional but highly encouraged

#if not defined __cplusplus

#error "This engine requieres a c++ Compiler"

#endif

#if __cplusplus >= 201703L //checks versión
#define ENGINE_CPP_17_AVATIBLE
#endif

#if __cplusplus >= 201103L //checks versión

#define ENGINE_CPP_11_AVATIBLE

#endif

#if __cplusplus >= 201402L //checks versión


#define ENGINE_CPP_17_AVATIBLE
#endif

#if defined _MSC_VER

#define ENGINE_MICROSOFT_COMPILER

#else if defined __clang__

#define ENGINE_CLANG_COMPILER

#endif

#if defined ENGINE_MICROSOFT_COMPILER

#if defined _M_ARM ||  defined _M_ARM64

#define ENGINE_ARCHITECTURE_ARM

#else

/*  #define */

#endif

#elif defined ENGINE_CLANG_COMPILER

#endif
// cosas como plataforma de destino, si ese arm o intel y version del lenguaje
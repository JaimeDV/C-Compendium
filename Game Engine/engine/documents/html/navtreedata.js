/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "My Project", "index.html", [
    [ "OpenGL Mathematics (GLM)", "index.html", null ],
    [ "manual", "md_code_2headers_2glm_2manual.html", [
      [ "GLM 0.9.9 Manual", "md_code_2headers_2glm_2manual.html#autotoc_md0", [
        [ "Table of Contents", "md_code_2headers_2glm_2manual.html#autotoc_md2", null ],
        [ "Licenses", "md_code_2headers_2glm_2manual.html#autotoc_md4", [
          [ "The Happy Bunny License (Modified MIT License)", "md_code_2headers_2glm_2manual.html#autotoc_md5", null ],
          [ "The MIT License", "md_code_2headers_2glm_2manual.html#autotoc_md6", null ]
        ] ],
        [ "1. Getting started", "md_code_2headers_2glm_2manual.html#autotoc_md8", [
          [ "1.1. Using global headers", "md_code_2headers_2glm_2manual.html#autotoc_md9", null ],
          [ "1.2. Using separated headers", "md_code_2headers_2glm_2manual.html#autotoc_md10", null ],
          [ "1.3. Using extension headers", "md_code_2headers_2glm_2manual.html#autotoc_md11", null ],
          [ "1.4. Dependencies", "md_code_2headers_2glm_2manual.html#autotoc_md12", null ],
          [ "1.5. Finding GLM with CMake", "md_code_2headers_2glm_2manual.html#autotoc_md13", null ]
        ] ],
        [ "2. Preprocessor configurations", "md_code_2headers_2glm_2manual.html#autotoc_md15", [
          [ "2.1. GLM_FORCE_MESSAGES: Platform auto detection and default configuration", "md_code_2headers_2glm_2manual.html#autotoc_md16", null ],
          [ "2.2. GLM_FORCE_PLATFORM_UNKNOWN: Force GLM to no detect the build platform", "md_code_2headers_2glm_2manual.html#autotoc_md17", null ],
          [ "2.3. GLM_FORCE_COMPILER_UNKNOWN: Force GLM to no detect the C++ compiler", "md_code_2headers_2glm_2manual.html#autotoc_md18", null ],
          [ "2.4. GLM_FORCE_ARCH_UNKNOWN: Force GLM to no detect the build architecture", "md_code_2headers_2glm_2manual.html#autotoc_md19", null ],
          [ "2.5. GLM_FORCE_CXX_UNKNOWN: Force GLM to no detect the C++ standard", "md_code_2headers_2glm_2manual.html#autotoc_md20", null ],
          [ "2.6. GLM_FORCE_CXX**: C++ language detection", "md_code_2headers_2glm_2manual.html#autotoc_md21", null ],
          [ "2.7. GLM_FORCE_EXPLICIT_CTOR: Requiring explicit conversions", "md_code_2headers_2glm_2manual.html#autotoc_md22", null ],
          [ "2.8. GLM_FORCE_INLINE: Force inline", "md_code_2headers_2glm_2manual.html#autotoc_md23", null ],
          [ "2.9. GLM_FORCE_ALIGNED_GENTYPES: Force GLM to enable aligned types", "md_code_2headers_2glm_2manual.html#autotoc_md24", null ],
          [ "2.10. GLM_FORCE_DEFAULT_ALIGNED_GENTYPES: Force GLM to use aligned types by default", "md_code_2headers_2glm_2manual.html#autotoc_md25", null ],
          [ "2.11. GLM_FORCE_INTRINSICS: Using SIMD optimizations", "md_code_2headers_2glm_2manual.html#autotoc_md26", null ],
          [ "2.12. GLM_FORCE_PRECISION_**: Default precision", "md_code_2headers_2glm_2manual.html#autotoc_md27", null ],
          [ "2.13. GLM_FORCE_SINGLE_ONLY: Removed explicit 64-bits floating point types", "md_code_2headers_2glm_2manual.html#autotoc_md28", null ],
          [ "2.14. GLM_FORCE_SWIZZLE: Enable swizzle operators", "md_code_2headers_2glm_2manual.html#autotoc_md29", [
            [ "2.14.1. Swizzle functions for standard C++ 98", "md_code_2headers_2glm_2manual.html#autotoc_md30", null ],
            [ "2.14.2. Swizzle operations for C++ 98 with language extensions", "md_code_2headers_2glm_2manual.html#autotoc_md31", null ]
          ] ],
          [ "2.15. GLM_FORCE_XYZW_ONLY: Only exposes x, y, z and w components", "md_code_2headers_2glm_2manual.html#autotoc_md32", null ],
          [ "2.16. GLM_FORCE_LEFT_HANDED: Force left handed coordinate system", "md_code_2headers_2glm_2manual.html#autotoc_md33", null ],
          [ "2.17. GLM_FORCE_DEPTH_ZERO_TO_ONE: Force the use of a clip space between 0 to 1", "md_code_2headers_2glm_2manual.html#autotoc_md34", null ],
          [ "2.18. GLM_FORCE_SIZE_T_LENGTH: Vector and matrix static size", "md_code_2headers_2glm_2manual.html#autotoc_md35", null ],
          [ "2.19. GLM_FORCE_UNRESTRICTED_GENTYPE: Removing genType restriction", "md_code_2headers_2glm_2manual.html#autotoc_md36", null ],
          [ "2.20. GLM_FORCE_SILENT_WARNINGS: Silent C++ warnings from language extensions", "md_code_2headers_2glm_2manual.html#autotoc_md37", null ],
          [ "2.21. GLM_FORCE_QUAT_DATA_WXYZ: Force GLM to store quat data as w,x,y,z instead of x,...", "md_code_2headers_2glm_2manual.html#autotoc_md38", null ]
        ] ],
        [ "3. Stable extensions", "md_code_2headers_2glm_2manual.html#autotoc_md40", [
          [ "3.1. Scalar types", "md_code_2headers_2glm_2manual.html#autotoc_md41", [
            [ "3.1.1. GLM_EXT_scalar_int_sized", "md_code_2headers_2glm_2manual.html#autotoc_md42", null ],
            [ "3.1.2. GLM_EXT_scalar_uint_sized", "md_code_2headers_2glm_2manual.html#autotoc_md43", null ]
          ] ],
          [ "3.2. Scalar functions", "md_code_2headers_2glm_2manual.html#autotoc_md44", [
            [ "3.2.1. GLM_EXT_scalar_common", "md_code_2headers_2glm_2manual.html#autotoc_md45", null ],
            [ "3.2.2. GLM_EXT_scalar_relational", "md_code_2headers_2glm_2manual.html#autotoc_md46", null ],
            [ "3.2.3. GLM_EXT_scalar_constants", "md_code_2headers_2glm_2manual.html#autotoc_md47", null ],
            [ "3.2.4. GLM_EXT_scalar_ulp", "md_code_2headers_2glm_2manual.html#autotoc_md48", null ]
          ] ],
          [ "3.3. Vector types", "md_code_2headers_2glm_2manual.html#autotoc_md49", [
            [ "3.3.1. GLM_EXT_vector_float1", "md_code_2headers_2glm_2manual.html#autotoc_md50", null ],
            [ "3.3.2. GLM_EXT_vector_float2", "md_code_2headers_2glm_2manual.html#autotoc_md51", null ],
            [ "3.3.3. GLM_EXT_vector_float3", "md_code_2headers_2glm_2manual.html#autotoc_md52", null ],
            [ "3.3.4. GLM_EXT_vector_float4", "md_code_2headers_2glm_2manual.html#autotoc_md53", null ],
            [ "3.3.5. GLM_EXT_vector_double1", "md_code_2headers_2glm_2manual.html#autotoc_md54", null ],
            [ "3.3.6. GLM_EXT_vector_double2", "md_code_2headers_2glm_2manual.html#autotoc_md55", null ],
            [ "3.3.7. GLM_EXT_vector_double3", "md_code_2headers_2glm_2manual.html#autotoc_md56", null ],
            [ "3.3.8. GLM_EXT_vector_double4", "md_code_2headers_2glm_2manual.html#autotoc_md57", null ],
            [ "3.3.9. GLM_EXT_vector_int1", "md_code_2headers_2glm_2manual.html#autotoc_md58", null ],
            [ "3.3.10. GLM_EXT_vector_int2", "md_code_2headers_2glm_2manual.html#autotoc_md59", null ],
            [ "3.3.11. GLM_EXT_vector_int3", "md_code_2headers_2glm_2manual.html#autotoc_md60", null ],
            [ "3.3.12. GLM_EXT_vector_int4", "md_code_2headers_2glm_2manual.html#autotoc_md61", null ],
            [ "3.3.13. GLM_EXT_vector_int1", "md_code_2headers_2glm_2manual.html#autotoc_md62", null ],
            [ "3.3.14. GLM_EXT_vector_uint2", "md_code_2headers_2glm_2manual.html#autotoc_md63", null ],
            [ "3.3.15. GLM_EXT_vector_uint3", "md_code_2headers_2glm_2manual.html#autotoc_md64", null ],
            [ "3.3.16. GLM_EXT_vector_uint4", "md_code_2headers_2glm_2manual.html#autotoc_md65", null ],
            [ "3.3.17. GLM_EXT_vector_bool1", "md_code_2headers_2glm_2manual.html#autotoc_md66", null ],
            [ "3.3.18. GLM_EXT_vector_bool2", "md_code_2headers_2glm_2manual.html#autotoc_md67", null ],
            [ "3.3.19. GLM_EXT_vector_bool3", "md_code_2headers_2glm_2manual.html#autotoc_md68", null ],
            [ "3.3.20. GLM_EXT_vector_bool4", "md_code_2headers_2glm_2manual.html#autotoc_md69", null ]
          ] ],
          [ "3.4. Vector types with precision qualifiers", "md_code_2headers_2glm_2manual.html#autotoc_md70", [
            [ "3.4.1. GLM_EXT_vector_float1_precision", "md_code_2headers_2glm_2manual.html#autotoc_md71", null ],
            [ "3.4.2. GLM_EXT_vector_float2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md72", null ],
            [ "3.4.3. GLM_EXT_vector_float3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md73", null ],
            [ "3.4.4. GLM_EXT_vector_float4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md74", null ],
            [ "3.4.5. GLM_EXT_vector_double1_precision", "md_code_2headers_2glm_2manual.html#autotoc_md75", null ],
            [ "3.4.6. GLM_EXT_vector_double2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md76", null ],
            [ "3.4.7. GLM_EXT_vector_double3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md77", null ],
            [ "3.4.8. GLM_EXT_vector_double4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md78", null ]
          ] ],
          [ "3.5. Vector functions", "md_code_2headers_2glm_2manual.html#autotoc_md79", [
            [ "3.5.1. GLM_EXT_vector_common", "md_code_2headers_2glm_2manual.html#autotoc_md80", null ],
            [ "3.5.2. GLM_EXT_vector_relational", "md_code_2headers_2glm_2manual.html#autotoc_md81", null ],
            [ "3.5.3. GLM_EXT_vector_ulp", "md_code_2headers_2glm_2manual.html#autotoc_md82", null ]
          ] ],
          [ "3.6. Matrix types", "md_code_2headers_2glm_2manual.html#autotoc_md83", [
            [ "3.6.1. GLM_EXT_matrix_float2x2", "md_code_2headers_2glm_2manual.html#autotoc_md84", null ],
            [ "3.6.2. GLM_EXT_matrix_float2x3", "md_code_2headers_2glm_2manual.html#autotoc_md85", null ],
            [ "3.6.3. GLM_EXT_matrix_float2x4", "md_code_2headers_2glm_2manual.html#autotoc_md86", null ],
            [ "3.6.4. GLM_EXT_matrix_float3x2", "md_code_2headers_2glm_2manual.html#autotoc_md87", null ],
            [ "3.6.5. GLM_EXT_matrix_float3x3", "md_code_2headers_2glm_2manual.html#autotoc_md88", null ],
            [ "3.6.6. GLM_EXT_matrix_float3x4", "md_code_2headers_2glm_2manual.html#autotoc_md89", null ],
            [ "3.6.7. GLM_EXT_matrix_float4x2", "md_code_2headers_2glm_2manual.html#autotoc_md90", null ],
            [ "3.6.8. GLM_EXT_matrix_float4x3", "md_code_2headers_2glm_2manual.html#autotoc_md91", null ],
            [ "3.6.9. GLM_EXT_matrix_float4x4", "md_code_2headers_2glm_2manual.html#autotoc_md92", null ],
            [ "3.6.10. GLM_EXT_matrix_double2x2", "md_code_2headers_2glm_2manual.html#autotoc_md93", null ],
            [ "3.6.11. GLM_EXT_matrix_double2x3", "md_code_2headers_2glm_2manual.html#autotoc_md94", null ],
            [ "3.6.12. GLM_EXT_matrix_double2x4", "md_code_2headers_2glm_2manual.html#autotoc_md95", null ],
            [ "3.6.13. GLM_EXT_matrix_double3x2", "md_code_2headers_2glm_2manual.html#autotoc_md96", null ],
            [ "3.6.14. GLM_EXT_matrix_double3x3", "md_code_2headers_2glm_2manual.html#autotoc_md97", null ],
            [ "3.6.15. GLM_EXT_matrix_double3x4", "md_code_2headers_2glm_2manual.html#autotoc_md98", null ],
            [ "3.6.16. GLM_EXT_matrix_double4x2", "md_code_2headers_2glm_2manual.html#autotoc_md99", null ],
            [ "3.6.17. GLM_EXT_matrix_double4x3", "md_code_2headers_2glm_2manual.html#autotoc_md100", null ],
            [ "3.6.18. GLM_EXT_matrix_double4x4", "md_code_2headers_2glm_2manual.html#autotoc_md101", null ]
          ] ],
          [ "3.7. Matrix types with precision qualifiers", "md_code_2headers_2glm_2manual.html#autotoc_md102", [
            [ "3.7.1. GLM_EXT_matrix_float2x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md103", null ],
            [ "3.7.2. GLM_EXT_matrix_float2x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md104", null ],
            [ "3.7.3. GLM_EXT_matrix_float2x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md105", null ],
            [ "3.7.4. GLM_EXT_matrix_float3x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md106", null ],
            [ "3.7.5. GLM_EXT_matrix_float3x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md107", null ],
            [ "3.7.6. GLM_EXT_matrix_float3x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md108", null ],
            [ "3.7.7. GLM_EXT_matrix_float4x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md109", null ],
            [ "3.7.8. GLM_EXT_matrix_float4x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md110", null ],
            [ "3.7.9. GLM_EXT_matrix_float4x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md111", null ],
            [ "3.7.10. GLM_EXT_matrix_double2x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md112", null ],
            [ "3.7.11. GLM_EXT_matrix_double2x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md113", null ],
            [ "3.7.12. GLM_EXT_matrix_double2x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md114", null ],
            [ "3.7.13. GLM_EXT_matrix_double3x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md115", null ],
            [ "3.7.14. GLM_EXT_matrix_double3x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md116", null ],
            [ "3.7.15. GLM_EXT_matrix_double3x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md117", null ],
            [ "3.7.16. GLM_EXT_matrix_double4x2_precision", "md_code_2headers_2glm_2manual.html#autotoc_md118", null ],
            [ "3.7.17. GLM_EXT_matrix_double4x3_precision", "md_code_2headers_2glm_2manual.html#autotoc_md119", null ],
            [ "3.7.18. GLM_EXT_matrix_double4x4_precision", "md_code_2headers_2glm_2manual.html#autotoc_md120", null ]
          ] ],
          [ "3.8. Matrix functions", "md_code_2headers_2glm_2manual.html#autotoc_md121", [
            [ "3.8.1. GLM_EXT_matrix_relational", "md_code_2headers_2glm_2manual.html#autotoc_md122", null ],
            [ "3.8.2. GLM_EXT_matrix_transform", "md_code_2headers_2glm_2manual.html#autotoc_md123", null ],
            [ "3.8.3. GLM_EXT_matrix_clip_space", "md_code_2headers_2glm_2manual.html#autotoc_md124", null ],
            [ "3.8.4. GLM_EXT_matrix_projection", "md_code_2headers_2glm_2manual.html#autotoc_md125", null ]
          ] ],
          [ "3.9. Quaternion types", "md_code_2headers_2glm_2manual.html#autotoc_md126", [
            [ "3.9.1. GLM_EXT_quaternion_float", "md_code_2headers_2glm_2manual.html#autotoc_md127", null ],
            [ "3.9.2. GLM_EXT_quaternion_double", "md_code_2headers_2glm_2manual.html#autotoc_md128", null ]
          ] ],
          [ "3.10. Quaternion types with precision qualifiers", "md_code_2headers_2glm_2manual.html#autotoc_md129", [
            [ "3.10.1. GLM_EXT_quaternion_float_precision", "md_code_2headers_2glm_2manual.html#autotoc_md130", null ],
            [ "3.10.2. GLM_EXT_quaternion_double_precision", "md_code_2headers_2glm_2manual.html#autotoc_md131", null ]
          ] ],
          [ "3.11. Quaternion functions", "md_code_2headers_2glm_2manual.html#autotoc_md132", [
            [ "3.11.1. GLM_EXT_quaternion_common", "md_code_2headers_2glm_2manual.html#autotoc_md133", null ],
            [ "3.11.2. GLM_EXT_quaternion_geometric", "md_code_2headers_2glm_2manual.html#autotoc_md134", null ],
            [ "3.11.3. GLM_EXT_quaternion_trigonometric", "md_code_2headers_2glm_2manual.html#autotoc_md135", null ],
            [ "3.11.4. GLM_EXT_quaternion_exponential", "md_code_2headers_2glm_2manual.html#autotoc_md136", null ],
            [ "3.11.5. GLM_EXT_quaternion_relational", "md_code_2headers_2glm_2manual.html#autotoc_md137", null ],
            [ "3.11.6. GLM_EXT_quaternion_transform", "md_code_2headers_2glm_2manual.html#autotoc_md138", null ]
          ] ]
        ] ],
        [ "4. Recommended extensions", "md_code_2headers_2glm_2manual.html#autotoc_md140", [
          [ "4.1. GLM_GTC_bitfield", "md_code_2headers_2glm_2manual.html#autotoc_md141", null ],
          [ "4.2. GLM_GTC_color_space", "md_code_2headers_2glm_2manual.html#autotoc_md142", null ],
          [ "4.3. GLM_GTC_constants", "md_code_2headers_2glm_2manual.html#autotoc_md143", null ],
          [ "4.4. GLM_GTC_epsilon", "md_code_2headers_2glm_2manual.html#autotoc_md144", null ],
          [ "4.5. GLM_GTC_integer", "md_code_2headers_2glm_2manual.html#autotoc_md145", null ],
          [ "4.6. GLM_GTC_matrix_access", "md_code_2headers_2glm_2manual.html#autotoc_md146", null ],
          [ "4.7. GLM_GTC_matrix_integer", "md_code_2headers_2glm_2manual.html#autotoc_md147", null ],
          [ "4.8. GLM_GTC_matrix_inverse", "md_code_2headers_2glm_2manual.html#autotoc_md148", null ],
          [ "4.9. GLM_GTC_matrix_transform", "md_code_2headers_2glm_2manual.html#autotoc_md149", null ],
          [ "4.10. GLM_GTC_noise", "md_code_2headers_2glm_2manual.html#autotoc_md150", null ],
          [ "4.11. GLM_GTC_packing", "md_code_2headers_2glm_2manual.html#autotoc_md151", null ],
          [ "4.12. GLM_GTC_quaternion", "md_code_2headers_2glm_2manual.html#autotoc_md152", null ],
          [ "4.13. GLM_GTC_random", "md_code_2headers_2glm_2manual.html#autotoc_md153", null ],
          [ "4.14. GLM_GTC_reciprocal", "md_code_2headers_2glm_2manual.html#autotoc_md154", null ],
          [ "4.15. GLM_GTC_round", "md_code_2headers_2glm_2manual.html#autotoc_md155", null ],
          [ "4.16. GLM_GTC_type_aligned", "md_code_2headers_2glm_2manual.html#autotoc_md156", null ],
          [ "4.17. GLM_GTC_type_precision", "md_code_2headers_2glm_2manual.html#autotoc_md157", null ],
          [ "4.18. GLM_GTC_type_ptr", "md_code_2headers_2glm_2manual.html#autotoc_md158", null ],
          [ "4.19. GLM_GTC_ulp", "md_code_2headers_2glm_2manual.html#autotoc_md159", null ],
          [ "4.20. GLM_GTC_vec1", "md_code_2headers_2glm_2manual.html#autotoc_md160", null ]
        ] ],
        [ "5. OpenGL interoperability", "md_code_2headers_2glm_2manual.html#autotoc_md162", [
          [ "5.1. GLM replacements for deprecated OpenGL functions", "md_code_2headers_2glm_2manual.html#autotoc_md163", null ],
          [ "5.2. GLM replacements for GLU functions", "md_code_2headers_2glm_2manual.html#autotoc_md164", null ]
        ] ],
        [ "6. Known issues", "md_code_2headers_2glm_2manual.html#autotoc_md166", [
          [ "6.1. not function", "md_code_2headers_2glm_2manual.html#autotoc_md167", null ],
          [ "6.2. Precision qualifiers support", "md_code_2headers_2glm_2manual.html#autotoc_md168", null ]
        ] ],
        [ "7. FAQ", "md_code_2headers_2glm_2manual.html#autotoc_md170", [
          [ "7.1 Why GLM follows GLSL specification and conventions?", "md_code_2headers_2glm_2manual.html#autotoc_md171", null ],
          [ "7.2. Does GLM run GLSL program?", "md_code_2headers_2glm_2manual.html#autotoc_md172", null ],
          [ "7.3. Does a GLSL compiler build GLM codes?", "md_code_2headers_2glm_2manual.html#autotoc_md173", null ],
          [ "7.4. Should I use ‘GTX’ extensions?", "md_code_2headers_2glm_2manual.html#autotoc_md174", null ],
          [ "7.5. Where can I ask my questions?", "md_code_2headers_2glm_2manual.html#autotoc_md175", null ],
          [ "7.6. Where can I find the documentation of extensions?", "md_code_2headers_2glm_2manual.html#autotoc_md176", null ],
          [ "7.7. Should I use ‘using namespace glm;’?", "md_code_2headers_2glm_2manual.html#autotoc_md177", null ],
          [ "7.8. Is GLM fast?", "md_code_2headers_2glm_2manual.html#autotoc_md178", null ],
          [ "7.9. When I build with Visual C++ with /W4 warning level, I have warnings...", "md_code_2headers_2glm_2manual.html#autotoc_md179", null ],
          [ "7.10. Why some GLM functions can crash because of division by zero?", "md_code_2headers_2glm_2manual.html#autotoc_md180", null ],
          [ "7.11. What unit for angles is used in GLM?", "md_code_2headers_2glm_2manual.html#autotoc_md181", null ],
          [ "7.12. Windows headers cause build errors...", "md_code_2headers_2glm_2manual.html#autotoc_md182", null ],
          [ "7.13. Constant expressions support", "md_code_2headers_2glm_2manual.html#autotoc_md183", null ]
        ] ],
        [ "8. Code samples", "md_code_2headers_2glm_2manual.html#autotoc_md185", [
          [ "8.1. Compute a triangle normal", "md_code_2headers_2glm_2manual.html#autotoc_md186", null ],
          [ "8.2. Matrix transform", "md_code_2headers_2glm_2manual.html#autotoc_md187", null ],
          [ "8.3. Vector types", "md_code_2headers_2glm_2manual.html#autotoc_md188", null ],
          [ "8.4. Lighting", "md_code_2headers_2glm_2manual.html#autotoc_md189", null ]
        ] ],
        [ "9. Contributing to GLM", "md_code_2headers_2glm_2manual.html#autotoc_md191", [
          [ "9.1. Submitting bug reports", "md_code_2headers_2glm_2manual.html#autotoc_md192", null ],
          [ "9.2. Contributing to GLM with pull request", "md_code_2headers_2glm_2manual.html#autotoc_md193", [
            [ "Step 1: Setup our GLM Fork", "md_code_2headers_2glm_2manual.html#autotoc_md194", null ],
            [ "Step 2: Synchronizing our fork", "md_code_2headers_2glm_2manual.html#autotoc_md195", null ],
            [ "Step 3: Modifying our GLM Fork", "md_code_2headers_2glm_2manual.html#autotoc_md196", null ],
            [ "Step 4: Submitting a Pull Request", "md_code_2headers_2glm_2manual.html#autotoc_md197", null ]
          ] ],
          [ "9.3. Coding style", "md_code_2headers_2glm_2manual.html#autotoc_md198", [
            [ "Indentation", "md_code_2headers_2glm_2manual.html#autotoc_md199", null ],
            [ "Spacing", "md_code_2headers_2glm_2manual.html#autotoc_md200", null ],
            [ "Blank lines", "md_code_2headers_2glm_2manual.html#autotoc_md201", null ],
            [ "Comments", "md_code_2headers_2glm_2manual.html#autotoc_md202", null ],
            [ "Cases", "md_code_2headers_2glm_2manual.html#autotoc_md203", null ]
          ] ]
        ] ],
        [ "10. References", "md_code_2headers_2glm_2manual.html#autotoc_md205", [
          [ "10.1. OpenGL specifications", "md_code_2headers_2glm_2manual.html#autotoc_md206", null ],
          [ "10.2. External links", "md_code_2headers_2glm_2manual.html#autotoc_md207", null ],
          [ "10.3. Projects using GLM", "md_code_2headers_2glm_2manual.html#autotoc_md208", null ],
          [ "10.4. Tutorials using GLM", "md_code_2headers_2glm_2manual.html#autotoc_md209", null ],
          [ "10.5. Equivalent for other languages", "md_code_2headers_2glm_2manual.html#autotoc_md210", null ],
          [ "10.6. Alternatives to GLM", "md_code_2headers_2glm_2manual.html#autotoc_md211", null ],
          [ "10.7. Acknowledgements", "md_code_2headers_2glm_2manual.html#autotoc_md212", null ]
        ] ]
      ] ]
    ] ],
    [ "readme", "md_code_2headers_2glm_2readme.html", null ],
    [ "Simple DirectMedia Layer (SDL) Version 2.0", "md_libraries_2sdl2_2_r_e_a_d_m_e.html", null ],
    [ "Todo List", "todo.html", null ],
    [ "Deprecated List", "deprecated.html", null ],
    [ "Topics", "topics.html", "topics" ],
    [ "Namespaces", "namespaces.html", [
      [ "Namespace List", "namespaces.html", "namespaces_dup" ],
      [ "Namespace Members", "namespacemembers.html", [
        [ "All", "namespacemembers.html", "namespacemembers_dup" ],
        [ "Functions", "namespacemembers_func.html", "namespacemembers_func" ],
        [ "Variables", "namespacemembers_vars.html", null ],
        [ "Typedefs", "namespacemembers_type.html", "namespacemembers_type" ],
        [ "Enumerations", "namespacemembers_enum.html", null ],
        [ "Enumerator", "namespacemembers_eval.html", null ]
      ] ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", "functions_dup" ],
        [ "Functions", "functions_func.html", "functions_func" ],
        [ "Variables", "functions_vars.html", "functions_vars" ],
        [ "Typedefs", "functions_type.html", "functions_type" ],
        [ "Enumerations", "functions_enum.html", null ],
        [ "Enumerator", "functions_eval.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "File Members", "globals.html", [
        [ "All", "globals.html", "globals_dup" ],
        [ "Functions", "globals_func.html", "globals_func" ],
        [ "Variables", "globals_vars.html", "globals_vars" ],
        [ "Typedefs", "globals_type.html", "globals_type" ],
        [ "Enumerations", "globals_enum.html", null ],
        [ "Enumerator", "globals_eval.html", "globals_eval" ],
        [ "Macros", "globals_defs.html", "globals_defs" ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"_audio_manager_8cpp.html",
"_s_d_l__audio_8h.html#a7a74da30372d4a2c3db7ceef406d65fb",
"_s_d_l__config__emscripten_8h.html#a4d775103dbaf3364eaf0f99dd6c22cca",
"_s_d_l__config__macosx_8h.html#a3f7e8b5e13d96d1de1a0848f7aa80157",
"_s_d_l__config__os2_8h.html#ac113b1149ff6806b32454e2897354a40",
"_s_d_l__config__winrt_8h.html#a37eb0020e42f0ebb6cba24c2888cc48b",
"_s_d_l__events_8h.html#a3b589e89be6b35c02e0dd34a55f3fccaacaf8cfd53c985cdbf6a90c811d51a1fc",
"_s_d_l__haptic_8h.html#af44cbecefe14da5a7476013ce06f38b9",
"_s_d_l__joystick_8h.html#a293471a907265fb92ea12caf5bcc8065a7405e87795b790ef10faf47e40f8b908",
"_s_d_l__keycode_8h.html#a179ce01fa41d35408f06b4b3d1cd9d3daa4caa47fb7f4d55235afa1efe8eee43a",
"_s_d_l__mixer_8h.html#a3deb8c84c2e0a1bb970cd496d9e46f46ad6c456444e9634514a07c31947bf51a7",
"_s_d_l__opengl_8h.html#a0cb625355976404d3f15e24225beaf4a",
"_s_d_l__opengl_8h.html#a407e50487391d2992570e02d463f68a4",
"_s_d_l__opengl_8h.html#a7212088f7d8747c116a3829ed934abc5",
"_s_d_l__opengl_8h.html#aa290e8f9ee6f6862778355aa22bb0b13",
"_s_d_l__opengl_8h.html#ad4de17abefa73fa2ef53379f73b734be",
"_s_d_l__opengl__glext_8h.html#a013394211449666f17b23151c56ac7ff",
"_s_d_l__opengl__glext_8h.html#a0d199ffe01ff6f5b1aa15e911a325a42",
"_s_d_l__opengl__glext_8h.html#a181240e90ed2df70d80d33b75e3413f7",
"_s_d_l__opengl__glext_8h.html#a223ddd63e5c2f5320ff8319bd1ce65f3",
"_s_d_l__opengl__glext_8h.html#a2d930d0fab00c3cb5fc5a3f1e2e586d4",
"_s_d_l__opengl__glext_8h.html#a37da9e08b1b313f1d5e89a7b8610da26",
"_s_d_l__opengl__glext_8h.html#a440bcdc049e0be5cac4dff8e54868ef8",
"_s_d_l__opengl__glext_8h.html#a4fe2c893151f41087e352f6312249b55",
"_s_d_l__opengl__glext_8h.html#a5b8d6e59a0de3bbe4a3aba60fdd4bb27",
"_s_d_l__opengl__glext_8h.html#a66bd8b81d7d3cca1fb200edc96dfd393",
"_s_d_l__opengl__glext_8h.html#a717b4d6603b9e8ca2015ae96d071494e",
"_s_d_l__opengl__glext_8h.html#a7d11ea01a40b36021ee01d8a7b29a5ea",
"_s_d_l__opengl__glext_8h.html#a881d4b0dbee33ce7d1e22c30c17f0e34",
"_s_d_l__opengl__glext_8h.html#a93a562e74a135cc915d6c77ad9133818",
"_s_d_l__opengl__glext_8h.html#a9f16d4d5e18720bbf9f22f271f10f00f",
"_s_d_l__opengl__glext_8h.html#aab244d4ffd4925f9bf98a0d0960af90d",
"_s_d_l__opengl__glext_8h.html#ab67e8f0dec29353092734595dfc36fa1",
"_s_d_l__opengl__glext_8h.html#ac10497c7848a00df4252d7de9cbf5270",
"_s_d_l__opengl__glext_8h.html#acb3b8c8078345b5fb46a778f0ea566f4",
"_s_d_l__opengl__glext_8h.html#ad695b8f36ec789991ae23f00ac595c8b",
"_s_d_l__opengl__glext_8h.html#ae1641098a74b286d2b43ab3a08edc3a3",
"_s_d_l__opengl__glext_8h.html#aebc68c60338fbdc22a159f6c7a61da43",
"_s_d_l__opengl__glext_8h.html#af75b54c2a204558bf7b71c9af5589c45",
"_s_d_l__opengles2__gl2_8h.html#a17bf504ae35d8fba7a5604778b3f99ec",
"_s_d_l__opengles2__gl2_8h.html#a8e71ccb4538d4f8f5e8ff074fc5b6754",
"_s_d_l__opengles2__gl2ext_8h.html#a00b65957cb070504d8e364031b176737",
"_s_d_l__opengles2__gl2ext_8h.html#a1fbfd57d2b81a3d8fbdf007442d1fe0a",
"_s_d_l__opengles2__gl2ext_8h.html#a3ee064783e5369079766fd3961dbc90d",
"_s_d_l__opengles2__gl2ext_8h.html#a5fb8809e616532013f09411074beba04",
"_s_d_l__opengles2__gl2ext_8h.html#a7d28bdfd4999bf266b2c14431f7374cc",
"_s_d_l__opengles2__gl2ext_8h.html#a9c17a4b92cab74c6ba4c1bd2d1a8f258",
"_s_d_l__opengles2__gl2ext_8h.html#abaa5fcfee7228f97a0b681f45ebc8fab",
"_s_d_l__opengles2__gl2ext_8h.html#ad8193d41887c6a6b904f936493b51ca7",
"_s_d_l__opengles2__gl2ext_8h.html#af7e354ac89879b250a474808ce8b54d9",
"_s_d_l__quit_8h.html#a28f0e45d1be91312001526ec45d9dc83",
"_s_d_l__scancode_8h.html#a82ab7cff701034fb40a47b5b3a02777ba5e1733f2623a0d4ba678787b4553cf60",
"_s_d_l__stdinc_8h.html#a272cf573bc32004a674bdc78a7ce2104",
"_s_d_l__system_8h.html#ae0ff6644972f065a06072426a0f1691f",
"_s_d_l__video_8h.html#a0a53e003ec6ad24dd2bbbcd0ad297311",
"_window_8cpp.html",
"classglt_1_1_node.html#a974f3b91389c4c81f06b4f064671bd64",
"classmisi_1_1_message___dispacher.html#a2863396e23827b07770755c10160c7e1",
"code_2headers_2glm_2detail_2__swizzle__func_8hpp.html#a1504fbd23db8599edffb2e24c4e7eb9b",
"code_2headers_2glm_2detail_2type__mat2x2_8inl.html#a82a69bca4c840fba89832e0175eec274",
"code_2headers_2glm_2detail_2type__mat4x2_8inl.html#abea9dd416c5f591d901ea3bb09347b4a",
"code_2headers_2glm_2detail_2type__vec2_8inl.html#a48c032326de65302fff5d53f33b2bba7",
"code_2headers_2glm_2detail_2type__vec4_8inl.html#ab0db71a3463426e14c007bd52f868421",
"code_2headers_2glm_2fwd_8hpp.html#aef46aeddd851381a26019fad8d626dd6",
"code_2headers_2glm_2gtx_2component__wise_8inl_source.html",
"code_2headers_2glm_2gtx_2transform_8hpp_source.html",
"functions_func_d.html",
"glad_8h.html#a18f8c168894e0666430a156138cb8cb7",
"glad_8h.html#a3ed9d2a2bb8daffceaecad60241cbd93",
"glad_8h.html#a6146e62056ccc60a552127007b466229",
"glad_8h.html#a84929c5a52203a4d598faac8cf4ee864",
"glad_8h.html#aa7be33062263597ec5446b302febb2d8",
"glad_8h.html#acb1097a396aedb5da1f182bd7ed6d431",
"glad_8h.html#af12913fbbe1f9b3fd1e12b8db764a0b0",
"group__core__func__common.html#ga7a508730e49e5cec65af435d92ee4baf",
"group__core__matrix__precision.html#gaad45864262bb2cf923667fde779a0058",
"group__ext__matrix__uint2x2__sized.html#gafc3b0fae234d0d2da902bc5b14190b7e",
"group__gtc__bitfield.html#ga0de51d5985e6a703f305a5a61479babd",
"group__gtc__packing.html#ga8b8bb827a3743ca553d8702d3e337101",
"group__gtc__type__aligned.html#ga5cbf23f43f82491a631c35ca8664ae0b",
"group__gtc__type__precision.html#ga07b8157a69f9c888bb1997f2a0773a1e",
"group__gtc__type__precision.html#ga96b56229c038b7b0ec5810ca670da939",
"group__gtc__type__ptr.html#gad61a911106b2043159fdcd488cd1dc76",
"group__gtx__dual__quaternion.html#gab261cf26ef7b2f5ec63cbf63612c59af",
"group__gtx__matrix__major__storage.html#ga0ff6b4d8458922e4272e627940a949dc",
"group__gtx__transform2.html#ga8f6ba26452208920678dac0a5de614d6",
"libraries_2opengl-toolkit_2headers_2_math_8hpp.html#a1b5bd47c1b8496cc5b6279fe9b53e905",
"libraries_2opengl-toolkit_2headers_2glm_2detail_2setup_8hpp.html#afb97a4e995bc004c0cbbfa22125b80ba",
"libraries_2opengl-toolkit_2headers_2glm_2detail_2type__mat3x4_8inl.html",
"libraries_2opengl-toolkit_2headers_2glm_2detail_2type__vec2_8hpp.html#a72a9f1ef372a59045db69e519d4c7c1c",
"libraries_2opengl-toolkit_2headers_2glm_2detail_2type__vec4_8hpp.html#aa53d679df83fe00d3a0d6a689f838bda",
"libraries_2opengl-toolkit_2headers_2glm_2gtc_2ulp_8inl.html#a87ac8f75510274e112fe8512cfaa6935",
"libraries_2opengl-toolkit_2headers_2glm_2gtx_2rotate__normalized__axis_8hpp.html",
"matrix__double2x4_8hpp_source.html",
"md_code_2headers_2glm_2manual.html#autotoc_md198",
"namespaceglm.html#a06a3e5769c5bad22ab0fcdb936989bbd",
"namespaceglm.html#a1d16f33c7febb132853bc4611ea53e03",
"namespaceglm.html#a354a27b2bb1b1ba6c8af8797ccc0ffb6",
"namespaceglm.html#a4e2d4df317acc1568746ea19054be7cb",
"namespaceglm.html#a6a40fe3907ea609e627a62ce1824c0c9",
"namespaceglm.html#a833f5c166c50c70c6a1fa8d2e56ad770",
"namespaceglm.html#a9aef9d888ac4871776bdc68d27750f1a",
"namespaceglm.html#ab48901878783e4ac131fe456406bcc20",
"namespaceglm.html#acaa7835f503b1d6e9bed278b9b5f763a",
"namespaceglm.html#ae1fa7277dac2d603b2aaec1df0c1b1fd",
"namespaceglm.html#afd957b3e81c734d05c680dc090e6513d",
"namespacemembers_type_u.html",
"struct_s_d_l___controller_sensor_event.html#aac19e4034212a30d64066a122d5db2a8",
"struct_s_d_l___mouse_wheel_event.html#ab45eb1895217214ecb773fc555e08f6c",
"struct_s_d_l_test___common_state.html#a9357085bdb80f4d9452b73d8f5cebc47",
"structglm_1_1detail_1_1compute__comp_normalize_3_01_l_00_01_t_00_01float_type_00_01_q_00_01true_00_01false_01_4.html",
"structglm_1_1detail_1_1compute__quat__mul__vec4.html",
"structglm_1_1detail_1_1functor2__vec__int_3_011_00_01_t_00_01_q_01_4.html",
"structglm_1_1detail_1_1make__unsigned_3_01signed_01char_01_4.html#af25906396e11879f5afccec2572dae4b",
"structglm_1_1mat_3_012_00_012_00_01_t_00_01_q_01_4.html#aae5b1dd156d9030d848e6f0e2a0d5cd1",
"structglm_1_1mat_3_013_00_012_00_01_t_00_01_q_01_4.html#a3985b6e74e5687bb606f8c4d166d7f75",
"structglm_1_1mat_3_013_00_014_00_01_t_00_01_q_01_4.html#aeed08a5a0acf000dddab2fd839410943",
"structglm_1_1mat_3_014_00_014_00_01_t_00_01_q_01_4.html#a988a7637eeb1d1165946a23d7d2cdaad",
"structglm_1_1tmat2x2.html#ab910eb77d8f50dfa02ad062bb429e0a5",
"structglm_1_1tmat3x2.html#a341f5be67463bce97692bc232312b7e8",
"structglm_1_1tmat3x4.html#aa797d8de2ec5784a9e29776f66998c9f",
"structglm_1_1tmat4x4.html#a19666b2ac9829464ab63697b5975483c",
"structglm_1_1tvec1.html#ae53846b6f7301ae3713cdf38f5ade523",
"structglm_1_1tvec3.html#a2c796e51503a52b4ad1d3c1efd9e9a8e",
"structglm_1_1tvec4.html#a5888692b8c797ac383bb81d93aed5913",
"structglm_1_1vec_3_011_00_01_t_00_01_q_01_4.html#a4f32c80d08972d72ff3b0fbb3d7047d6",
"structglm_1_1vec_3_012_00_01_t_00_01_q_01_4.html#ad428f4c7f12511c0a95a9da3353f0299",
"structglm_1_1vec_3_013_00_01_t_00_01_q_01_4.html#adf06ca1a7f16f0d2ab619810ba836b55",
"structglm_1_1vec_3_014_00_01_t_00_01_q_01_4.html#aabfcc89421d1524dad967f4fa4d771b1",
"structstd_1_1hash_3_01glm_1_1tmat3x2_3_01_t_00_01_p_01_4_01_4.html",
"unionglm_1_1detail_1_1u10u10u10u2.html#a87e65de4f6ca82a84cec4e005f04e403",
"vec__swizzle_8hpp.html#a36be3de64b6db2030a9cbb5d32e57b48",
"vec__swizzle_8hpp.html#abc62af7d8a906efd8b6ec2b9159a44f3"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';
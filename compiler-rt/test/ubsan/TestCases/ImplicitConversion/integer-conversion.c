// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV0 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V0
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV1 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V1
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV2 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V2
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV3 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V3
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV4 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V4
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV5 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V5
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV6 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V6
// RUN: %clang   -x c   -fsanitize=implicit-conversion %s -DV7 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V7

// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV0 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V0
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV1 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V1
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV2 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V2
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV3 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V3
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV4 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V4
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV5 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V5
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV6 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V6
// RUN: %clang   -x c++ -fsanitize=implicit-conversion %s -DV7 -o %t && %run %t 2>&1 | FileCheck %s --implicit-check-not="implicit conversion" --check-prefixes=CHECK-V7

#include <stdint.h>

// Test plan:
//  * Two types - int and char
//  * Two signs - signed and unsigned
//  * Square that - we have input and output types.
// Thus, there are total of (2*2)^2 == 16 tests.
// These are all the possible variations/combinations of casts.
// However, not all of them should result in the check.
// So here, we *only* check which should and which should not result in checks.

uint32_t convert_unsigned_int_to_unsigned_int(uint32_t x) {
#line 100
  return x;
}

uint8_t convert_unsigned_char_to_unsigned_char(uint8_t x) {
#line 200
  return x;
}

int32_t convert_signed_int_to_signed_int(int32_t x) {
#line 300
  return x;
}

int8_t convert_signed_char_to_signed_char(int8_t x) {
#line 400
  return x;
}

uint8_t convert_unsigned_int_to_unsigned_char(uint32_t x) {
#line 500
  return x;
}

uint32_t convert_unsigned_char_to_unsigned_int(uint8_t x) {
#line 600
  return x;
}

int32_t convert_unsigned_char_to_signed_int(uint8_t x) {
#line 700
  return x;
}

int32_t convert_signed_char_to_signed_int(int8_t x) {
#line 800
  return x;
}

int32_t convert_unsigned_int_to_signed_int(uint32_t x) {
#line 900
  return x;
}

uint32_t convert_signed_int_to_unsigned_int(int32_t x) {
#line 1000
  return x;
}

uint8_t convert_signed_int_to_unsigned_char(int32_t x) {
#line 1100
  return x;
}

uint8_t convert_signed_char_to_unsigned_char(int8_t x) {
#line 1200
  return x;
}

int8_t convert_unsigned_char_to_signed_char(uint8_t x) {
#line 1300
  return x;
}

uint32_t convert_signed_char_to_unsigned_int(int8_t x) {
#line 1400
  return x;
}

int8_t convert_unsigned_int_to_signed_char(uint32_t x) {
#line 1500
  return x;
}

int8_t convert_signed_int_to_signed_char(int32_t x) {
#line 1600
  return x;
}

#line 10111 // !!!

int main() {
  // No bits set.
  convert_unsigned_int_to_unsigned_int(0);
  convert_unsigned_char_to_unsigned_char(0);
  convert_signed_int_to_signed_int(0);
  convert_signed_char_to_signed_char(0);
  convert_unsigned_int_to_unsigned_char(0);
  convert_unsigned_char_to_unsigned_int(0);
  convert_unsigned_char_to_signed_int(0);
  convert_signed_char_to_signed_int(0);
  convert_unsigned_int_to_signed_int(0);
  convert_signed_int_to_unsigned_int(0);
  convert_signed_int_to_unsigned_char(0);
  convert_signed_char_to_unsigned_char(0);
  convert_unsigned_char_to_signed_char(0);
  convert_signed_char_to_unsigned_int(0);
  convert_unsigned_int_to_signed_char(0);
  convert_signed_int_to_signed_char(0);

  // One lowest bit set.
  convert_unsigned_int_to_unsigned_int(1);
  convert_unsigned_char_to_unsigned_char(1);
  convert_signed_int_to_signed_int(1);
  convert_signed_char_to_signed_char(1);
  convert_unsigned_int_to_unsigned_char(1);
  convert_unsigned_char_to_unsigned_int(1);
  convert_unsigned_char_to_signed_int(1);
  convert_signed_char_to_signed_int(1);
  convert_unsigned_int_to_signed_int(1);
  convert_signed_int_to_unsigned_int(1);
  convert_signed_int_to_unsigned_char(1);
  convert_signed_char_to_unsigned_char(1);
  convert_unsigned_char_to_signed_char(1);
  convert_signed_char_to_unsigned_int(1);
  convert_unsigned_int_to_signed_char(1);
  convert_signed_int_to_signed_char(1);

#if defined(V0)
  // All source bits set.
  convert_unsigned_int_to_unsigned_int((uint32_t)UINT32_MAX);
  convert_unsigned_char_to_unsigned_char((uint8_t)UINT8_MAX);
  convert_signed_int_to_signed_int((int32_t)(uint32_t)UINT32_MAX);
  convert_signed_char_to_signed_char((int8_t)UINT8_MAX);
  convert_unsigned_int_to_unsigned_char((uint32_t)UINT32_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967295 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned
  convert_unsigned_char_to_unsigned_int((uint8_t)UINT8_MAX);
  convert_unsigned_char_to_signed_int((uint8_t)UINT8_MAX);
  convert_signed_char_to_signed_int((int8_t)UINT8_MAX);
  convert_unsigned_int_to_signed_int((uint32_t)UINT32_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:900:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967295 (32-bit, unsigned) to type 'int32_t' (aka 'int') changed the value to -1 (32-bit, signed)
  convert_signed_int_to_unsigned_int((int32_t)(uint32_t)UINT32_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1000:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -1 (32-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967295 (32-bit, unsigned)
  convert_signed_int_to_unsigned_char((int32_t)(uint32_t)UINT32_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -1 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)UINT8_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -1 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)UINT8_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 255 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)UINT8_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -1 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967295 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((uint32_t)UINT32_MAX);
// CHECK-V0: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967295 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(uint32_t)UINT32_MAX);
#elif defined(V1)
   // Source 'Sign' bit set.
  convert_unsigned_int_to_unsigned_int((uint32_t)INT32_MIN);
  convert_unsigned_char_to_unsigned_char((uint8_t)INT8_MIN);
  convert_signed_int_to_signed_int((int32_t)(uint32_t)INT32_MIN);
  convert_signed_char_to_signed_char((int8_t)INT8_MIN);
  convert_unsigned_int_to_unsigned_char((uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483648 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 0 (8-bit, unsigned)
  convert_unsigned_char_to_unsigned_int((uint8_t)INT8_MIN);
  convert_unsigned_char_to_signed_int((uint8_t)INT8_MIN);
  convert_signed_char_to_signed_int((int8_t)INT8_MIN);
  convert_unsigned_int_to_signed_int((uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:900:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483648 (32-bit, unsigned) to type 'int32_t' (aka 'int') changed the value to -2147483648 (32-bit, signed)
  convert_signed_int_to_unsigned_int((int32_t)(uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1000:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483648 (32-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 2147483648 (32-bit, unsigned)
  convert_signed_int_to_unsigned_char((int32_t)(uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483648 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 0 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)INT8_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)INT8_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 128 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)INT8_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967168 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483648 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to 0 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(uint32_t)INT32_MIN);
// CHECK-V1: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483648 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to 0 (8-bit, signed)
#elif defined(V2)
  // All bits except the source 'Sign' bit are set.
  convert_unsigned_int_to_unsigned_int((uint32_t)INT32_MAX);
  convert_unsigned_char_to_unsigned_char((uint8_t)INT8_MAX);
  convert_signed_int_to_signed_int((int32_t)(uint32_t)INT32_MAX);
  convert_signed_char_to_signed_char((int8_t)INT8_MAX);
  convert_unsigned_int_to_unsigned_char((uint32_t)INT32_MAX);
// CHECK-V2: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483647 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned)
  convert_unsigned_char_to_unsigned_int((uint8_t)INT8_MAX);
  convert_unsigned_char_to_signed_int((uint8_t)INT8_MAX);
  convert_signed_char_to_signed_int((int8_t)INT8_MAX);
  convert_unsigned_int_to_signed_int((uint32_t)INT32_MAX);
  convert_signed_int_to_unsigned_int((int32_t)(uint32_t)INT32_MAX);
  convert_signed_int_to_unsigned_char((int32_t)(uint32_t)INT32_MAX);
// CHECK-V2: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 2147483647 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)INT8_MAX);
  convert_unsigned_char_to_signed_char((uint8_t)INT8_MAX);
  convert_signed_char_to_unsigned_int((int8_t)INT8_MAX);
  convert_unsigned_int_to_signed_char((uint32_t)INT32_MAX);
// CHECK-V2: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483647 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(uint32_t)INT32_MAX);
// CHECK-V2: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 2147483647 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
#elif defined(V3)
  // All destination bits set.
  convert_unsigned_int_to_unsigned_int((uint32_t)UINT8_MAX);
  convert_unsigned_char_to_unsigned_char((uint8_t)UINT8_MAX);
  convert_signed_int_to_signed_int((int32_t)(uint32_t)UINT8_MAX);
  convert_signed_char_to_signed_char((int8_t)UINT8_MAX);
  convert_unsigned_int_to_unsigned_char((uint32_t)UINT8_MAX);
  convert_unsigned_char_to_unsigned_int((uint8_t)UINT8_MAX);
  convert_unsigned_char_to_signed_int((uint8_t)UINT8_MAX);
  convert_signed_char_to_signed_int((int8_t)UINT8_MAX);
  convert_unsigned_int_to_signed_int((uint32_t)UINT8_MAX);
  convert_signed_int_to_unsigned_int((int32_t)(uint32_t)UINT8_MAX);
  convert_signed_int_to_unsigned_char((int32_t)(uint32_t)UINT8_MAX);
  convert_signed_char_to_unsigned_char((int8_t)UINT8_MAX);
// CHECK-V3: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -1 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 255 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)UINT8_MAX);
// CHECK-V3: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 255 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)UINT8_MAX);
// CHECK-V3: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -1 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967295 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((uint32_t)UINT8_MAX);
// CHECK-V3: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 255 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(uint32_t)UINT8_MAX);
// CHECK-V3: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 255 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to -1 (8-bit, signed)
#elif defined(V4)
  // Destination 'sign' bit set.
  convert_unsigned_int_to_unsigned_int((uint32_t)(uint8_t)INT8_MIN);
  convert_unsigned_char_to_unsigned_char((uint8_t)(uint8_t)INT8_MIN);
  convert_signed_int_to_signed_int((int32_t)(uint32_t)(uint8_t)INT8_MIN);
  convert_signed_char_to_signed_char((int8_t)(uint8_t)INT8_MIN);
  convert_unsigned_int_to_unsigned_char((uint32_t)(uint8_t)INT8_MIN);
  convert_unsigned_char_to_unsigned_int((uint8_t)(uint8_t)INT8_MIN);
  convert_unsigned_char_to_signed_int((uint8_t)(uint8_t)INT8_MIN);
  convert_signed_char_to_signed_int((int8_t)(uint8_t)INT8_MIN);
  convert_unsigned_int_to_signed_int((uint32_t)(uint8_t)INT8_MIN);
  convert_signed_int_to_unsigned_int((int32_t)(uint32_t)(uint8_t)INT8_MIN);
  convert_signed_int_to_unsigned_char((int32_t)(uint32_t)(uint8_t)INT8_MIN);
  convert_signed_char_to_unsigned_char((int8_t)(uint8_t)INT8_MIN);
// CHECK-V4: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)(uint8_t)INT8_MIN);
// CHECK-V4: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 128 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)(uint8_t)INT8_MIN);
// CHECK-V4: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967168 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((uint32_t)(uint8_t)INT8_MIN);
// CHECK-V4: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 128 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(uint32_t)(uint8_t)INT8_MIN);
// CHECK-V4: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 128 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
#elif defined(V5)
  // All bits except the destination 'sign' bit are set.
  convert_unsigned_int_to_unsigned_int((~((uint32_t)(uint8_t)INT8_MIN)));
  convert_unsigned_char_to_unsigned_char((uint8_t)(uint8_t)INT8_MIN);
  convert_signed_int_to_signed_int((int32_t)(~((uint32_t)(uint8_t)INT8_MIN)));
  convert_signed_char_to_signed_char((int8_t)(uint8_t)INT8_MIN);
  convert_unsigned_int_to_unsigned_char((~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967167 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 127 (8-bit, unsigned)
  convert_unsigned_char_to_unsigned_int((uint8_t)(uint8_t)INT8_MIN);
  convert_unsigned_char_to_signed_int((uint8_t)(uint8_t)INT8_MIN);
  convert_signed_char_to_signed_int((int8_t)(uint8_t)INT8_MIN);
  convert_unsigned_int_to_signed_int((~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:900:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967167 (32-bit, unsigned) to type 'int32_t' (aka 'int') changed the value to -129 (32-bit, signed)
  convert_signed_int_to_unsigned_int((int32_t)(~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:1000:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -129 (32-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967167 (32-bit, unsigned)
  convert_signed_int_to_unsigned_char((int32_t)(~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -129 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 127 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)(uint8_t)INT8_MIN);
// CHECK-V5: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)(uint8_t)INT8_MIN);
// CHECK-V5: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 128 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)(uint8_t)INT8_MIN);
// CHECK-V5: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967168 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 4294967167 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to 127 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(~((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V5: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -129 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to 127 (8-bit, signed)
#elif defined(V6)
  // Only the source and destination sign bits are set.
  convert_unsigned_int_to_unsigned_int((uint32_t)INT32_MIN);
  convert_unsigned_char_to_unsigned_char((uint8_t)INT8_MIN);
  convert_signed_int_to_signed_int((int32_t)INT32_MIN);
  convert_signed_char_to_signed_char((int8_t)INT8_MIN);
  convert_unsigned_int_to_unsigned_char(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN));
// CHECK-V6: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483776 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_unsigned_char_to_unsigned_int((uint8_t)INT8_MIN);
  convert_unsigned_char_to_signed_int((uint8_t)INT8_MIN);
  convert_signed_char_to_signed_int((int8_t)INT8_MIN);
  convert_unsigned_int_to_signed_int((uint32_t)INT32_MIN);
// CHECK-V6: {{.*}}integer-conversion.c:900:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483648 (32-bit, unsigned) to type 'int32_t' (aka 'int') changed the value to -2147483648 (32-bit, signed)
  convert_signed_int_to_unsigned_int((int32_t)INT32_MIN);
// CHECK-V6: {{.*}}integer-conversion.c:1000:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483648 (32-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 2147483648 (32-bit, unsigned)
  convert_signed_int_to_unsigned_char((int32_t)(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V6: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483520 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)INT8_MIN);
// CHECK-V6: {{.*}}integer-conversion.c:1200:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 128 (8-bit, unsigned)
  convert_unsigned_char_to_signed_char((uint8_t)INT8_MIN);
// CHECK-V6: {{.*}}integer-conversion.c:1300:10: runtime error: implicit conversion from type 'uint8_t' (aka 'unsigned char') of value 128 (8-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_char_to_unsigned_int((int8_t)INT8_MIN);
// CHECK-V6: {{.*}}integer-conversion.c:1400:10: runtime error: implicit conversion from type 'int8_t' (aka 'signed char') of value -128 (8-bit, signed) to type 'uint32_t' (aka 'unsigned int') changed the value to 4294967168 (32-bit, unsigned)
  convert_unsigned_int_to_signed_char((((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V6: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483776 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V6: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value -2147483520 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to -128 (8-bit, signed)
#elif defined(V7)
  // All bits except the source and destination sign bits are set.
  convert_unsigned_int_to_unsigned_int((uint32_t)INT32_MAX);
  convert_unsigned_char_to_unsigned_char((uint8_t)INT8_MAX);
  convert_signed_int_to_signed_int((int32_t)INT32_MAX);
  convert_signed_char_to_signed_char((int8_t)INT8_MAX);
  convert_unsigned_int_to_unsigned_char(~(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V7: {{.*}}integer-conversion.c:500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483519 (32-bit, unsigned) to type 'uint8_t' (aka 'unsigned char') changed the value to 127 (8-bit, unsigned)
  convert_unsigned_char_to_unsigned_int((uint8_t)INT8_MAX);
  convert_unsigned_char_to_signed_int((uint8_t)INT8_MAX);
  convert_signed_char_to_signed_int((int8_t)INT8_MAX);
  convert_unsigned_int_to_signed_int((uint32_t)INT32_MAX);
  convert_signed_int_to_unsigned_int((int32_t)INT32_MAX);
  convert_signed_int_to_unsigned_char((int32_t)(~(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN))));
// CHECK-V7: {{.*}}integer-conversion.c:1100:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 2147483519 (32-bit, signed) to type 'uint8_t' (aka 'unsigned char') changed the value to 127 (8-bit, unsigned)
  convert_signed_char_to_unsigned_char((int8_t)INT8_MAX);
  convert_unsigned_char_to_signed_char((uint8_t)INT8_MAX);
  convert_signed_char_to_unsigned_int((int8_t)INT8_MAX);
  convert_unsigned_int_to_signed_char(~(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V7: {{.*}}integer-conversion.c:1500:10: runtime error: implicit conversion from type 'uint32_t' (aka 'unsigned int') of value 2147483519 (32-bit, unsigned) to type 'int8_t' (aka 'signed char') changed the value to 127 (8-bit, signed)
  convert_signed_int_to_signed_char((int32_t)~(((uint32_t)INT32_MIN) | ((uint32_t)(uint8_t)INT8_MIN)));
// CHECK-V7: {{.*}}integer-conversion.c:1600:10: runtime error: implicit conversion from type 'int32_t' (aka 'int') of value 2147483519 (32-bit, signed) to type 'int8_t' (aka 'signed char') changed the value to 127 (8-bit, signed)
#else
#error Some V* needs to be defined!
#endif

  return 0;
}
/* Verify that overloaded built-ins for __builtin_vec_xst with double
   inputs produce the right code.  */

/* { dg-options "-mvsx -O2" } */
/* { dg-require-effective-target powerpc_vsx } */

#include <altivec.h>

#define BUILD_VAR_TEST(TESTNAME1, VALUE, VAR_OFFSET, SAVETO)		\
void									\
TESTNAME1 ## _var (VALUE value, VAR_OFFSET offset, SAVETO * saveto) 	\
{									\
	__builtin_vec_xst (value, offset, saveto);		\
}

#define BUILD_CST_TEST(TESTNAME1, VALUE, CST_OFFSET, SAVETO)		\
void									\
TESTNAME1 ## _cst (VALUE value, SAVETO * saveto) 			\
{									\
	__builtin_vec_xst (value, CST_OFFSET, saveto);		\
}

BUILD_VAR_TEST( test1,  vector double, signed long long, vector double );
BUILD_VAR_TEST( test2,  vector double, signed int, vector double );
BUILD_CST_TEST( test3,  vector double, 12, vector double );

BUILD_VAR_TEST( test4,  vector double, signed long long, double );
BUILD_VAR_TEST( test5,  vector double, signed int, double );
BUILD_CST_TEST( test6,  vector double, 12, double );

/* { dg-final { scan-assembler-times {\mstxvd2x\M|\mstxvx\M|\mstvx\M|\mpstxv\M} 6 } } */

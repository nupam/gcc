/* { dg-do compile } */
/* { dg-options "-maltivec -mno-vsx -mno-warn-altivec-long" } */
/* { dg-require-effective-target ilp32 } */
/* { dg-require-effective-target powerpc_altivec } */

/* These should not get warnings for 32-bit code when the warning is
   disabled.  */

__vector long vl;
__vector unsigned long vul;
__vector signed long vsl;
__vector __bool long int vbli;
__vector long int vli;
__vector unsigned long int vuli;
__vector signed long int vsli;

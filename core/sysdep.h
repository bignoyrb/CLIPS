   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.24  06/05/06            */
   /*                                                     */
   /*            SYSTEM DEPENDENT HEADER FILE             */
   /*******************************************************/

/*************************************************************/
/* Purpose: Isolation of system dependent routines.          */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*      6.24: Support for run-time programs directly passing */
/*            the hash tables for initialization.            */
/*                                                           */
/*            Added BeforeOpenFunction and AfterOpenFunction */
/*            hooks.                                         */
/*                                                           */
/*            Added environment parameter to GenClose.       */
/*            Added environment parameter to GenOpen.        */
/*                                                           */
/*************************************************************/

#ifndef _H_sysdep
#define _H_sysdep

#ifndef _H_symbol
#include "symbol.h"
#endif

#ifndef _STDIO_INCLUDED_
#define _STDIO_INCLUDED_
#include <stdio.h>
#endif

#include <setjmp.h>

#if WIN_BTC || WIN_MVC
#include <dos.h>
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _SYSDEP_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

   LOCALE void                        InitializeEnvironment(EXEC_STATUS);
   LOCALE void                        EnvInitializeEnvironment(void *,EXEC_STATUS,struct symbolHashNode **,struct floatHashNode **,
															   struct integerHashNode **,struct bitMapHashNode **,
															   struct externalAddressHashNode **);
   LOCALE void                        SetRedrawFunction(void *,EXEC_STATUS,void (*)(void *,EXEC_STATUS));
   LOCALE void                        SetPauseEnvFunction(void *,EXEC_STATUS,void (*)(void *,EXEC_STATUS));
   LOCALE void                        SetContinueEnvFunction(void *,EXEC_STATUS,void (*)(void *,EXEC_STATUS,int));
   LOCALE void                        (*GetRedrawFunction(void *,EXEC_STATUS))(void *,EXEC_STATUS);
   LOCALE void                        (*GetPauseEnvFunction(void *,EXEC_STATUS))(void *,EXEC_STATUS);
   LOCALE void                        (*GetContinueEnvFunction(void *,EXEC_STATUS))(void *,EXEC_STATUS,int);
   LOCALE void                        RerouteStdin(void *,EXEC_STATUS,int,char *[]);
   LOCALE double                      gentime(void);
   LOCALE void                        gensystem(void *,EXEC_STATUS);
   LOCALE void                        VMSSystem(char *);
   LOCALE int                         GenOpenReadBinary(void *,EXEC_STATUS,char *,char *);
   LOCALE void                        GetSeekCurBinary(void *,EXEC_STATUS,long);
   LOCALE void                        GetSeekSetBinary(void *,EXEC_STATUS,long);
   LOCALE void                        GenTellBinary(void *,EXEC_STATUS,long *);
   LOCALE void                        GenCloseBinary(void *,EXEC_STATUS);
   LOCALE void                        GenReadBinary(void *,EXEC_STATUS,void *,size_t);
   LOCALE FILE                       *GenOpen(void *,EXEC_STATUS,char *,char *);
   LOCALE int                         GenClose(void *,EXEC_STATUS,FILE *);
   LOCALE void                        genexit(void *,EXEC_STATUS,int);
   LOCALE int                         genrand(void);
   LOCALE void                        genseed(int);
   LOCALE int                         genremove(char *);
   LOCALE int                         genrename(char *,char *);
   LOCALE char                       *gengetcwd(char *,int);
   LOCALE void                        GenWrite(void *,size_t,FILE *);
   LOCALE int                       (*EnvSetBeforeOpenFunction(void *,EXEC_STATUS,int (*)(void *,EXEC_STATUS)))(void *,EXEC_STATUS);
   LOCALE int                       (*EnvSetAfterOpenFunction(void *,EXEC_STATUS,int (*)(void *,EXEC_STATUS)))(void *,EXEC_STATUS);
   LOCALE int                         gensprintf(char *,const char *,...);
   LOCALE char                       *genstrcpy(char *,const char *);
   LOCALE char                       *genstrncpy(char *,const char *,size_t);
   LOCALE char                       *genstrcat(char *,const char *);
   LOCALE char                       *genstrncat(char *,const char *,size_t);
   LOCALE void                        SetJmpBuffer(void *,EXEC_STATUS,jmp_buf *);
   LOCALE void                        genprintfile(void *,EXEC_STATUS,FILE *,char *);
   LOCALE int                         gengetchar(void *,EXEC_STATUS);
   LOCALE int                         genungetchar(void *,EXEC_STATUS,int);
   
#if WIN_BTC
   LOCALE __int64 _RTLENTRY _EXPFUNC  strtoll(const char *,char **,int);
   LOCALE __int64 _RTLENTRY _EXPFUNC  llabs(__int64 val);
#endif

#endif






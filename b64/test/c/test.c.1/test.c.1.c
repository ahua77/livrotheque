/* /////////////////////////////////////////////////////////////////////////////
 * File:        c/test.c.1/test.c.1.cpp
 *
 * Purpose:     Implementation file for the test.c.1 project.
 *
 * Created:     18th October 2004
 * Updated:     13th May 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2004-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2004
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */

/* b64 Header Files */
#include <b64/b64.h>

/* Standard C Header Files */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#ifdef __BORLANDC__
# pragma warn -8065
#elif defined(__INTEL_COMPILER)
# pragma warning(disable : 1419)
#elif defined(_MSC_VER) && \
      _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);
static int  run_unittests(void);
#ifdef _DEBUG
static void first_tests(void);
#endif /* _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * main
 */

#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca             __builtin_alloca
#elif defined(_WIN32) || \
      defined(_WIN64)
# include <malloc.h>
# ifndef alloca
#  define alloca            _alloca
# endif /* !alloca */
#else /* ? OS */
# include <alloca.h>
#endif /* OS */

int main(int argc, char *argv[])
{
    int         iRet            =   0;
    int         i;

#ifdef _DEBUG
    first_tests();
#endif /* _DEBUG */

    for(i = 1; i < argc; ++i)
    {
        const char  *const  arg =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                /* -- arguments */
                if( 0 == strcmp("unittest", arg + 2) ||
                    0 == strcmp("unittests", arg + 2))
                {
                    return run_unittests();
                }
                else
                {
                    usage(1, "Invalid argument(s) specified", i, argc, argv);
                }
            }
            else
            {
                /* - arguments */
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
        }
        else
        {
            /* other arguments */
            usage(1, "Invalid argument(s) specified", i, argc, argv);
        }
    }

    return iRet;
}

/* /////////////////////////////////////////////////////////////////////////////
 * static functions
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    /* Get the executable name */
    char    *EXE_NAME   =   strcpy((char*)alloca(1 + strlen(argv[0])), argv[0]);
    char    *p;

    if(NULL != (p = strrchr(EXE_NAME, '\\')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    if(NULL != (p = strrchr(EXE_NAME, '/')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }


    fprintf(stderr, "\n");
    fprintf(stderr, "  b64 C test program: %s\n", EXE_NAME);
    fprintf(stderr, "\n");

    if(NULL != reason)
    {
        fprintf(stderr, "  Error: %s\n", reason);
        fprintf(stderr, "\n");
    }

    if(0 < invalidArg)
    {
        int i;

        fprintf(stderr, "  First invalid argument #%d: %s\n", invalidArg, argv[invalidArg]);
        fprintf(stderr, "  Arguments were (first bad marked *):\n\n");
        for(i = 1; i < argc; ++i)
        {
            fprintf(stderr, "  %s%s\n", (i == invalidArg) ? "* " : "  ", argv[i]);
        }
        fprintf(stderr, "\n");
    }

    fprintf(stderr, "  USAGE 1: %s --unittest\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Runs internal tests, returning 0 if all succeed, non-0 otherwise\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  USAGE 2: %s -?\n", EXE_NAME);
    fprintf(stderr, "\n");
    fprintf(stderr, "    Displays this help\n");
    fprintf(stderr, "\n");

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

/* This is needed as a separate function, otherwise we run out of stack!! */
static int execute_unittest()
{
    int             ints[1001];
    const size_t    n       =   rand() % (sizeof(ints) / sizeof(ints[0]));
    size_t          j;
    size_t          cch;
    size_t          cch2;
    char            *enc;
    size_t          cb;
    size_t          cb2;
    int             *dec;

    /* Randomise the array */
    for(j = 0; j < n; ++j)
    {
        ints[j] = rand();
    }

    /* Encode */
    cch     =   b64_encode(&ints[0], n * sizeof(int), NULL, 0);
    enc     =   (char*)alloca(cch);

    cch2    =   b64_encode(&ints[0], n * sizeof(int), enc, cch);

    if( 0 != n &&
        0 == cch)
    {
        fprintf(stderr, "Failed: b64_encode() returned 0\n");

        return 1;
    }
    else if(cch2 != cch)
    {
        fprintf(stderr, "Failed: b64_encode() returned different size to that reported in size determination\n");

        return 1;
    }

    /* Decode */
    cb      =   b64_decode(enc, cch, NULL, 0);
    dec     =   (int*)alloca(cb);

    cb2     =   b64_decode(enc, cch, dec, cb);

    if( 0 != n &&
        0 == cb)
    {
        fprintf(stderr, "Failed: b64_decode() returned 0\n");

        return 1;
    }
    else if(cb2 > cb)
    {
        fprintf(stderr, "Failed: b64_decode() returned different value than that reported in size determination\n");

        return 1;
    }

    if(cb < n * sizeof(int))
    {
        fprintf(stderr, "Failed: wrong size: encoded size: %ld; decoded size: %ld\n", (long)(n * sizeof(int)), (long)cb);

        return 1;
    }

    if(0 != memcmp(&ints[0], &dec[0], cb2))
    {
        fprintf(stderr, "Failed: decoded form different from original!\n");

        return 1;
    }

    return 0;
}

static int run_unittests()
{
    const int   NUM_TESTS   =   10000;
    int         iRet        =   0;
    int         i;

#if 0
    srand(&i);
#endif /* 0 */

    for(i = 0; i < NUM_TESTS; ++i)
    {
        iRet = execute_unittest();

        if(0 != iRet)
        {
            break;
        }
    }

    if(0 == iRet)
    {
        fprintf(stderr, "%d tests succeeded\n", NUM_TESTS);
    }
    else
    {
        fprintf(stderr, "Test #%d failed\n", i);
    }

    return iRet;
}

#ifdef _DEBUG
static void first_tests(void)
{
    static const char   encoded[]   =   "YWJjZGVm Z2hpamtsbW5vcHFyc3#R1dnd4eXp@BQkNERUZHSEl~KS0xNTk9QUVJTVFVWV1hZWjAxMjM0\r\nNTY=";

    B64_RC      rc;
    size_t      n       =   b64_decode2(encoded, strlen(encoded) - 1, NULL, 0, 0, NULL, &rc);
    char        *dest   =   (char*)malloc(n);
    char const  *badChar;
    size_t      n2;

    /* Ignoring all bad content. */

    n2 = b64_decode2(encoded, strlen(encoded) - 1, dest, n, 0, &badChar, &rc);

    if(0 == n2)
    {
        printf("Unexpected failure, when ignoring all bad characters; bad=\"%s\"\n", badChar);
    }
    else
    {
#if 0
        printf("Decoded: %.*s\n", n2, dest);
#endif /* 0 */
    }

    /* Ignoring bad whitespace. */

    n2 = b64_decode2(encoded, strlen(encoded) - 1, dest, n, B64_F_STOP_ON_UNEXPECTED_WS, &badChar, &rc);

    if(0 == n2)
    {
#if 0
        printf("Expected failure, when stopping on bad whitespace characters; bad=\"%s\"\n", badChar);
#endif /* 0 */
    }
    else
    {
        printf("Decoded: %.*s\n", (int)n2, dest);
    }

    /* Ignoring bad whitespace. */

    n2 = b64_decode2(encoded, strlen(encoded) - 1, dest, n, B64_F_STOP_ON_UNKNOWN_CHAR, &badChar, &rc);

    if(0 == n2)
    {
#if 0
        printf("Expected failure, when stopping on unrecognised characters; bad=\"%s\"\n", badChar);
#endif /* 0 */
    }
    else
    {
        printf("Decoded: %.*s\n", (int)n2, dest);
    }
}
#endif /* _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */

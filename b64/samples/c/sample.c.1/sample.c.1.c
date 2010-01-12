/* /////////////////////////////////////////////////////////////////////////
 * File:        c/sample.c.1/sample.c.1.c
 *
 * Purpose:     Implementation file for the sample.c.1 project.
 *
 * Created:     18th October 2004
 * Updated:     3rd May 2008
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
 * ////////////////////////////////////////////////////////////////////// */

/* b64 Header Files */
#include <b64/b64.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
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

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca             __builtin_alloca
#elif defined(WIN32) || \
      defined(WIN64)
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
    int         bVerbose        =   1;
    int         bEncoding       =   1;
    int         i;
    char const  *inputFileName  =   NULL;
    char const  *outputFileName =   NULL;

    for(i = 1; i < argc; ++i)
    {
        const char  *const  arg =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                /* -- arguments */
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
            else
            {
                /* - arguments */
                switch(arg[1])
                {
                    case    'd':
                        bEncoding   =   0;
                        break;
                    case    'e':
                        bEncoding   =   1;
                        break;
                    case    's':
                        bVerbose    =   0;
                        break;
                    case    'v':
                        bVerbose    =   1;
                        break;
                    default:
                        usage(1, "Invalid argument(s) specified", i, argc, argv);
                        break;
                }
            }
        }
        else
        {
            if(NULL == inputFileName)
            {
                inputFileName = arg;
            }
            else if(NULL == outputFileName)
            {
                outputFileName = arg;
            }
            else
            {
                /* other arguments */
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
        }
    }

    if(NULL == inputFileName)
    {
        usage(1, "Must specify an input file", -1, argc, argv);
    }
    if(NULL == outputFileName)
    {
        usage(1, "Must specify an output file", -1, argc, argv);
    }

    if(bVerbose)
    {
        printf("%s %s => %s\n", (bEncoding ? "Encoding" : "Decoding"), inputFileName, outputFileName);
    }

    {
        FILE    *inputFile  =   fopen(inputFileName, "rb");
        FILE    *outputFile =   fopen(outputFileName, "wb");

        if(NULL == inputFile)
        {
            fprintf(stderr, "Could not open file: %s\n", inputFileName);
        }
        else if(NULL == outputFile)
        {
            fprintf(stderr, "Could not create file: %s\n", outputFileName);
        }
        else 
        {
            typedef size_t (*PFn)(void const *, size_t , void *, size_t );

            char    *src;
            size_t  srcLen;
            char    *dest;
            size_t  destLen;
            PFn     pfn =   bEncoding ? (PFn)b64_encode : (PFn)b64_decode;

            fseek(inputFile, 0, SEEK_END);
            srcLen = (size_t)ftell(inputFile);
            fseek(inputFile, 0, SEEK_SET);

            src =   (char*)alloca(srcLen);

            fread(src, 1, srcLen, inputFile);

            destLen =   pfn(src, srcLen, NULL, 0);

            dest    =   (char*)alloca(destLen);

            pfn(src, srcLen, dest, destLen);

            fwrite(dest, 1, destLen, outputFile);
        }

        if(NULL != inputFile)
        {
            fclose(inputFile);
        }
        if(NULL != outputFile)
        {
            fclose(outputFile);
        }
    }

    return iRet;
}

/* /////////////////////////////////////////////////////////////////////////
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

    fprintf(stderr, "  USAGE 1: %s [-e | -d] <input-file> <output-file>\n\n", EXE_NAME);
    fprintf(stderr, "    -d            - decode the <input-file>\n");
    fprintf(stderr, "    -e            - encode the <input-file>\n");
    fprintf(stderr, "    <input-file>  - file whose contents are to be converted\n");
    fprintf(stderr, "    <output-file> - file where the converted results are stored\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "    Converts the <input-file> to the <output-file> by either\n");
    fprintf(stderr, "    Base-64 encoding (-e) or Base-64 decoding (-d)\n");
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

/* /////////////////////////////////////////////////////////////////////////
 * end of file
 */

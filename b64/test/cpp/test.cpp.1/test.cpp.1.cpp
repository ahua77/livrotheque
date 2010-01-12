/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.cpp.1.cpp
 *
 * Purpose:     Implementation file for the test.cpp.1 project.
 *
 * Created:     18th October 2004
 * Updated:     15th March 2008
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
#include <b64/b64.hpp>

/* STLSoft Header Files */
#include <stlsoft/conversion/sap_cast.hpp>

/* PlatformSTL Header Files */
#if !defined(STLSOFT_COMPILER_IS_WATCOM)
# include <platformstl/filesystem/memory_mapped_file.hpp>
#endif /* !STLSOFT_COMPILER_IS_WATCOM */

/* Standard C++ Header Files */
#include <exception>
#include <fstream>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#if defined(STLSOFT_COMPILER_IS_WATCOM)
# include <exception.h>
namespace std
{
    using ::exception;
}
#endif /* STLSOFT_COMPILER_IS_WATCOM */

/* Standard C Header Files */
#include <assert.h>
#include <time.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[]);
static int  run_unittests();

/* /////////////////////////////////////////////////////////////////////////////
 * main
 */

static int main_(int argc, char *argv[])
{
    int i;

#ifdef _DEBUG
    {
        stlsoft::c_str_ptr(b64::B64_RC_OK);
        stlsoft::c_str_ptr(b64::B64_RC_INSUFFICIENT_BUFFER);
        stlsoft::c_str_ptr(b64::B64_RC_TRUNCATED_INPUT);
        stlsoft::c_str_ptr(b64::B64_RC_DATA_ERROR);
    }
#endif /* _DEBUG */

    for(i = 1; i < argc; ++i)
    {
        const char  *arg    =   argv[i];

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

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::exception &x)
    {
        cerr << "Unhandled error: " << x.what() << endl;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;
    }

    return EXIT_FAILURE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

/* /////////////////////////////////////////////////////////////////////////////
 * static functions
 */

#if defined(__GNUC__)
# ifdef alloca
#  undef alloca
# endif /* !alloca */
# define alloca             __builtin_alloca
#elif defined(WIN32) || \
      defined(__WATCOMC__)
# include <malloc.h>
# ifndef alloca
#  define alloca            _alloca
# endif /* !alloca */
#else /* ? OS */
# include <alloca.h>
#endif /* OS */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char *argv[])
{
    char    *EXE_NAME   =   strcpy(static_cast<char*>(alloca(1 + strlen(argv[0]))), argv[0]);
    char    *p;

    if(NULL != (p = strrchr(EXE_NAME, '\\')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    if(NULL != (p = strrchr(EXE_NAME, '/')))
    {
        0[(EXE_NAME = p + 1) - 1] = '\0';
    }

    cerr << "" << endl;
    cerr << "  b64 C++ test program: " << EXE_NAME << endl;;
    cerr << "" << endl;

    stlsoft_assert(invalidArg < argc);

    if(NULL != reason)
    {
        cerr << "  Error: " << reason << "" << endl;
        cerr << "" << endl;
    }

    if(0 < invalidArg)
    {
        cerr << "  First invalid argument #" << invalidArg << ": " << argv[invalidArg] << endl;
        cerr << "  Arguments were (first bad marked *):" << endl << endl;
        for(int i = 1; i < argc; ++i)
        {
            cerr << "  " << ((i == invalidArg) ? "* " : "  ") << argv[i] << endl;
        }
        cerr << "" << endl;
    }

    cerr << "  USAGE 1: " << EXE_NAME << " --unittest" << endl;
    cerr << "" << endl;
    cerr << "    Runs internal tests, returning 0 if all succeed, non-0 otherwise" << endl;
    cerr << "" << endl;
    cerr << "  USAGE 2: " << EXE_NAME << " -?" << endl;
    cerr << "" << endl;
    cerr << "    Displays this help" << endl;
    cerr << "" << endl;

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

static int execute_unittest()
{
    int             iRet    =   0;
    int             ints[1001];
    const size_t    n       =   rand() % (sizeof(ints) / sizeof(ints[0]));
    size_t          j;

    /* Randomise the array */
    for(j = 0; j < n; ++j)
    {
        ints[j] = rand();
    }

    /* Encode */
    b64::cpp::string_t  enc =   b64::cpp::encode(&ints[0], (1 + (rand() - 1)) % sizeof(ints));

    /* Decode */
    b64::cpp::blob_t    dec =   b64::cpp::decode(enc);

    if( !dec.empty() &&
        0 != ::memcmp(&ints[0], &dec[0], dec.size()))
    {
        cerr << "Failed!" << endl;

        iRet = 1;
    }

    return iRet;
}

static int run_unittests()
{
#ifdef __BORLANDC__
# pragma warn -8080 // For some silly reason, Borland C++ cannot see that NUM_TESTS is used!!
#endif /* __BORLANDC__ */

    const int   NUM_TESTS   =   10000;
    int         iRet        =   0;
    int         i;

    srand(static_cast<unsigned int>(time(NULL)));

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
        cerr << NUM_TESTS << " tests succeeded" << endl;
    }
    else
    {
        cerr << "Test " << i << " failed" << endl;
    }

    return iRet;
}

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */

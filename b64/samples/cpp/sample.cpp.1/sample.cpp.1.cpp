/* /////////////////////////////////////////////////////////////////////////////
 * File:        cpp/sample.cpp.1/sample.cpp.1.cpp
 *
 * Purpose:     Implementation file for the Cpp project.
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

/* /////////////////////////////////////////////////////////////////////////////
 * main
 */

static int main_(int argc, char *argv[])
{
    int         iRet            =   0;
    int         bVerbose        =   true;
    int         bEncoding       =   true;
    int         i;
    char const  *inputFileName  =   NULL;
    char const  *outputFileName =   NULL;

#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
//  cout << "Cpp: " << STLSOFT_COMPILER_LABEL_STRING << endl;
#endif /* debug */

    for(i = 1; i < argc; ++i)
    {
        const char  *arg    =   argv[i];

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
                        bEncoding   =   false;
                        break;
                    case    'e':
                        bEncoding   =   true;
                        break;
                    case    's':
                        bVerbose    =   false;
                        break;
                    case    'v':
                        bVerbose    =   true;
                        break;
                    default:
                        usage(1, "Invalid argument(s) specified", i, argc, argv);
                        break;
                }
            }
        }
        else if(NULL == inputFileName)
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
        cout << (bEncoding ? "Encoding" : "Decoding") << " " << inputFileName << " => " << outputFileName << endl;
    }

#if !defined(STLSOFT_COMPILER_IS_WATCOM)
    ::platformstl::memory_mapped_file   mmf(inputFileName);

    if(bEncoding)
    {
        std::string     encoded = b64::cpp::encode(mmf.memory(), static_cast<size_t>(mmf.size()));

        std::ofstream   os(outputFileName);

        os << encoded;
    }
    else
    {
        b64::cpp::blob_t    decoded = b64::cpp::decode(static_cast<char const*>(mmf.memory()), static_cast<size_t>(mmf.size()));

        std::ofstream       stm(outputFileName, std::ios::out | std::ios::binary);

        using namespace stlsoft;    // for sap_cast (can't qualify, as some really dumb old compilers don't support it as a class)

        stm.write(sap_cast<char const*>(&decoded[0]), static_cast<std::streamsize>(decoded.size()));
    }
#endif /* !STLSOFT_COMPILER_IS_WATCOM */

    return iRet;
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
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return EXIT_FAILURE;
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

    cerr << "  USAGE 1: " << EXE_NAME << " [-e | -d] <input-file> <output-file>" << endl;
    cerr << "" << endl;
    cerr << "    -d            - decode the <input-file>" << endl;
    cerr << "    -e            - encode the <input-file>" << endl;
    cerr << "    <input-file>  - file whose contents are to be converted" << endl;
    cerr << "    <output-file> - file where the converted results are stored" << endl;
    cerr << "" << endl;
    cerr << "    Converts the <input-file> to the <output-file> by either" << endl;
    cerr << "    Base-64 encoding (-e) or Base-64 decoding (-d)" << endl;
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

/* /////////////////////////////////////////////////////////////////////////////
 * end of file
 */

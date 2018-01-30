// Copyright 2018, hongchu098.  All rights reserved. 
// 
// Licensed under an MIT-style license that can be found in 
// the LICENSE file at the top-level directory. 
 
// Author: hongchu098 (hongchu098 at aliyun dot com) 
// 
 

#ifndef CJMISC_FIXEDINT_HPP_
# define CJMISC_FIXEDINT_HPP_

# include <cstdint>

namespace cjmisc
{
    typedef signed char schar;
    typedef signed short sshort;
    typedef signed int sint;
    typedef signed long slong;
    typedef signed long long sllong;

    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
    typedef unsigned long ulong;
    typedef unsigned long long ullong;

    typedef std::int8_t s8;
    typedef std::int16_t s16;
    typedef std::int32_t s32;
    typedef std::int64_t s64;

    typedef std::uint8_t u8;
    typedef std::uint16_t u16;
    typedef std::uint32_t u32;
    typedef std::uint64_t u64;

    typedef std::int_least8_t sleast8;
    typedef std::int_least16_t sleast16;
    typedef std::int_least32_t sleast32;
    typedef std::int_least64_t sleast64;

    typedef std::uint_least8_t uleast8;
    typedef std::uint_least16_t uleast16;
    typedef std::uint_least32_t uleast32;
    typedef std::uint_least64_t uleast64;
}

#endif

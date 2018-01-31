// Copyright 2018, hongchu098.  All rights reserved. 
// 
// Licensed under an MIT-style license that can be found in 
// the LICENSE file at the top-level directory. 
 
// Author: hongchu098 (hongchu098 at aliyun dot com) 
// 


#ifndef CJMISC_OUTPUTF_HPP_
# define CJMISC_OUTPUTF_HPP_

# include <string>
# include <sstream>
# include <functional>

namespace cjmisc
{

    template<typename T>
    struct to_pointer_if_array
    {
        typedef typename std::conditional
          <
            std::is_array<typename std::remove_reference<T>::type>::value,
            typename std::decay<T>::type,
            T
          >::type type;
    };

    // Thread Safety: according to $os
    template<typename OStreamType>
    void outputf_0(OStreamType& os, const char* str)
    {
        for(std::size_t i = 0; str[i] != 0; ++i)
            if(str[i] == '%' && (str[i + 1] == '{' || str[i + 1] == '}' || str[i + 1] == '%'))
                os.put(str[++i]);
            else
                os.put(str[i]);
    }

    // Thread Safety: according to $os
    template<typename OStreamType, typename T, typename... ARGS>
    void outputf_0(OStreamType& os, const char* str, const T& arg0, const ARGS&... args)
    {
        for(std::size_t i = 0; str[i] != 0; ++i)
            if(str[i] == '{' && str[i + 1] == '}')
            {
                os << arg0;
                return outputf_0(os, str + i + 2, args...);
            }
            else if(str[i] == '%' && (str[i + 1] == '{' || str[i + 1] == '}' || str[i + 1] == '%'))
                os.put(str[++i]);
            else
                os.put(str[i]);
    }

    // Thread Safety: according to $os
    template<typename OStreamType, typename... ARGS>
    inline void outputf_1(OStreamType& os, const char* str, const ARGS&... args)
    {
        outputf_0(os, str, static_cast<typename to_pointer_if_array<const ARGS&>::type>(args)...);
        os.flush();
    }

    // Thread Safety: according to $os
    template<typename OStreamType, typename... ARGS>
    inline void outputf(OStreamType& os, const char* str, const ARGS&... args)
    {
        return outputf_1(os, str, static_cast<typename to_pointer_if_array<const ARGS&>::type>(args)...);
    }

    // Thread Safety: safe
    template<typename... ARGS>
    std::string soutputf_0(const char* fmt, const ARGS&... args)
    {
        std::stringstream ss;
        outputf(ss, fmt, args...);
        return ss.str();
    }

    // Thread Safety: safe
    template<typename... ARGS>
    inline std::string soutputf(const char* fmt, const ARGS&... args)
    {
        return soutputf_0(fmt, static_cast<typename to_pointer_if_array<const ARGS&>::type>(args)...);
    }

}

#endif

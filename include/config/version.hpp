#ifndef EXAMPE_VERSION_HPP
#define EXAMPE_VERSION_HPP

#include <iostream>
    
#define EXAMPLE_VERSION_MAJOR 0
#define EXAMPLE_VERSION_MINOR 123
#define EXAMPLE_VERSION_PATCH 2

struct versioning_info
{
    unsigned int const major_;
    unsigned int const minor_;
    unsigned int const patch_;

    versioning_info(unsigned int major,
                    unsigned int minor,
                    unsigned int patch)
       : major_(major),
         minor_(minor),
         patch_(patch)
    {}

    friend std::ostream& operator<<(std::ostream& os, const versioning_info& ver)
    {
        os << ver.major_ << '.'
           << ver.minor_ << '.'
           << ver.patch_;
        return os;
    }

    versioning_info(const versioning_info&) = default;
    versioning_info() = delete;
    versioning_info& operator=(const versioning_info&) = delete;
}; 

inline
versioning_info version()
{
    static versioning_info ver(EXAMPLE_VERSION_MAJOR, EXAMPLE_VERSION_MINOR, EXAMPLE_VERSION_PATCH);
    return ver;
}


#ifndef EXAMPE_VERSION_HPP
#define EXAMPE_VERSION_HPP

#include <iostream>
    
#define EXAMPLE_VERSION_MAJOR 0
#define EXAMPLE_VERSION_MINOR 123
#define EXAMPLE_VERSION_PATCH 2

struct versioning_info
{
    unsigned int const major;
    unsigned int const minor;
    unsigned int const patch;

    versioning_info(unsigned int major,
                    unsigned int minor,
                    unsigned int patch)
       : major(major),
         minor(minor),
         patch(patch)
    {}

    friend std::ostream& operator<<(std::ostream& os, const versioning_info& ver)
    {
        os << ver.major << '.'
           << ver.minor << '.'
           << ver.patch;
        return os;
    }

    versioning_info(const versioning_info&) = default;
    versioning_info() = delete;
    versioning_info& operator=(const versioning_info&) = delete;
}; 

constexpr versioning_info version()
{
    static constexpr versioning_info ver(EXAMPLE_VERSION_MAJOR, EXAMPLE_VERSION_MINOR, EXAMPLE_VERSION_PATCH);
    return ver;
}

#endif

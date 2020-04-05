#include "../include/Mona/MonaFilter.h"
//-------------------------------------------------------------------------//
#include <stdexcept>
//-------------------------------------------------------------------------//
namespace Mona {
//-------------------------------------------------------------------------//
    MonaFilter::MonaFilter(const std::string & fname) : handle(dlopen(fname.c_str(), RTLD_LAZY))
    {
#if defined(_DEBUG)
        assert(this->handle != nullptr && "Invalid handle pointer.");
#endif // defined(_DEBUG)
        if (this->handle == nullptr) {
            throw (std::invalid_argument(dlerror()));
        }
    }

    MonaFilter::~MonaFilter() noexcept
    {
        if (this->handle != nullptr) {
            dlclose(handle);
            handle = nullptr;
        }
    }

    auto MonaFilter::good() const noexcept -> bool
    {
        return (this->handle != nullptr);
    }

    auto MonaFilter::load(const std::string & fname) -> void
    {
#if defined(_DEBUG)
        assert(fname.empty() != true && "Invalid name of library file.");
#endif // defined(_DEBUG)
        if (this->handle != nullptr) {
            dlclose(handle);
            handle = nullptr;
        }
        if (fname.empty() != true) {
            // Loading the library.
            this->handle = dlopen(fname.c_str(), RTLD_LAZY);
        }
#if defined(_DEBUG)
        assert(this->handle != nullptr && "Invalid handle pointer.");
#endif // defined(_DEBUG)
        if (this->handle == nullptr) {
            throw (std::invalid_argument(dlerror()));
        }
    }

    auto MonaFilter::accept(const std::string & url) -> bool
    {
#if defined(_DEBUG)
        assert(this->handle != nullptr && "Invalid pointer on dl handle.");
#endif // defined(_DEBUG)
        if (this->handle != nullptr) {
            // Getting a pointer on method.
            auto method = reinterpret_cast<accept_t>(dlsym(this->handle, "accept"));
            // Getting an error.
            auto error = dlerror();
            if (error != nullptr) {
                throw (std::invalid_argument(error));
            }
            return (*method)(url.c_str());
        }
        return true;
    }

    auto MonaFilter::notify(const char * url, short type) -> void
    {
#if defined(_DEBUG)
        assert(this->handle != nullptr && "Invalid pointer on dl handle.");
#endif // defined(_DEBUG)
        if (this->handle != nullptr) {
            // Getting a pointer on method.
            auto method = reinterpret_cast<notify_t >(dlsym(this->handle, "notify"));
            // Getting an error.
            auto error = dlerror();
            if (error != nullptr) {
                throw (std::invalid_argument(error));
            }
            // Calling a method.
            (*method)(url, type);
        }
    }
//-------------------------------------------------------------------------//
}; // namespace Mona
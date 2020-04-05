/*!==========================================================================
* \file
* - Program:       MonaBase
* - File:          MonaFilter.h
* - Created:       04/04/2020
* - Authors:       Vitaly Bulganin
* - Description:
* - Comments:
*
-----------------------------------------------------------------------------
*
* - History:
*
===========================================================================*/
#pragma only
//-------------------------------------------------------------------------//
#ifndef __MONA_FILTER_H_182C7E63_E1CF_412A_8E63_D5CF4213BCB1__
#define __MONA_FILTER_H_182C7E63_E1CF_412A_8E63_D5CF4213BCB1__
//-------------------------------------------------------------------------//
#include <string>
#include <dlfcn.h>
//-------------------------------------------------------------------------//
namespace Mona {
    //!<
    class MonaFilter final {
        using accept_t = bool(*)(const char * url);
        using notify_t = void(*)(const char * url, short type);
        //!< Keeps a handle.
        void * handle = nullptr;

    public:
        /**
         * Constructor.
         */
        MonaFilter() = default;

        /**
         * Constructor.
         * @param fname [in] - A name of dynamic library file.
         * @throw std::invalid_argument - Error loading a library.
         */
        explicit MonaFilter(const std::string & fname);

        /**
         * Destructor.
         * @throw None.
         */
        ~MonaFilter() noexcept;

        /**
         * Checks the filter on valid.
         * @return true, if the filter has already initialized, otherwise false.
         * @throw None.
         */
        auto good() const noexcept -> bool;

        /**
         * Loads a filter.
         * @param fname [in] - A name of dynamic library file.
         * @throw std::invalid_argument - Error loading the file.
         */
        auto load(const std::string & fname) -> void;

        /**
         * Checks the URL on acceptance.
         * @param url [in] - URL.
         * @return true, if the URL is acceptable, otherwise false.
         * @throw std::invalid_argument - Error calling a method.
         */
        auto accept(const std::string & url) -> bool;

        /**
         * Notifies somebody.
         * @param url [in] - The URL's client.
         * @param type [in] - A type of notification.
         * @throw std::invalid_argument - Error calling a method.
         * @note A type is one of the following values: 1 - start, 2 - stop.
         */
        auto notify(const char * url, short type) -> void;
    };
}; // namespace Mona
//-------------------------------------------------------------------------//
#endif // __MONA_FILTER_H_182C7E63_E1CF_412A_8E63_D5CF4213BCB1__

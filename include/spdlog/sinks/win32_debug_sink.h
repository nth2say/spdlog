#pragma once
#include <mutex>
#include "./base_sink.h"
#include "../details/null_mutex.h"
#include <debugapi.h>
namespace spdlog {
    namespace sinks {
        template <class Mutex>
        class win32_debug_sink : public base_sink<Mutex> {
        protected:
            void _sink_it(const details::log_msg& msg) override
            {
                OutputDebugStringA(msg.formatted.str().c_str());
            }

        public:
            void flush() override
            {
            }
        };

        typedef win32_debug_sink<details::null_mutex> win32_debug_sink_st;
        typedef win32_debug_sink<std::mutex> win32_debug_sink_mt;
    }
}

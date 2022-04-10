#include <iop-hal/runtime.hpp>
#include <iop/loop.hpp>

#include <unity.h>

namespace iop {
    auto setup(EventLoop &loop) noexcept -> void {
        (void) loop;
    }
}

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    UNITY_BEGIN();
    iop_hal::setup();
    UNITY_END();
    return 0;
}
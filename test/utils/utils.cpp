#include <iop/utils.hpp>
#include <iop/loop.hpp>

#include <unity.h>

#include <iostream>

namespace iop {
    auto setup(EventLoop &loop) noexcept -> void {
        (void) loop;
    }
}

void interrupts() {
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::NONE);
    iop::scheduleInterrupt(iop::InterruptEvent::MUST_UPGRADE);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::MUST_UPGRADE);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::NONE);

    iop::scheduleInterrupt(iop::InterruptEvent::MUST_UPGRADE);
    iop::scheduleInterrupt(iop::InterruptEvent::MUST_UPGRADE);
    iop::scheduleInterrupt(iop::InterruptEvent::ON_CONNECTION);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::MUST_UPGRADE);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::ON_CONNECTION);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::NONE);
    TEST_ASSERT(iop::descheduleInterrupt() == iop::InterruptEvent::NONE);
}

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    UNITY_BEGIN();
    RUN_TEST(interrupts);
    UNITY_END();
    return 0;
}
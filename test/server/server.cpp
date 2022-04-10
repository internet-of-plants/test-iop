#include <iop-hal/network.hpp>
#include <iop/server.hpp>
#include <iop/api.hpp>
#include <iop/loop.hpp>

#include <pthread.h>
#include <unity.h>
#include <unistd.h>
#include <thread>
#include <chrono>

namespace iop {
    auto setup(EventLoop &loop) noexcept -> void {
        (void) loop;
    }
}

const static iop::StaticString serverHost(reinterpret_cast<const __FlashStringHelper *>("http://127.0.0.1:8082"));

/*
void producer() {
    iop_hal::HTTPClient client;
    client.begin(iop::Network::wifiClient(), serverHost.toString());
    const auto code = client.sendRequest("GET", "");
    iop::Log::print((std::string("Status: ") + std::to_string(code) + "\n").c_str(), iop::LogLevel::INFO, iop::LogType::STARTEND);
    usleep(1000);
    TEST_ASSERT(code == 200);

    const auto rawStatus = iop::Network(serverHost, iop::LogLevel::WARN).rawStatus(code);
    const auto rawStatusStr = iop::Network::rawStatusToString(rawStatus);
    const auto forbidden = "UNKNOWN-not-documented";
    iop::Log::print((std::string("Payload: ") + client.getString() + "\n").c_str(), iop::LogLevel::INFO, iop::LogType::STARTEND);
    if (rawStatusStr.length() == strlen(forbidden)) {
        TEST_ASSERT(strcmp(rawStatusStr.asCharPtr(), forbidden) != 0);
    }
}

void * consumer(void* ptr) {
    auto *server = static_cast<CredentialsServer *>(ptr);
    std::optional<AuthToken> maybeToken;
    while (!(maybeToken = server->serve(std::nullopt, eventLoop.api()))) {
        usleep(100);
    }
    TEST_ASSERT(!maybeToken);
    return nullptr;
}
*/

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;
    UNITY_BEGIN();
    /*
    iop::Log(iop::LogLevel::TRACE, IOP_STR("SERVER")).setup(iop::LogLevel::TRACE);

    CredentialsServer server(iop::LogLevel::WARN);

    server.setup();
    TEST_ASSERT(!server.serve(std::nullopt, api));

    pthread_t id;
    pthread_create(&id, NULL, consumer, &server);
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(5000ms);
    producer();

    pthread_join(id, NULL);

    server.close();
    */
    UNITY_END();
    return 0;
}
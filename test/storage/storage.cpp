#include <iop-hal/string.hpp>
#include <iop/storage.hpp>
#include <iop/loop.hpp>

#include <unity.h>

namespace iop {
    auto setup(EventLoop &loop) noexcept -> void {
        (void) loop;
    }
}

void authToken() {
  const iop::Storage storage(iop::LogLevel::WARN);
  storage.setup();
  storage.removeToken();
  TEST_ASSERT(!storage.token());
  iop::AuthToken token;
  token.fill('A');
  
  storage.setToken(token);
  TEST_ASSERT(storage.token().value().get() == token);
  storage.removeToken();
  TEST_ASSERT(!storage.token());
}

void wifiConfig() {
  const iop::Storage storage(iop::LogLevel::WARN);
  storage.setup();
  storage.removeWifi();
  TEST_ASSERT(!storage.wifi());

  iop::NetworkName ssid;
  ssid.fill('\0');
  std::memcpy(ssid.data(), "Bruh", 4);

  iop::NetworkPassword psk;
  psk.fill('\0');
  std::memcpy(psk.data(), "Bruh", 4);
  
  const iop::WifiCredentials creds(ssid, psk);
  storage.setWifi(creds);
  TEST_ASSERT(iop::to_view(storage.wifi().value().get().ssid) == iop::to_view(creds.ssid));
  TEST_ASSERT(iop::to_view(storage.wifi().value().get().password) == iop::to_view(creds.password));
  storage.removeWifi();
  TEST_ASSERT(!storage.wifi());
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  UNITY_BEGIN();
  RUN_TEST(authToken);
  RUN_TEST(wifiConfig);
  UNITY_END();
  return 0;
}
#include <stddef.h>
#include <stdint.h>

#include <span>

#include "nstun/encap.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	(void)nstun::parse_socks5_auth_reply(std::span<const uint8_t>(data, size));
	return 0;
}

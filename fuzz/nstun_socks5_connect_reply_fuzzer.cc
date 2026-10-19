#include <stddef.h>
#include <stdint.h>

#include <span>

#include "nstun/encap.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	nstun::Socks5Reply reply = {};
	(void)nstun::parse_socks5_connect_reply(std::span<const uint8_t>(data, size), &reply);
	return 0;
}

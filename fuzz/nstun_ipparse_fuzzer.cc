#include <stddef.h>
#include <stdint.h>

#include <span>

#include "nstun/ipparse.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	if (size < 1) {
		return 0;
	}

	/* The first byte picks the starting next-header value so the fuzzer can
	 * enter the walk at any of the extension headers. */
	nstun::ByteReader reader(std::span<const uint8_t>(data + 1, size - 1));
	(void)nstun::skip_ipv6_ext_headers(data[0], &reader);
	return 0;
}

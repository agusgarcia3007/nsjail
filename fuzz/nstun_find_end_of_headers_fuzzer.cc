#include <stddef.h>
#include <stdint.h>

#include <vector>

#include "nstun/encap.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	std::vector<uint8_t> buf(data, data + size);
	(void)nstun::find_end_of_headers(buf);
	return 0;
}

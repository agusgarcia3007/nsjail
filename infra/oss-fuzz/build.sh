#!/bin/bash -eu
# Build the nstun parser fuzzers for OSS-Fuzz.
#
# The targets only use the dependency-free parsing TUs (ipparse.cc and
# encap.cc), so this does not need protobuf, libnl, or the kafel submodule.

cd "$SRC/nsjail"

compile() {
	local name="$1"
	local deps="$2"
	$CXX $CXXFLAGS -std=c++20 -I. \
		"fuzz/nstun_${name}_fuzzer.cc" $deps \
		$LIB_FUZZING_ENGINE -o "$OUT/nstun_${name}_fuzzer"
}

compile ipparse nstun/ipparse.cc
compile socks5_auth_reply nstun/encap.cc
compile socks5_connect_reply nstun/encap.cc
compile http_connect_reply nstun/encap.cc
compile find_end_of_headers nstun/encap.cc

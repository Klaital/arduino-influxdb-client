cc_library(
	name = "influxdb-client",
	hdrs=glob(["**/*.h"]),
    srcs=glob(["**/*.cpp"]),
)
cc_test(
	name = "influxdb_test",
	size = "small",
	srcs = [
		"influxdb.cpp",
		"influxdb_test.cc",
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"//:influxdb-client",
	],
)

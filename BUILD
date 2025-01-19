cc_library(
	name = "influxdb-client",
	hdrs=glob(["**/*.h"]),
    srcs=glob(["**/influxdb.cpp"]),
)
cc_library(
	name = "keyvalpair",
	hdrs=glob(["**/keyvalpair.h"]),
	srcs=glob(["**/keyvalpair.cpp"]),
)
cc_library(
	name = "point",
	hdrs=glob(["**/point.h", "**/keyvalpair.h"]),
	srcs=glob(["**/point.cpp"]),
)
cc_test(
	name = "influxdb_test",
	size = "large",
	srcs = [
		"influxdb.cpp",
		"influxdb_test.cc",
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"//:influxdb-client",
		"//:point",
		"//:keyvalpair",
		"//:keyvalpair_test",
		"//:point_test",
	],
)
cc_test(
	name = "keyvalpair_test",
	size = "small",
	srcs = [
		"keyvalpair.cpp",
		"keyvalpair_test.cc",
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"//:keyvalpair",
	],
)
cc_test(
	name = "point_test",
	size = "small",
	srcs = [
		"point.cpp",
		"point_test.cc",
	],
	deps = [
		"@googletest//:gtest",
		"@googletest//:gtest_main",
		"//:point",
		"//:keyvalpair",
		"//:keyvalpair_test",
	],
)

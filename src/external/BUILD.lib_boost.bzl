"""@lib_boost//:libs
"""
package(default_visibility = ["//visibility:public"])
cc_library(
    name = "libs",
    srcs = ["libboost_python310.a", "libboost_numpy310.a"],
)

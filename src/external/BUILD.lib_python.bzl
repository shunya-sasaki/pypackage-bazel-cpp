""" @lib_python//:libs
"""
package(default_visibility = ["//visibility:public"])
cc_library(
    name = "libs",
    srcs = ["libpython3.10.a"]
)

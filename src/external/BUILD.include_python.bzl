""" @libpython//:headers
"""
package(default_visibility = ["//visibility:public"])
cc_library(
    name = "headers",
    hdrs = glob(["**/*.h", "**/*.hpp"]),
    includes = ["."],
)

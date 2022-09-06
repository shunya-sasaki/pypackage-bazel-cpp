load("@rules_python//python:packaging.bzl", "py_wheel")

cc_library(
    name = "cpp",
    srcs = [
        "cpp.cc",
        "cpp.h"
    ],
    copts = [
        "-Iexternal/include_boost",
        "-Iexternal/include_python",
    ],
    linkopts = [
        "-Lexternal/lib_boost",
        "-lboost_python310",
        "-lboost_numpy310",
    ],
    linkstatic = True,
    visibility = ["//src/main:__pkg__"],
    deps = [
        "@include_boost//:headers",
        "@include_python//:headers",
        "@lib_boost//:libs",
        "boostmodule"
    ],
)

cc_library(
    name = "boostmodule",
    srcs = [
        "boostmodule.cc",
        "boostmodule.h",
    ],
    copts = [
        "-Iexternal/include_boost",
    ],
    linkopts = [
        "-Lexternal/lib_boost",
        "-lboost_numpy310",
    ],
    linkstatic = True,
    visibility = ["//src/main:__pkg__"],
    deps = [
        "@include_boost//:headers",
        "@include_python//:headers",
        "@lib_boost//:libs",
    ],
)


py_library(
    name = "pylib",
    srcs = glob(["**/*.py"]),
    data = [":cpp"],
    visibility = ["//main:__pkg__"],
)

py_wheel(
    name = "wheel",
    distribution = "mypackage",
    python_tag = "py3",
    version = "0.0.0",
    deps = [":pylib"],
)

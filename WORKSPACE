"""
"""
INCLUDE_BOOST = "/opt/homebrew/include"
LIB_BOOST = "/opt/homebrew/lib"
INCLUDE_PYTHON = "/opt/homebrew/opt/python@3.10/Frameworks/Python.framework/Versions/3.10/include/python3.10"
LIB_PYTHON = "/opt/homebrew/opt/python@3.10/Frameworks/Python.framework/Versions/3.10/lib/python3.10/config-3.10-darwin"

new_local_repository(
    name = "include_boost",
    path = INCLUDE_BOOST,
    build_file = "src/external/BUILD.include_boost.bzl"
)

new_local_repository(
    name = "lib_boost",
    path = LIB_BOOST,
    build_file = "src/external/BUILD.lib_boost.bzl"
)


new_local_repository(
    name = "include_python",
    path = INCLUDE_PYTHON,
    build_file = "src/external/BUILD.include_python.bzl"
)

new_local_repository(
    name = "lib_python",
    path = LIB_PYTHON,
    build_file = "src/external/BUILD.lib_python.bzl"
)

local_repository(
    name="main",
    path="src/main"
)


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "rules_python",
    sha256 = "a3a6e99f497be089f81ec082882e40246bfd435f52f4e82f37e89449b04573f6",
    strip_prefix = "rules_python-0.10.2",
    url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.10.2.tar.gz",
)

load("@rules_python//python:repositories.bzl", "python_register_toolchains")

python_register_toolchains(
    name = "python3_10",
    # Available versions are listed in @rules_python//python:versions.bzl.
    # We recommend using the same version your team is already standardized on.
    python_version = "3.10",
)


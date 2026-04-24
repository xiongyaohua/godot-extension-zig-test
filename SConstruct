#!/usr/bin/env python
from typing import Any

# Stubs for global injects of scons. Add to silent language server
def Environment(*args: Any, **kwargs: Any) -> Any: ...
def Import(*args: str) -> None: ...
def Export(*args: Any) -> None: ...
def Return(*args: Any) -> None: ...
def SConscript(scripts: Any, exports: Any = ..., variant_dir: Any = ..., duplicate: int = ...) -> Any: ...
def Glob(pattern: str) -> list[Any]: ...
def Default(*targets: Any) -> None: ...

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/cpp/", "zig-out/include/"])
sources = Glob("src/cpp/*.cpp")

if env["target"] in ["editor", "template_debug"]:
    doc_data = env.GodotCPPDocData("src/cpp/gen/doc_data.gen.cpp", source=Glob("docs/doc_classes/*.xml"))
    sources.append(doc_data)

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "godot-project/bin/libgdzig.{}.{}.framework/libgdzig.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "godot-project/bin/libgdzig{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

env.NoCache(library)
Default(library)

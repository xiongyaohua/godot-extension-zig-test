#!/usr/bin/env python
env = SConscript("godot-cpp/SConstruct")
env = env.Clone()

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/cpp/", "zig-out/include/"])
env.Append(LINKFLAGS=["-Wl,-z,noexecstack"])

sources = Glob("src/cpp/*.cpp")

if env["platform"] == "windows":
    zig_lib_name = "libmy_extension.lib"
else:
    zig_lib_name = "libmy_extension.a"

zig_command = (
    "zig build --cache-dir ./.zig-cache --global-cache-dir ./.zig-global-cache"
)
zig_build = env.Command(
    target=f"zig-out/lib/{zig_lib_name}",
    source=[],
    action=zig_command,
)
env.AlwaysBuild(zig_build)
env.Depends(env["LIBS"], zig_build)

# env.Append(LIBPATH=["zig-out/lib/"])
env.Append(LIBS=[zig_build])

if env["target"] in ["editor", "template_debug"]:
    doc_data = env.GodotCPPDocData(
        "src/cpp/gen/doc_data.gen.cpp", source=Glob("docs/doc_classes/*.xml")
    )
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

build-x86:
    scons use_llvm=true compiledb=true target=editor arch=x86_64
build-arm64:
    scons use_llvm=true compiledb=true target=editor arch=arm64
doc:
    (cd godot-project && ~/Code/godot-related/godot/bin/godot.linuxbsd.editor.x86_64 --doctool ../docs/ --gdextension-docs)

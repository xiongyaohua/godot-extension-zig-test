build:
    scons use_llvm=true compiledb=true target=editor platform=macos arch=arm64
doc:
    (cd godot-project && ~/Code/godot-related/godot/bin/godot.linuxbsd.editor.x86_64 --doctool ../docs/ --gdextension-docs)

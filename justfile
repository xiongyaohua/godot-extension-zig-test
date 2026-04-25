build:
    scons use_llvm=true compiledb=true target=editor
doc:
    (cd godot-project && ~/Code/godot-related/godot/bin/godot.linuxbsd.editor.x86_64 --doctool ../docs/ --gdextension-docs)

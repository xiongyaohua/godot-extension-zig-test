#include "gdextension_interface.h"
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "simple.h"

using namespace godot;

void initialize_zig_module(ModuleInitializationLevel p_level);
void uninitialize_zig_module(ModuleInitializationLevel p_level);

extern "C" {
GDExtensionBool GDE_EXPORT
zig_module_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
		GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
			r_initialization);

	init_obj.register_initializer(initialize_zig_module);
	init_obj.register_terminator(uninitialize_zig_module);
	init_obj.set_minimum_library_initialization_level(
			MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}

void initialize_zig_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(SimpleExtension);
}

void uninitialize_zig_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

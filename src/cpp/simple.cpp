#include "simple.h"
#include "godot_cpp/core/class_db.hpp"

void SimpleExtension::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_a"), &SimpleExtension::get_a);
	ClassDB::bind_method(D_METHOD("get_b"), &SimpleExtension::get_b);
	ClassDB::bind_method(D_METHOD("set_a"), &SimpleExtension::set_a);
	ClassDB::bind_method(D_METHOD("set_b"), &SimpleExtension::set_b);
	ClassDB::bind_method(D_METHOD("get_total"), &SimpleExtension::get_total);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "a_value"), "set_a", "get_a");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "b_value"), "set_b", "get_b");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "total_value"), "", "get_total");
}

int32_t SimpleExtension::get_total() const {
	return a + b;
}

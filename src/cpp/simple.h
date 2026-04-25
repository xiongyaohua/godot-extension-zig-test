#include <cstdint>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

class SimpleExtension : public Node {
	GDCLASS(SimpleExtension, Node);

protected:
	static void _bind_methods();
	int32_t a;
	int32_t b;

public:
	SimpleExtension() {
		a = 3;
		b = 5;
	}
	int32_t get_a() const { return a; }
	int32_t get_b() const { return b; }
	void set_a(int32_t p_value) { a = p_value; }
	void set_b(int32_t p_value) { b = p_value; }
	int32_t get_total() const;
};

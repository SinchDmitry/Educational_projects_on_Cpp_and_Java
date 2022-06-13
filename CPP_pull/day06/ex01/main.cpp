#include "Data.hpp"

int	main() {
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr->setData("Letters and words before");
	raw = serialize(ptr);
	new_ptr = deserialize(raw);
	std::cout << "read after reinterpret : " << new_ptr->getData() << std::endl;
}..
#include "IsEven.h"

bool IsEven::operator()(int val) const { 
	return val % 2 == 0; 
}

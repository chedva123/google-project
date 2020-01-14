//#include "OffLine.h"
#include "Online.h"
int main() {
	init();
	std::cout << getMap()["1"][0].first;
	run();
	
	system("pause");
	return 0;
}
	
#include"ourMap.h"
int main() {
	ourMap<int>map;
	for (int i = 0; i < 10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		int value = i + 1;
		map.insert(key, value);
		cout << map.size() << endl;
		cout << map.getloadFactor() << endl;
		cout << map.size() << endl;

		cout << key << ":" << map.getValue(key) << endl;
		cout << map.size() << endl;

	}
}
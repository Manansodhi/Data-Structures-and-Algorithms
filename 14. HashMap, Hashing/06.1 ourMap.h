template<typename V>
class MapNode {
public:
	string key;
	V value;
	MapNode*next;

	MapNode(string key, V value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}

	//for deleting linked list all in one go we need do define Recursive Destructure
	~MapNode() {
		delete next;
	}
};


template<typename V>
class ourMap {
	MapNode<V>**buckets;
	int count, numBuckets;

	int getBucketIndex(string key) {
		int hashcode = 0, currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashcode += key[i] * currentCoeff; //calculatinh hashcode using hash function to string base p
			hashcode = hashcode % numBuckets;
			currentCoeff *= 37; //p-> prime number
			currentCoeff = currentCoeff % numBuckets;
		}
		return hashcode % numBuckets; // compression function
	}

public:
	ourMap() {
		count = 0;
		numBuckets = 5;
		//array of size 5 or esme starting m garbage address pade hoge toh null karmna h becoz voh dangerous hote h
		buckets = new MapNode<V>*[numBuckets];

		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}


	~ourMap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete[] buckets;
	}

	int size() {
		return count;
	}
	double getloadFactor() {
		return (1.0 * count) / numBuckets;
	}

	void rehash() {
		MapNode<V>**temp = buckets;
		buckets = new MapNode<V>*[2 * numBuckets];

		for (int i = 0; i < 2 * numBuckets; i++) {
			buckets[i] = NULL;
		}

		int oldBuketCount = numBuckets;
		numBuckets *= 2;
		count = 0;

		for (int i = 0; i < oldBuketCount; i++) {
			MapNode<V>*head = temp[i];
			while (head != NULL) {
				string key = head->key;
				V value = head->value;
				insert(key, value);
				head = head->nest;
			}
		}

		for (int i = 0; i < oldBuketCount; i++) {
			MapNode<V>*head = temp[i];
		}
		delete head;
		delete[] temp; 1
	}


	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>*head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>*node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
		double loadFactor = (1.0 * count) / numBuckets;
		if (loadFactor > 0.7) {
			rehash();
		}
	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>*head = buckets[bucketIndex];
		MapNode<V>*prev = NULL;

		while (head != NULL) {
			if (head->key = key) {
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;
				}
				else {
					prev->next = head->next;
					V value = head->value;
				} head->next = head;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = haed->next;
		}
		return 0;
	}




	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>*head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

};
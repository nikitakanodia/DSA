// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode { // class for linked list.
    public:
    string key; // to store key of type string
    V value; // to store value of type template
    MapNode* next; // to store the next pointer

    MapNode(string key, V value) { // constructor to assign values
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode() { // Destructor to delete the node.
        delete next;
    }
};

template <typename V>
class ourmap { 
    MapNode<V>** buckets; // a 2D bucket array to store the head pointers of the linked list corresponding to each index.
    int count; // to store the size
    int numBuckets; // to store number of buckets for compression function

    public:

    ourmap() { // constructor: to initialize the values
        count = 0; //
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets]; // dynamically allocated
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL; // assigning each head pointer to NULL
        }
    }

    ~ourmap() { // destructor: to delete the storage used
        for (int i = 0; i < numBuckets; i++) { // first-of-all delete each linked list
            delete buckets[i];
        }
        delete [] buckets; // the delete the total bucket
    }


    private:

    int getBucketIndex(string key) { // to provide the index using hash function
        int hashCode = 0;
        int currentCoeff = 1;
        // using “abcd” = (‘a’ * p3) + (‘b’ * p2) + (‘c’ * p1) + (‘d’ * p0) as our hash code
        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37; // taking p = 37
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>** temp = buckets; // To store the old bucket
        buckets = new MapNode<V>*[2 * numBuckets]; // doubling the size

        for (int i = 0; i < 2*numBuckets; i++) {
            buckets[i] = NULL; // initialising each head pointer to NULL
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2; // updating new size
        count = 0;

        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head != NULL) {
                string key = head->key;
                V value = head->value;
                insert(key, value); // inserting each value of old bucket into the new one
                head = head->next;
            }
        }
        // deleting the old bucket
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp; 
    }

    public:

    int size() { // to return the size of the map
        return count;
    }


    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key); // find the index
        MapNode<V>* head = buckets[bucketIndex]; // head of linked list
        while (head != NULL) {
            if (head->key == key) { // if found, returned the value
                return head->value;
            }
            head = head->next;
        }
        return 0; // if not found, returning 0 as default value.
    }

    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];

        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        // Now we will check the load factor after insertion.
        double loadFactor = (1.0 * count)/numBuckets;
        if (loadFactor > 0.7) {
            rehash(); // We will rehash.
        }
    }
    V remove(string key) {
        int bucketIndex = getBucketIndex(key); // find the index
        MapNode<V>* head = buckets[bucketIndex]; // head node
        MapNode<V>* prev = NULL; // previous pointer

        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) {
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next; // connecting previous to the head’s next pointer
                }
                V value = head->value;
                head->next = NULL; // before calling delete over it, in order to avoid complete linked list deletion, we have to assign it’s next to NULL
                delete head;
                count--; // reducing the size
                return value;// return the value stored at deleted node
            }
                prev = head;
                head = head->next;
        }
        return 0; // means that value not found
    }
};


int main(){
    ourmap<int> map;
    for(int i=0 ; i<10 ; i++){
        char c = '0'+i ; 
        string key = "abc";
        key = key+ c; 
        int value = i+1;
        map.insert(key , value);
        cout<<"load factor : "<< map.getLoadFactor()<<endl;
    }
    cout<<"size : "<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    cout<<"size : "<<map.size()<<endl;
    for(int i=0 ; i<10 ; i++){
        char c='0'+i;
        string key = "abc";
        key = key + c;
        cout<<key<<" : "<< map.getValue(key)<<endl;
    }
    cout<<"size : "<<map.size()<<endl;
}
#include <iostream>
#include <string>
using namespace std;

template <typename v>
class mapnode{
    public :
    string key;
    v value;
    mapnode<v> *next;

    mapnode(string key , v value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapnode(){
        delete next;
    }

};

template <typename v>
class ourmap{
    mapnode<v>** buckets;
    int count;
    int numbuckets;

    public: 
    
    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets= new mapnode<v>*[numbuckets];
        for(int i = 0 ; i < numbuckets; i++){
            buckets[i]=NULL;
        }
    }

    ~ourmap(){
        for(int i=0 ; i<numbuckets ; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    private :
    int getbucketindex(string key){
        int hashcode = 0; 
        int currentcoeff = 1;
        for(int i = key.length()-1 ; i >= 0 ; i--){
            hashcode += key[i] * currentcoeff;
            hashcode = hashcode % numbuckets ;
            currentcoeff *= 37;
            currentcoeff = currentcoeff % numbuckets ;
        }
        return hashcode % numbuckets;
    }  

void rehash(){
        mapnode<v>** temp = buckets;
        buckets = new mapnode<v> *[2*numbuckets];
        for(int i=0 ; i<2*numbuckets ; i++){
            buckets[i]=NULL;
        }

        int oldBucketCount = numbuckets;
        numbuckets *= 2;
        count = 0;
        for(int i=0 ; i<oldBucketCount ; i++){
            mapnode<v> *head = temp[i];
            while (head!=NULL){
                string key = head -> key;
                v value = head->value;
                insert(key , value);
                head = head->next;
            }
        }
        //
        //
        //
        for(int i=0 ; i<oldBucketCount ; i++){
            mapnode<v> *head= temp[i];
            delete head; 
        }
        delete []temp;

    }

    public:

    int size(){
        return count;
    }

    double getloadfactor(){
        return (1.0*count)/numbuckets;
    }

    v getvalue(string key){
        int bucketindex = getbucketindex(key);
        mapnode<v> *head = buckets[bucketindex];
        while (head!=NULL){
            if (head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key , v value){
        int bucketindex = getbucketindex(key);
        mapnode<v> *head = buckets[bucketindex];
        while (head!=NULL){
            if (head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        mapnode<v> * node = new mapnode<v>(key , value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
        double loadfactor = (1.0 * count)/numbuckets;
        if (loadfactor > 0.7){
            rehash();
        }
    }

    v remove(string key){
        int bucketindex = getbucketindex(key);
        mapnode<v>* head = buckets[bucketindex];
        mapnode<v>* prev = NULL;
        while (head != NULL){
            if (head->key == key){
                if (prev == NULL){
                    buckets[bucketindex] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head = head->next;
        }
        return 0;
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
        cout<<"load factor : "<< map.getloadfactor()<<endl;
    }
    cout<<"size : "<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    cout<<"size : "<<map.size()<<endl;
    for(int i=0 ; i<10 ; i++){
        char c='0'+i;
        string key = "abc";
        key = key + c;
        cout<<key<<" : "<< map.getvalue(key)<<endl;
    }
    cout<<"size : "<<map.size()<<endl;
}
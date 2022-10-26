#include <vector>
using namespace std;

// class PriorityQueue{
//     vector<int> pq;

//     public:
//     bool isEmpty(){
//         return pq.size() == 0;
//     }

//     int getSize(){
//         return pq.size();
//     }

//     int getMin(){
//         if (isEmpty()){
//             return 0; //priority queue is empty
//         }
//         return pq.at(0);
//     }
    
//     void insert(int element){
//         pq.push_back(element);
//         int childIndex = pq.size()-1;
//         while (childIndex > 0){

//             int parentIndex = (childIndex-1)/2 ;

//             if (pq[parentIndex] > pq[childIndex]){
//                 int temp = pq[childIndex];
//                 pq[childIndex] = pq[parentIndex];

//                 pq[parentIndex] = temp;
//             }
//             else{
//                 break;
//             }

//             childIndex = parentIndex;
//         }
//     }

//     int removeMin(){
//         int ans = pq[0];
//         pq[0] = pq[pq.size()-1];
//         pq.pop_back();
//         int pi=0;

//         while (pi < pq.size()){
//             int minIndex = pi;
//             int lci = (2*pi) + 1;
//             int rci = (2*pi) + 2;
//             int minimum;
//             if ( lci < pq.size() && rci < pq.size()){
//                 minimum = min( pq[pi] , min(pq[lci] , pq[rci] ) );
//             }
//             if ( lci < pq.size() && rci >= pq.size()){
//                 minimum = min( pq[pi] , pq[lci] );
//             }
//             if ( lci >= pq.size() && rci < pq.size()){
//                 minimum = min( pq[pi] , pq[rci] );
//             }
//             else{
//                 return ans;
//             }

//             if (minimum == pq[lci] ){
//                 minIndex = lci;
//             }
//             if (minimum == pq[rci] ){
//                 minIndex = rci;
//             }
//             if (minIndex!=pi){
//                 int temp = pq[minIndex];
//                 pq[minIndex] = pq[pi];
//                 pq[pi] = temp;
//             }
//             else{
//                 return ans;
//             } 
//             pi = minIndex;
//         }
//     }

// };

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    
    int removeMin(){
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        int lci = (2*pi) + 1;
        int rci = (2*pi) + 2;
        while (lci < pq.size()){
            int minIndex = pi;
            if (pq[minIndex] > pq[lci] ){
                minIndex = lci;
            }
            if (rci < pq.size() && pq[minIndex] > pq[rci] ){
                minIndex = rci;
            }
            if (minIndex!=pi){
                int temp = pq[minIndex];
                pq[minIndex] = pq[pi];
                pq[pi] = temp;
            }
            else{
                break;
            } 
            pi = minIndex;
            int lci = (2*pi) + 1;
            int rci = (2*pi) + 2;        
        }
        return ans;
    }

    // int removeMin(){
    //     int ans = pq[0];
    //     pq[0] = pq[pq.size()-1];
    //     pq.pop_back();
    //     int pi=0;

    //     while (pi < pq.size()){
    //         int minIndex = pi;
    //         int lci = (2*pi) + 1;
    //         int rci = (2*pi) + 2;
    //         int minimum;
    //         if ( lci < pq.size() && rci < pq.size()){
    //             minimum = min( pq[pi] , min(pq[lci] , pq[rci] ) );
    //         }
    //         else if ( lci < pq.size() && rci >= pq.size()){
    //             minimum = min( pq[pi] , pq[lci] );
    //         }
    //         else if ( lci >= pq.size() && rci < pq.size()){
    //             minimum = min( pq[pi] , pq[rci] );
    //         }
    //         else{
    //             return ans;
    //         }

    //         if (lci < pq.size() && minimum == pq[lci] ){
    //             minIndex = lci;
    //         }
    //         else if (rci < pq.size() && minimum == pq[rci] ){
    //             minIndex = rci;
    //         }
    //         if (minIndex!=pi){
    //             int temp = pq[minIndex];
    //             pq[minIndex] = pq[pi];
    //             pq[pi] = temp;
    //         }
    //         else{
    //             return ans;
    //         } 
    //         pi = minIndex;
    //     }
    //     return ans;
    // }
};
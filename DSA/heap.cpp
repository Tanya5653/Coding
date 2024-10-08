#include<iostream>
#include<queue>
using namespace std;
class heap{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }   
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //swapping 1st and last element
        arr[1]=arr[size];
        //removing deleting last element
        size--;

        //take root to correct pos
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }
};
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest= right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
    heapify(arr,size,1);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n =5;

    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing array:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    
    cout<<"printing sorted array:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"USING PRIORITY QUEUE:"<<endl;
    
    priority_queue<int> pq;  //max heap
    
    pq.push(30);
    pq.push(29);
    pq.push(55);
    pq.push(58);

    cout<<"element at top: "<<pq.top()<<endl;

    pq.pop();
    cout<<"element at top: "<<pq.top()<<endl;

    if(pq.empty()){
        cout<<"pq is empty.."<<endl;
    }
    else{
        cout<<"pq is not empty.."<<endl;
    }

    //min heap
    cout<<endl;
    cout<<"PRIORITY QUEUE FOR MIN HEAP"<<endl;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(29);
    minHeap.push(55);
    minHeap.push(58);

    cout<<"element at top: "<<minHeap.top()<<endl;

    return 0;
}
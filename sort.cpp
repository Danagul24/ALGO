#include <iostream>
#include <vector>
using namespace std;

class Maxheap{
    public:
    vector<int>a;
    vector<int>sorted;


    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){
        return 2 * i + 2;
    }

    
    void siftDown(int i){
        if (left(i) > a.size() - 1){
            return;
        }
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] < a[right(i)]){
            j = right(i);
        }
            
        if (a[i] < a[j]){
            swap(a[i], a[j]);
            siftDown(j);
        }
        
    }

    void insert(int num){
        a.push_back(num);
        int i = a.size() - 1;
    }

    void extractMax() {
        sorted.push_back(a[0]);
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        siftDown(0);
    }
    
    void print(){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
};



int main(){
    int n, num;
    cin >> n;
    Maxheap *heap = new Maxheap();
    for (int i = 0; i < n; i++){
        cin >> num;
        heap->insert(num);
    }
    for (int i = n/2 - 1; i >= 0; i--){
        heap->siftDown(i);
    }
    heap->print();
    for (int i = 0; i < n; i++) { 
        heap->extractMax(); 
        cout << endl;
        heap->print(); 
             
    }
    for (int i = n - 1; i >= 0; i--){
        cout << heap->sorted[i] << " ";
    }
    return 0;
    
}
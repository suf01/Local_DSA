#include<bits/stdc++.h>
using namespace std;

//bubble sort B->O(n), W-> O(n^2), O(1)

// B-> O(n), W->O(n^2), O(1)
void insertion_sort(vector<int> &v){
    int n = v.size();

    for(int i = 1; i < n; i++){
        int j = i-1;
        int temp = v[i];

        while(j>=0 && v[j]>temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
}

// B->O(n^2), W->O(n^2), O(1)
void selection_sort(vector<int> &v){
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        int min = i;

        for(int j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(min!=i){
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

// B-> O(n*logn), W->O(n*logn), O(n)
void merge(vector<int> &v, int lo, int mid, int hi){
    int n = v.size();

    int i = lo;
    int j = mid+1; 
    int k = lo;

    vector<int> b(n);

    while(i <= mid && j <= hi){
        if(v[i] <= v[j]){
            b[k] = v[i];
            i++;
            k++;
        }

        if(v[j] < v[i]){
            b[k] = v[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        b[k] = v[i];
        i++;
        k++;
    }
    while(j <= hi){
        b[k] = v[j];
        j++;
        k++;
    }

    for(int i = lo; i <= hi; i++){
        v[i] = b[i];
    }
}

void merge_sort(vector<int> &v, int lo, int hi){
    int n = v.size();

    if(lo < hi){
        int mid = (hi+lo)/2;
        merge_sort(v, lo, mid);
        merge_sort(v, mid+1, hi);
        merge(v, lo, mid, hi);
    }
}

//B->O(n*logn), W->O(n^2), O(logn)
int partition(vector<int> &v, int lo, int hi){
    int pivot = v[lo];
    int i = lo;
    int j = hi;

    while(i < j){
        while(v[i] <= pivot){
            i++;
        }
        while(v[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[j];
    v[j] = v[lo];
    v[lo] = temp;

    return j;
}

void quick_sort(vector<int> &v, int lo, int hi){
    if(lo < hi){
        int pivot = partition(v, lo, hi);
        quick_sort(v, lo, pivot-1);
        quick_sort(v, pivot+1, hi);
    }
}

// B->O(N+k) W->O(N+k) or O(max(N, arr)), O(k)
void count_sort(vector<int> &v){
    int n = v.size();

    int k = 0;
    for(int i = 0; i < n; i++){
        k = max(k, v[i]);
    }

    vector<int> temp(k+1);

    
    for(int i = 0; i < n; i++){
        temp[v[i]]++;
    }

    for(int i = 1; i < temp.size(); i++){
        temp[i] += temp[i-1];
    }

    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        temp[v[i]]--;
        ans[temp[v[i]]] = v[i];
    }

    for(int i = 0; i < n; i++){
        v[i] = ans[i];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    //insertion_sort(v);
    //selection_sort(v);
    //merge_sort(v, 0, n-1);

    quick_sort(v, 0, n-1);

    for(auto it: v){
        cout<<it<<" ";
    }
}

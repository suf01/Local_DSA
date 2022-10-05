void merge(vector<int> &v, int lo, int mid, int hi){
	int i = lo;
	int j = mid+1;

	int k = i;
	int n = v.size();

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
	while(j <= mid){
		b[k] = v[j];
		j++;
		k++;
	}

	for(int l = lo; l <= hi; l++){
		v[l] = b[l];
	}
}

void merge_sort(vector<int> &v, int lo, int hi){
	if(lo < hi){
		int mid = (lo+hi)/2;
		merge_sort(v, lo, mid);
		merge_sort(v, mid+1, hi);

		merge(v, lo, mid, hi);
	}
}

int main(){
	int n;
	cin>>n;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}

	for(auto it: v){
		cout<<it<<" ";
	}
	cout<<endl;
	
	merge_sort(v, 0, n-1);
	for(auto it: v){
		cout<<it<<" ";
	}
}

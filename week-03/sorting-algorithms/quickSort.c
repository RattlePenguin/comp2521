int partition(int A[], int lo, int hi) {
	int pivot = A[lo];

	int l = lo + 1;
	int r = hi;
	while (true) {
		while (l < r && A[l] <= pivot) l++;
		while (l < r && A[r] >= pivot) r--;
		if (l == r) break;
		swap(A, l, r);
	}

	if (pivot < A[l]) l--;
	swap(A, lo, l);
	return l;
}

void merge(int A[], int p, int q, int r){
    int i, j, k, n1 = q - p + 1, n2 = r - q, L[n1], R[n2];
    for(i = 0; i <= n1; i++)
        L[i] = A[p + i - 1];
    for(j = 0; j <= n2; j++)
        R[j] = A[q + j];
    i = 1;
    j = 1;
    for(k = p; k <= r; k++) {
        if(i > n1)
            A[k] = R[j++];
        else if(j > n2)
            A[k] = L[i++];
        else if(L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

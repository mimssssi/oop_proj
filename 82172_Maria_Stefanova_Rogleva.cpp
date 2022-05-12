#include <iostream>
#include <vector>

void swap(unsigned * x, unsigned * y);
void Heapify(unsigned A[], int n, int k);
void HeapSort(unsigned A[], int n);
void output(const unsigned* A, const unsigned* B, size_t n);
unsigned findCurrentTime(const unsigned* A, const unsigned* B, size_t n);
unsigned findMinTime(const unsigned* A, const unsigned* B, size_t n, 
                    unsigned* optA, unsigned* optB);

int main()
{
    unsigned A[] = {7, 9, 3, 2, 11, 5};
    unsigned B[] = {10, 8, 1, 4, 6, 12};

    output(A, B, 6);
    return 0;
}

void swap(unsigned * x, unsigned * y) {
  unsigned z = *x;
  *x = *y;
  *y = z;
}

void Heapify(unsigned A[], int n, int k) {
  // Assumed A[1...n] instead of A[0...n-1].
  int b, q;
  unsigned m, v;
  b = k;
  start:
  q = k << 1; // q = left(k)
  if (q <= n) {
    m = A[k];
    v = A[q];
    if (v > m) {
      b = q;
      m = v;
    }
    ++q; // q = right(k)
    if (q <= n) {
      v = A[q];
      if (v > m) {
        b = q;
        m = v;
      }
    }
  }
  if (b == k)
    return;
  swap(&A[k], &A[b]);
  k = b;
  goto start;
}

void HeapSort(unsigned A[], int n) {
  int k;
  A = &A[-1];  // Replaces A[0...n-1] with A[1...n].
  for (k = n >> 1; k >= 1; --k)
    Heapify(A, n, k);
  k = n;
  while (k >= 2) {
    swap(&A[1], &A[k]);
    --k;
    Heapify(A, k, 1);
  }
}

void output(const unsigned* A, const unsigned* B, size_t n)
{
    std::cout<<"Filling times: \n";
    for(size_t i = 0; i < n; ++i)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<'\n';
    std::cout<<"Bottling times: \n";
    for(size_t i = 0; i < n; ++i)
    {
        std::cout<<B[i]<<" ";
    }
    std::cout<<'\n';
    std::cout<<"Total filling and bottling time in original order: \n";
    std::cout<<findCurrentTime(A, B, n)<<'\n';
    std::cout<<"=================================================================\n";

}

unsigned findCurrentTime(const unsigned* A, const unsigned* B, size_t n)
{
    unsigned* tempA = new unsigned[n];
    unsigned* tempB = new unsigned[n];
    tempA[0] = A[0];
    for(size_t i = 1; i < n; ++i)
    {
        tempA[i] = tempA[i-1] + A[i];
    }

    tempB[n-1] = B[n-1];
    for(size_t i = n-2; i > 0; --i)
    {
        tempB[i] = tempB[i+1] + B[i];
    }
    tempB[0] = tempB[1] + B[0];

    unsigned maxValue = 0;
    for(size_t i = 0; i < n; ++i)
    {
        if(maxValue < (tempB[i] + tempA[i]))
        {
            maxValue = tempB[i] + tempA[i];
        }
    }

    delete[] tempA;
    delete[] tempB;
    return maxValue;
}

unsigned findMinTime(const unsigned* A, const unsigned* B, size_t n, 
                    unsigned* optA, unsigned* optB)
{
    unsigned* sortedA = new unsigned[n];
	unsigned* sortedB = new unsigned[n];
	for(int i = 0; i < n; i++)
	{
		sortedA[i] = A[i];
		sortedB[i] = B[i];
	}
	HeapSort(sortedA, n);
	HeapSort(sortedB, n);

	// Идея - взимаме по-малкото число на позиция 1 в сортираните масиви и ако то идва от 
  //масив А, тази бутилка пращаме най-отпред в нашата оптимална наредба. Ако идва от 
  //масив Б, то тя отива последна в наредбата. Съответният индекс за оптималния масив се
  //коригира и вече не разглеждаме тази бутилка. След това взимаме следващото най-малко 
  //число от масивите А и Б и т.н.
  // Не можах да измисля как да си оправя индексацията на бутилките.

	delete[] sortedA;
	delete[] sortedB;

}
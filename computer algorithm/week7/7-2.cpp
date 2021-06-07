//�����������, ��ͻ����������
//maxheap�̰� ������������
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct Heap {
	int H[MAX];
	int n;
}_Heap;  //�ٵ� �̷����ϸ� �������� �Ǵ°���?

void downHeap(int i) {
	if (i * 2 > _Heap.n) return;
	if (_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2 + 1]) {
		if (_Heap.H[i * 2] > _Heap.H[i * 2 + 1]) {
			int temp;
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2];
			_Heap.H[i * 2] = temp;  //�ٷ�����ֳ�
			downHeap(i * 2);
		}
		else {
			int temp;
			temp = _Heap.H[i];
			_Heap.H[i] = _Heap.H[i * 2 + 1];
			_Heap.H[i * 2 + 1] = temp;  //�ٷ�����ֳ�
			downHeap(i * 2 + 1);
		}
	}
	else return;
}

void buildHeap() {
	for (int i = _Heap.n / 2; i >= 1; i--) {
		downHeap(i);
	}
}

void rBuildHeap(int i) {
	if (i > _Heap.n)
		return;
	if (i * 2 <= _Heap.n)
		rBuildHeap(2 * i);
	if (i * 2+1 <= _Heap.n)
		rBuildHeap(2 * i+1);
	downHeap(i);
}

int removeMax() {
	int key = _Heap.H[1];
	_Heap.H[1] = _Heap.H[_Heap.n--];
	downHeap(1);
	return key;
}
void inPlaceHeapSort() {
	int size = _Heap.n;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMax();
		_Heap.H[_Heap.n + 1] = key;
	}
}

void printHeap() {
	for (int i = 1; i <= _Heap.n; i++) {
		printf("[%d] ", _Heap.H[i]);
	}
	printf("\n");
}

void printArray() {
	for (int i = 1; _Heap.H[i]>0; i++) {
		printf("[%d] ", _Heap.H[i]);
	}
	printf("\n");
}

void main() {
	_Heap.n = 0;
	srand(time(NULL));
	printf("�Է��� ������ ����:");
	scanf("%d", &_Heap.n);
	for (int i = 1; i <= _Heap.n; i++) {
		_Heap.H[i] = rand() % 100 + 1;
	}
	//buildHeap();
	rBuildHeap(1);
	printHeap();

	getchar();
	printf("\n");
	inPlaceHeapSort();
	//n�� 0�̵ɰŴϱ� printHeap���ȵʿ�
	printArray();

}
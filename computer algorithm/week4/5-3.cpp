//shell sort�� inc_insertion sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX 15

void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first+gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -=gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

void main() {
	int list[MAX];
	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++) {
			if (list[i] == list[j])
				i--;
		}
	}
	for (int i = 0; i < MAX; i++)
		printf("%d ", list[i]);
	printf("\n\n");
	getchar();

	//selection_sort(list, MAX);
	shell_sort(list, MAX);
	for (int i = 0; i < MAX; i++) {
		printf("%d ", list[i]);
		Sleep(500);			//��վ�
	}
	printf("\n\n");
}
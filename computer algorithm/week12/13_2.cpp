//그래프 인접리스트로 구현하기
//교수님이 준 엉성코드
//제대로 구현해보기
//이전단원인 hashtable도 잘복습

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Vertex {
	int no;
	int weight;
	struct Vertex* next;
}Vertex;

typedef struct {
	int vCount;
	Vertex* v[N];
}Graph;

void init(Graph* G) {
	G->vCount = 0;
	for (int i = 0; i < N; i++)
		G->v[i] = NULL;
}

void makeVertex(Graph* G) {
	G->vCount++;
}

void insertEdge(Graph* G, int w, int v1, int v2) {
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->weight = w;
	p->no = v1 + 1;
	p->next = G->v[v2];
	G->v[v2] = p;

	Vertex* q = (Vertex*)malloc(sizeof(Vertex));
	q->weight = w;
	q->no = v2 + 1;
	q->next = G->v[v1];
	G->v[v1] = q;//linkedlist로 연결된 접점리스트의head에 q추가하기
}

void print(Graph* G) {
	for (int i = 0; i < G->vCount; i++) {
		Vertex* v = G->v[i];
		printf("V[%d]: ", i + 1);
		while (v != NULL) {
			printf("[%d (%d)] ", v->no, v->weight);
			v = v->next;
		}
		printf("\n");
	}
}

void process(Graph* G, int num) {	//특정vertex에 연결된 vertex들 나열
	Vertex* p = G->v[num-1];
	while (p != NULL) {
		printf("[%d (%d)] ", p->no, p->weight);
		p = p->next;
	}
	printf("\n");
}

void process2(Graph* G, int v1, int v2, int w) {	//가중치수정하기
	Vertex* p = G->v[v1];
	while (p != NULL) {
		if (p->no == v2 - 1) {
			p->weight = w;
			return;
		}
		else
			p = p->next;
	}
}

int main() {
	Graph* G;
	G = (Graph*)malloc(sizeof(Graph));
	init(G);
	for (int i = 0; i < 6; i++)
		makeVertex(G);

	insertEdge(G, 1, 0, 1);	//가중치, vertex1, vertex2
	insertEdge(G, 1, 0, 2);
	insertEdge(G, 1, 0, 3);
	insertEdge(G, 2, 0, 5);
	insertEdge(G, 1, 1, 2);
	insertEdge(G, 4, 2, 4);
	insertEdge(G, 3, 4, 5);

	print(G);

	process(G, 1);
}
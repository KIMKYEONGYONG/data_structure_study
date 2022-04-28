#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_SIZE 20
#define X_SIZE 4
#define Y_SIZE 5

typedef struct Mouse
{
	short x;
	short y;
}Mouse;

typedef struct Stack
{
	Mouse data[MAX_SIZE];
	int top;
}Stack;

char maze[X_SIZE][Y_SIZE] = {
	{ '1', '0', '1', '1', '1' },
	{ '1', '0', '0', '0', '0' },
	{ '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '1', '1' }
};

void init(Stack *p){
	p->top = -1;
}

int is_full(Stack *p){
	return (p->top == MAX_SIZE - 1);
}

int my_empty(Stack *p){
	return (p->top == -1);
}

void push(Stack *p, Mouse data){
	if (is_full(p))
	{
		cout << "스택이 꽉 찼습니다 \n";
		return;
	}
	else{
		p->top++;
		p->data[p->top].x = data.x;
		p->data[p->top].y = data.y;
	}
}

Mouse pop(Stack *p){
	if (my_empty(p)){
		cout << "스택이 비었습니다 \n";
		exit(1);
	}
	return p->data[(p->top)--];
}

void FindWay(Stack *s, int x, int y){
	if (x < 0 || y < 0 || x > X_SIZE || y > Y_SIZE) return;

	if (maze[x][y] != '1' && maze[x][y] != '#'){
		Mouse tmp;
		tmp.x = x;
		tmp.y = y;

		push(s, tmp);
	}
}

int main()
{
	Stack s;
	Mouse m;
	int x, y;
	init(&s);

	// 시작점
	m.x = 0;
	m.y = 1;

	cout << "미로 \n";
	for (int i = 0; i < X_SIZE; i++){
		for (int j = 0; j < Y_SIZE; j++){
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n이동경로 \n";
	cout << "시작 (" << m.x << "," << m.y << ") ";

	while (true){
		x = m.x;
		y = m.y;

		maze[x][y] = '#';

		FindWay(&s, x + 1, y);
		FindWay(&s, x - 1, y);
		FindWay(&s, x, y + 1);
		FindWay(&s, x, y - 1);

		// 도착점
		if (x == 1 && y == 4){
			break;
		}

		if (my_empty(&s)){
			cout << "이동경로를 찾을 수 없습니다. 실패 \n";
		}
		else{
			m = pop(&s);
			cout << "(" << m.x << "," << m.y << ") ";
		}



	}

	cout << "도착\n";
	cout << "탐색 성공\n\n\n";


	for (int i = 0; i < X_SIZE; i++){
		for (int j = 0; j < Y_SIZE; j++){
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

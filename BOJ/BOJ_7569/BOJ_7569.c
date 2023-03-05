#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int basket[100][100][100] = { 0, };
int queue[1000000][3] = { 0, };
int xx[6] = { 1,-1,0,0,0,0 };
int yy[6] = { 0,0,1,-1,0,0 };
int zz[6] = { 0,0,0,0,1,-1 };
int head = 0;
int tail = 0;

int main(void) {
	int tomato, M, N, H, x, y, z;
	int maximum = 0;
	int rotten = 0;

	scanf("%d %d %d", &M, &N, &H);

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &tomato);

				basket[i][j][k] = tomato;

				if (tomato == 1) {
					queue[tail][0] = i;
					queue[tail][1] = j;
					queue[tail][2] = k;
					tail++;
				}
			}
		}
	}

	while (head < tail) {
		x = queue[head][0];
		y = queue[head][1];
		z = queue[head][2];
		head++;

		for (int i = 0; i < 6; i++) {
			if (x + xx[i] < N && x + xx[i] > -1 && y + yy[i] < M && y + yy[i] > -1 && z + zz[i] < H && z + zz[i] > -1 && basket[x + xx[i]][y + yy[i]][z + zz[i]] == 0) {
				basket[x + xx[i]][y + yy[i]][z + zz[i]] = basket[x][y][z] + 1;
				queue[tail][0] = x + xx[i];
				queue[tail][1] = y + yy[i];
				queue[tail][2] = z + zz[i];
				tail++;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				maximum = MAX(maximum, basket[i][j][k]);

				if (basket[i][j][k] == 0) {
					rotten = -1;
				}
			}
		}
	}

	if (rotten == -1) {
		printf("%d", rotten);
	}
	else {
		printf("%d", maximum - 1);
	}

	return 0;
}
// 'A'의 아스키코드 번호는 65이다. 'Z'의 아스키코드 번호는 90이다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
static bool visited[26];
static char board[20][20];
static int n, m;
static int dy[] = { 0, 0, 1, -1 };
static int dx[] = { 1, -1, 0, 0 };
static int max_cnt = 0;

void ClearBuffer()
{
	while (getchar() != '\n');
}

void dfs(int y, int x, int cnt)
{
	if (max_cnt < cnt)
	{
		max_cnt = cnt;
	}
	char alphabet = board[y][x];
	visited[alphabet - 65] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if ((0 <= ny)&&(ny < n)&&(0 <= nx)&&(nx<m)&&(!visited[board[ny][nx] - 65]))
		{
			dfs(ny, nx, cnt + 1);
		}
	}
	visited[alphabet - 65] = false;
}

int main()
{
	for (int i = 0; i < 26; i++)
	{
		visited[i] = 0;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		ClearBuffer();
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &board[i][j]);
		}
	}
	dfs(0, 0, 1);
	printf("%d", max_cnt);
	return 0;
}
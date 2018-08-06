#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N; //��ǻ�� ����
int k; //���� ����

queue<int> q;
bool visit[101];
int main(void)
{
	vector<int> v[101]; // ��ǻ�� ����
	cin >> N;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	}

	int cnt = 0; //���̷����� �ɸ� ����
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		for (int i = 0; i < v[value].size(); i++)
		{
			if (!visit[v[value][i]])
			{
				visit[v[value][i]] = true;
				q.push(v[value][i]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
#include <iostream>

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u: adj[s]) {
		dfs(u);
	}
}

int main(){
	int N;
	std::cin >> N;
	int pulau[N];
	int jembatan[N][N];
	bool visited[N][N];
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			std::cin >> jembatan[i][j];
		}
	}
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (jembatan[i][j] == 1){
				visited[i][j] = true;
			} else if (jembatan[i][j]== 0){
				visited[i][j] = false;
			}
		}
	}
	
}

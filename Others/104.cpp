#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > table;

int main() {
	int f, v;
	cin >> f >> v;
	table = vector<vector<int> >(f, vector<int>(v));
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < v; ++j) {
			cin >> table[i][j];
		}
	}
	vector<vector<vector<int> > > vases(2, vector<vector<int> >(v + 1, vector<int>(f)));
	vector<vector<int> > value(2, vector<int>(v + 1));
	value[0][0] = 0;
	for (int i = 0; i <= f; ++i) {
		if (i > 0) value[i % 2][i] = value[(i - 1) % 2][i - 1] + table[i - 1][i - 1];
		for (int j = i + 1; j <= v; ++j) {
			if (i == 0 || j == 0) {
				value[i % 2][j] = 0;
				continue;
			}
			if (value[i % 2][j - 1] >= value[(i - 1) % 2][j - 1] + table[i - 1][j - 1]) {
				value[i % 2][j] = value[i % 2][j - 1];
				vases[i % 2][j] = vases[i % 2][j - 1];
			}
			else {
				value[i % 2][j] = value[(i - 1) % 2][j - 1] + table[i - 1][j - 1];
				vases[i % 2][j] = vases[(i - 1) % 2][j - 1];
				vases[i % 2][j][i - 1] = j;
			}
		}
	}
	cout << value[f % 2][v] << endl;
	for (int i = 0; i < f; ++i) {
		cout << vases[f % 2][v][i] << " ";
	}
	cout << endl;
	return 0;
}
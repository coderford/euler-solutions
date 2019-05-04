/*
The minimal path sum in the 5 by 5 matrix below, by starting in any cell in 
the left column and finishing in any cell in the right column, and only moving 
up, down, and right, is indicated in red and bold; the sum is equal to 994.

			131,673,234,103,018
			201,096,342,965,150
			630,803,746,422,111
			537,699,497,121,956
			805,732,524,037,331

Find the minimal path sum, in p082_matrix.txt, a 31K text file containing a 80 
by 80 matrix, from the left column to the right column
*/
#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vvl getInput(istream &in) {
	// reads a matrix from given input stream 
	// Each row is a line containing comma separated values
	// No need to specify size of matrix
	vvl result;
	string line;
	getline(in, line);
	while(!in.eof() && line != "") {
		result.push_back(vl());
		istringstream s(line);
		long tmp;
		s>>tmp;
		while(!s.fail()) {
			result[result.size()-1].push_back(tmp);
			s.ignore(10, ',');
			s>>tmp;
		}
		getline(in, line);
	}
	return result;
}

bool isValid(int i, int j, int n, int m) {
	if(i < 0 || i >= n) return false;
	if(j < 0 || j >= m) return false;
	return true;
}

vvl grid, up, down, lft;
vvb seen;

long getDist(int i, int j) {
	seen[i][j] = true;
	int n = grid.size(), m = grid[0].size();
	long u = INF, d = INF, l = INF;

	// dist from up
	if(isValid(i-1, j, n, m)) {
		if(up[i][j] < 0)  {
			if(!seen[i-1][j]) {
				up[i][j] = getDist(i-1, j) + grid[i][j];	
				u = up[i][j];
			}
		}
		else u = up[i][j];
	}

	// from lft
	if(isValid(i, j-1, n, m)) {
		if(lft[i][j] < 0)  {
			if(!seen[i][j-1]) {
				lft[i][j] = getDist(i, j-1) + grid[i][j];	
				l = lft[i][j];
			}
		}
		else l = lft[i][j];
	}

	// from down
	if(isValid(i+1, j, n, m)) {
		if(down[i][j] < 0)  {
			if(!seen[i+1][j]) {
				down[i][j] = getDist(i+1, j) + grid[i][j];	
				d = down[i][j];
			}
		}
		else d = down[i][j];
	}

	seen[i][j] = false;
	return min(u, min(d, l));
}

int main(int argc, char *argv[]) {
	ifstream in;
	if(argc < 2) {
		cout<<"Pass matrix filename as argument!\n";
		return 0;
	}
	else {
		in.open(argv[1]);
		if(in.fail()) {
			cout<<"Could not open specified file!\n";
			return 1;
		}
	}
	// read matrix from file
	grid = getInput(in); in.close();
	int n = grid.size(), m = grid[0].size();
	cout<<"Got "<<n<<"x"<<m<<" matrix...\n";
	
	// these store the minimum distance when approached from up, down and lft
	up.assign(n, vl(m, -1));
	down.assign(n, vl(m, -1));
	lft.assign(n, vl(m, -1));
	
	// this seen/visited matrix is used to avoid going in a cycle
	seen.assign(n, vb(m, false));

	// the min distance for all in first column is the value already present
	for(int i = 0; i < n; i++)
		up[i][0] = down[i][0] = lft[i][0] = grid[i][0];
	
	// find min dist for all elements in rightmost column
	long mindist = INF;
	for(int i = 0; i < n; i++) {
		long d = getDist(i, m-1);
		if(d < mindist) mindist = d;
	}
	
	cout<<"Minimum sum is "<<mindist<<'\n';
	return 0;
}

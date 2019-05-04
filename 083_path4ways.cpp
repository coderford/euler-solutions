/*
Same question as 81, but now four directional movement is allowed...
Solution is a simple extension of the one for problem 82...
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

vvl grid, up, down, lft, rt;
vvb seen;

long getDist(int i, int j) {
	seen[i][j] = true;
	int n = grid.size(), m = grid[0].size();
	long u = INF, d = INF, l = INF, r = INF;

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

	// from left
	if(isValid(i, j-1, n, m)) {
		if(lft[i][j] < 0)  {
			if(!seen[i][j-1]) {
				lft[i][j] = getDist(i, j-1) + grid[i][j];	
				l = lft[i][j];
			}
		}
		else l = lft[i][j];
	}

	// from right
	if(isValid(i, j+1, n, m)) {
		if(rt[i][j] < 0)  {
			if(!seen[i][j+1]) {
				rt[i][j] = getDist(i, j+1) + grid[i][j];	
				r = rt[i][j];
			}
		}
		else r = rt[i][j];
	}

	seen[i][j] = false;
	return min(u, min(d, min(l, r)));
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
	
	// these store the minimum distance when approached from each direction
	up.assign(n, vl(m, -1));
	down.assign(n, vl(m, -1));
	lft.assign(n, vl(m, -1));
	rt.assign(n, vl(m, -1));
	
	// this seen/visited matrix is used to avoid going in a cycle
	seen.assign(n, vb(m, false));

	// the min distance for top left element is the value already present
	up[0][0] = down[0][0] = lft[0][0] = rt[0][0] = grid[0][0];
	
	// find min dist for bottom right element;
	cout<<"Minimum sum is "<<getDist(n-1, m-1)<<'\n';
	return 0;
}

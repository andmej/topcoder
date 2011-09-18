#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

template <class T> string toStr(const T &x){
stringstream s; s << x; return s.str();
}

template <class T> int toInt(const T &x){
stringstream s; s << x; int r; s >> r; return r;
}

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cerr << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y, double tol = EPS){
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void test(string s){
  int x = 1, y = 1;
  printf("x = %d, y = %d\n", x, y);
  for (int i = 0; i < s.size(); ++i){
    if (s[i] == 'X'){
      x = x + y;
    }else y = x + y;
    printf("[%c] x = %d, y = %d\n", s[i], x, y);
  }
}

int f(int a, int b){
  if (a > b) swap(a, b);
  assert(a <= b);
  assert(a > 1);
  int ans = 0;
  while (true){
    if (a == 0){
      return INT_MAX;
    }
    if (a == 1){
      ans += b - 1 ;
      break;
    }

    ans += b / a;
    b = b % a;
    swap(a, b);
  }
  return ans;
}

string build(int x, int y){
  string ans = "";
  while (true){
    if (x == 1 and y == 1) break;
    assert(x != y);
    if (x > y){
      x = x - y;
      ans += 'X';
    }else{
      y = y - x;
      ans += "Y";
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

class TwoRegisters {
	public:
	string minProg(int r) {
	  if (r == 1) return "";
	  int ans = r - 1;
	  string s(r - 1, 'X');

	  for (int p = 2; p <= 1000000; ++p){
	    int k = f(r, p);
	    if (k < ans){
	      ans = k;
	      s = build(r, p);
	    }else if(k == ans){
	      string t = build(r, p);
	      if (t < s) s = t;
	    }
	  }
	  //test(s);
	  return s;
	}
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arg1 = "XXYYX"; verify_case(0, Arg1, minProg(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "XX"; verify_case(1, Arg1, minProg(Arg0)); }
	void test_case_2() { int Arg0 = 20; string Arg1 = "XYYYYXX"; verify_case(2, Arg1, minProg(Arg0)); }
	void test_case_3() { int Arg0 = 34; string Arg1 = "XYXYXYX"; verify_case(3, Arg1, minProg(Arg0)); }

// END CUT HERE
                     
};

// BEGIN CUT HERE

int main(){
    TwoRegisters ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

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
#define D(x) cout << #x " = " << (x) << endl


class EqualizeStrings {
	public:
	string getEq(string s, string t) {
	  string ans = "";
	  for (int i = 0; i < s.size(); ++i){
	    int x = s[i] - 'a', y = t[i] - 'a';
	    if (x > y) swap(x, y);
	    assert(x <= y);
	    char add;
	    if (y - x < 26 - (y - x)){
	      add = x;
	    }else{
	      add = 0;
	    }
	    add += 'a';
	    ans += add;
	  }
	  return ans;
	}

 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cat"; string Arg1 = "dog"; string Arg2 = "caa"; verify_case(0, Arg2, getEq(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "bcdefghijklmnopqrstuvwxyza"; string Arg2 = "abcdefghijklmnopqrstuvwxya"; verify_case(1, Arg2, getEq(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "programmingcompetitionsrule"; string Arg1 = "programmingcompetitionsrule"; string Arg2 = "programmingcompetitionsrule"; verify_case(2, Arg2, getEq(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoderopen"; string Arg1 = "onlinerounds"; string Arg2 = "onlcndaoondn"; verify_case(3, Arg2, getEq(Arg0, Arg1)); }

// END CUT HERE
                     
};

// BEGIN CUT HERE
int main(){
EqualizeStrings ___test;
___test.run_test(-1);
return 0;
}
// END CUT HERE

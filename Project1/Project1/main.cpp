

/*
//깊이너비 dfs bfs 여행경로
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	unordered_map<string, vector<string>> routes;

	for (int i = 0; i < tickets.size(); i++)
	{
		routes[tickets[i][0]].push_back(tickets[i][1]);
	}

	vector<string> s = vector<string>{ "ICN" };

	while (!s.empty())
	{
		string airport = s.back();
		if (routes.find(airport) == routes.end()
			|| routes[airport].size() == 0)
		{
			answer.push_back(airport);
			s.pop_back();
		}
		else
		{
			s.push_back(routes[airport].back());
			routes[airport].pop_back();
		}
	}

	reverse(answer.begin(), answer.end());
	return answer;
}


void main()
{
	vector<vector<string>> tickets = { {"ICN","SFO"},{"ICN","ATL"},{"SFO","ATL"},{"ATL","ICN"},{"ATL","SFO"} };
	vector<string> result = solution(tickets);



	return;
}

*/

/*
//동적계획법 dynamic programming n으로표현
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	int answer = -1;
	unordered_set<int> s[8];
	int base = 0;

	//기본적인 5 55 555 5555 등.
	for (int i = 0; i < 8; i++)
	{
		base = 10 * base + 1;
		s[i].insert(base * N);
	}

	//5랑 55,555,555 제외.
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (auto& op1 : s[j])
			{
				for (auto& op2 : s[i - j - 1])
				{
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if(op2 != 0) s[i].insert(op1 / op2);
				}
			}
		}

		//만들고자 하는 수가 들어있으면.
		if (s[i].count(number) > 0)
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}

int main()
{

	cout << solution(5, 12) << endl;

	return 0;
}

*/

/*
//힙 더 맵게
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (auto& i : scoville)
	{
		q.push(i);
	}

	while (1)
	{
		int min1 = q.top();
		q.pop();

		if (min1>= K)
		{
			break;
		}
		else if (q.empty())
		{
			answer = -1;
			break;
		}

		int min2 = q.top();
		q.pop();
		q.push(min1 + 2 * min2);
		answer++;
	}

	return answer;
}

////내가한거.
//bool normal = true;
//
//bool cmp(int _left, int _right)
//{
//	return _left > _right;
//}
//
//bool ifif(vector<int>& scoville, int K)
//{
//	if (scoville.size() > 1)
//	{
//		sort(scoville.begin(), scoville.end(), cmp);
//		if (scoville[scoville.size() - 1] >= K)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	else
//	{
//		normal = false;
//		return false;
//	}
//
//	return true;
//}
//
//int solution(vector<int> scoville, int K) {
//	int answer = 0;
//	int mix = 0;
//	int first = 0;
//	int second = 0;
//
//	while (ifif(scoville, K))
//	{
//		first = scoville[scoville.size()-1];
//		scoville.pop_back();
//		second = scoville[scoville.size() - 1];
//		scoville.pop_back();
//
//		mix = first + (second * 2);
//		scoville.push_back(mix);
//
//		answer++;
//	}
//
//	return (normal) ? answer : -1;
//}

void main()
{
	//int n = 5;
	//vector<int> lost = { 3, 30, 34, 5, 9 };
	//string str = "4177252841";
	vector<int> v = { 1, 2, 3, 9, 10, 12 };
	int k = 7;
	cout << solution(v, k) << endl;

}

*/

/*

//큰 수 만들기 greedy 탐욕법
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	for (int i = 0; i < number.size(); i++)
	{
		while(!answer.empty() && answer.back() < number[i] && k > 0)
		{
			answer.pop_back();
			k--;
		}

		if(k == 0)
		{
			answer += (number.substr(i, number.size() - i));
			break;
		}

		answer.push_back(number[i]);
	}

	return answer.substr(0, answer.length() - k);
}

void main()
{
	//int n = 5;
	//vector<int> lost = { 3, 30, 34, 5, 9 };
	vector<int> v;
	string str = "4177252841";
	int k = 4;
	cout << solution(str, k) << endl;

}
*/

/*
//90도 회전 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//vector<vector<int>> origin = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<vector<int>> origin = { {1,2,3,4,5}
									,{6,7,8,9,10}
									,{11,12,13,14,15}
									,{16,17,18,19,20}
									,{21,22,23,24,25} };
	int size = origin.size();
	vector<vector<int>> temp(size, vector<int>(size, 0));

	for (vector<int> _vec : origin)
	{
		for (int _int : _vec)
		{
			printf("%3d", _int);
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//temp[j][size - i - 1] = origin[i][j];	//시계방향 90도
			temp[size - j - 1][i] = origin[i][j];	//반시계 90도
		}
	}

	for (vector<int> _vec : temp)
	{
		for (int _int : _vec)
		{
			printf("%3d", _int);
		}

		cout << endl;
	}

	return 0;
}


*/


/////////////////////////////////////////////////////////////////////////////////kongStudio

/*

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// Template for C++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> memo;//numsVal(필요한숫자), index

		for (int i = 0; i < nums.size(); i++)
		{
			//현재 nums[i]는 타겟이 되려면 target-nums[i]가 필요한데 있나요?
			if (memo.count(target - nums[i]))
			{
				//있어요?
				return { memo[target - nums[i]], i };
			}
			else
			{
				//없으면 뒤에 필요할지 모르니 저장. 필요한 수를 키값으로.
				memo[nums[i]] = i;
			}
		}

		return {};
	}
};


int main()
{
	vector<int> a = { 2, 7, 11, 15 };
	vector<int> result;
	Solution* s = new Solution();

	result = s->twoSum(a, 9);

	for (int _r : result)
	{
		cout << _r;
	}

	return 0;
}


*/


/*
#include <iostream>
#include <stack>
#include <string>

using namespace std;


// Template for C++
class Queue {
public:
	stack<int> _mainStack;
	stack<int> _subStack;

	// Push element x to the back of queue.
	void push(int x) {
		while (_mainStack.size()>0)
		{
			_subStack.push(_mainStack.top());
			_mainStack.pop();
		}

		//방금온게 제일 밑으로.
		_mainStack.push(x);

		//위에다 다시 쌓기.

		while (_subStack.size() > 0)
		{
			_mainStack.push(_subStack.top());
			_subStack.pop();
		}

	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (_mainStack.size() > 0)
		{
			_mainStack.pop();
		}
		else
		{
			cout << "empty" << endl;
		}
	}

	// Get the front element.
	int peek(void) {
		return _mainStack.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (_mainStack.size() == 0) ? true : false;
	}
};

int main()
{
	Queue* q = new Queue();
	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	q->push(5);
	cout << to_string(q->empty()) << endl;
	cout << q->peek() << endl;
	q->push(6);
	cout << q->peek() << endl;
	q->pop();
	cout << q->peek() << endl;
	q->pop();
	cout << q->peek() << endl;
	q->pop();
	cout << q->peek() << endl;
	q->pop();
	cout << q->peek() << endl;
	q->pop();
	q->pop();
	q->pop();
	cout << to_string(q->empty()) << endl;

	q->pop();
	return 0;
}

//_mainStack에 들어있던것을 _subStack에 그대로 엎어서 넣고-> 비어있는 _mainStack에 새로 추가할 요소 넣고 다시 _subStack에서 메인으로
//결론은 새로들어온 숫자가 스택에서 맨 마지막에 나갈수 있도록 해주는 방법으로 스택2개를 사용하였습니다.



*/


/*
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		if (digits.size() == 0)
		{
			return digits;
		}

		digits[digits.size() - 1]++;

		//vector 요소 하나에 한자리수만 들어가므로 맨끝이 두자리가 되었다면, 자릿수 체크를 시작합니다.
		if (digits[digits.size() - 1] > 9)
		{
			for (int i = digits.size() - 1; i >= 0; i--)
			{
				if (digits[i] > 9)
				{
					digits[i] %= 10;

					if (i == 0)
					{
						digits.insert(digits.begin(), 1);
					}
					else
					{
						digits[i - 1]++;
					}
				}
				else
				{
					break;
				}
			}
		}

		return digits;
	}

};

int main()
{
	vector<int> a = { 9, 9, 9, 9 };
	vector<int> result;
	Solution* s = new Solution();

	result = s->plusOne(a);

	for (int _r : result)
	{
		cout << _r;
	}


	return 0;
}




*/

/*
#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution
{
public:
	string reverseVowels(string s) {

		//모음만 따로 빼서 스택에다 저장해 둔 뒤 다음번 순회 에서, 모음이 나올때 스택에서 꺼내 덮어씌었습니다.
		stack<char> _stack;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o'
				|| s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O')
			{
				_stack.push(s[i]);
			}
		}

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o'
				|| s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O')
			{
				s[i] = _stack.top();
				_stack.pop();
			}
		}

		return s;

	}

};

int main()
{
	Solution* s = new Solution();
	cout << s->reverseVowels("hEllo") << endl;


	return 0;
}


*/


/*
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
	map<int, int> memo;

	int Fibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}
		else if (memo[n] != 0)
		{
			return memo[n];
		}
		else
		{
			return memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
		}
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->Fibonacci(10) << endl;
	return 0;
}


//해당값에 대해 기억해뒀다가 이미 계산했던 이력이있는 값들은 재귀를 통하여 또한번 계산하는 행위를 방지합니다.

*/
/////////////////////////////////////////////////////////////////////////////////kongStudio



/*

string solution(int _i)
{

	string str = "123";
	int s = 3;
	cout << str[1] << endl;
	str += to_string(s);
	cout << str << endl;

	return str;


}


int main()
{
	cout << solution(5) << endl;

	return 0;
}
*/


/*

#include <iostream>
#include <string>
using namespace std;

void printReverse(string str)
{
	// Print first word
	int i = 0;
	for (i = 0; i < str.length() && str[i] != ' '; i++)
		cout << str[i];

	// Print middle words
	string word = "";
	for (; i < str.length(); i++) {

		if (str[i] != ' ')
			word += str[i];
		else {
			reverse(word.begin(), word.end());

			cout << word << " ";
			word = "";
		}
	}

	// Print last word
	cout << word << " ";
}

int main()
{
	string str = "Hi how are you geeks";
	printReverse(str);
	return 0;
}

*/


/*
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
	map<int, int> memo;

	int Fibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}
		else if (memo[n] != 0)
		{
			return memo[n];
		}
		else
		{
			return memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
		}
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->Fibonacci(10) << endl;
	return 0;
}


//해당값에 대해 기억해뒀다가 이미 계산했던 이력이있는 값들은 재귀를 통하여 또한번 계산하는 행위를 방지합니다.

*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void Add(char* _cArrLeft, char* _cArrRight)
{
	for (int i = 0; i < 1024; ++i)
	{
		_cArrRight[i] = _cArrLeft[i] + _cArrRight[i];

		//한자릿수가 10이 넘어가는지 체크
		NumberCheck(_cArrRight, i);
	}
}

void NumberCheck(char* _cArrRight, int _idx)
{
	//한자릿수가 10이 넘어가면?
	if (_cArrRight[_idx] >= 10)
	{
		int iAddIdx = _idx + 1;
		_cArrRight[_idx] %= 10;
		_cArrRight[iAddIdx] += 1;

		//혹시 다음자리도 10이상인지 검사; 재귀함수 사용
		NumberCheck(_cArrRight, iAddIdx);
	}

}


int main()
{
	char cArrLeft[1024] = { 0 };
	char cArrRight[1024] = { 0 };
	char cArrResult[1024] = { 0 };

	int iCalCnt = 1;
	int iMaxFibonacciCnt = 1000;

	//Left & Right Init
	cArrLeft[0] = 0;
	cArrRight[0] = 1;

	//계산
	while (1)
	{
		//오른쪽 항에 들어갈 피보나치수 만들기
		Add(cArrLeft, cArrRight);

		iCalCnt++;
		if (iCalCnt == iMaxFibonacciCnt)
		{
			break;
		}
	}


	bool bContinueControl = false;

	for (int i = 1023; i >= 0; --i)
	{
		if (cArrResult[i] == 0 && false == bContinueControl)
		{
			continue;
		}
		printf("%d", cArrResult[i]);
		bContinueControl = true;
	}

	printf("\n");


	return 0;
}



*/

























































//그리디 체육복
/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	unordered_set<int> l(lost.begin(), lost.end());//잃어버린애들.
	set<int> r;	//여분얘들.
	unordered_set<int> inter;//교집합 잃어버린얘들+여분얘들

	for (auto& x : reserve)
	{
		if (l.find(x) == l.end())
		{
			//잃어버린 목록에 없다.
			//여분얘들 추가.
			r.insert(x);
		}
		else
		{
			//잃어버린 목록에 있다.
			//무효 목록에 저장.
			inter.insert(x);
		}
	}

	//무효목록에서 잃어버린얘들+여분얘들
	for (auto& x : inter)
	{
		//잃어버린 목록에서 제거.
		l.erase(x);
	}

	for (auto& x : r)
	{
		if (l.find(x - 1) != l.end())
		{
			l.erase(x - 1);
		}
		else if (l.find(x + 1) != l.end())
		{
			l.erase(x + 1);
		}
	}

	return n - l.size();
}

void main()
{
	int n = 5;
	vector<int> lost = { 2,4 };
	vector<int> reserve = { 1,3,5 };

	cout << solution(n, lost, reserve) << endl;

}
*/
/*

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> u(n + 2, 1);

	for (int i = 0; i < reserve.size(); i++)
	{
		u[reserve[i]]++;
	}
	for (int i = 0; i < lost.size(); i++)
	{
		u[lost[i]]--;
	}
	for (int i = 1; i <= n; i++)
	{
		if (u[i - 1] == 0 && u[i] == 2)
		{
			u[i - 1] = u[i] = 1;
		}
		else if (u[i] == 2 && u[i + 1] == 0)
		{
			u[i] = u[i + 1] = 1;
		}

	}

	for (int i = 1; i <= n; i++)
	{
		if (u[i] > 0)
		{
			answer++;
		}
	}

	return answer;
}

void main()
{
	int n = 5;
	vector<int> lost = { 2,4 };
	vector<int> reserve = { 1,3,5 };

	cout << solution(n, lost, reserve) << endl;

}*/
/*
#include <iostream>


#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i : reserve) student[i] += 1;
	for (int i : lost) student[i] += -1;
	for (int i = 1; i <= n; i++) {
		if (student[i] == -1) {
			if (student[i - 1] == 1)
				student[i - 1] = student[i] = 0;
			else if (student[i + 1] == 1)
				student[i] = student[i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (student[i] != -1) answer++;

	return answer;
}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//	int answer = 0;
//
//
//	vector<int> total;
//	total.assign(5, 1);
//
//	for (int _r : reserve)
//	{
//		total[_r-1] = 2;
//	}
//
//	for (int _l : lost)
//	{
//		total[_l - 1] = 0;
//	}
//
//	for (int i = 0; i < total.size(); i++)
//	{
//		if (total[i] == 0)
//		{
//			if (i > 0 && total[i - 1] == 2)
//			{
//				total[i - 1]--;
//				total[i]++;
//			}
//			else if (i < total.size() - 1 && total[i + 1] == 2)
//			{
//				total[i + 1]--;
//				total[i]++;
//			}
//		}
//	}
//
//	for (int _t : total)
//	{
//		if (_t == 1 || _t == 2)
//		{
//			answer++;
//		}
//	}
//
//
//
//	return answer;
//}

void main()
{
	int n = 5;
	vector<int> lost = {2,4};
	vector<int> reserve = {1,3,5};

	cout << solution(n, lost, reserve) << endl;

}


//5 [2, 4][1, 3, 5]	5
//5 [2, 4][3]		4
//3 [3]	  [1]		2


*/




















//이분탐색 입국심사
/*
#include <iostream>


//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int n, vector<int> times) {
//	long long answer = 0;
//
//	vector<long long> expectTime;
//	expectTime.assign(times.size(), 0);
//
//
//	//for (int i = 0; i < times.size(); i++)
//	//{
//	//	expectTime.push_back(times[i]);
//	//}
//
//
//	int min = 0;
//	int minIdx = 0;
//
//	for (int i = 0; i < n; i++)	//인원수
//	{
//		min = expectTime[0] + times[0];
//
//		for (int j = 0; j < expectTime.size(); j++)
//		{
//			if (expectTime[j] + times[j] <= min)
//			{
//				//expectTime[j] += times[j];
//				min = expectTime[j] + times[j];
//				minIdx = j;
//			}
//		}
//
//		expectTime[minIdx] += times[minIdx];
//
//	}
//
//	for (int i = 0; i < expectTime.size(); i++)
//	{
//		if (answer <= expectTime[i])
//		{
//			answer = expectTime[i];
//		}
//	}
//
//	return answer;
//}


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long left = (long long)times[0];
	long long right = (long long)times[times.size() - 1] * n;
	long long answer = right;
	while (left <= right) {
		long long mid = (right + left) / 2;
		long long pass = 0;

		for (int i = 0; i < times.size(); ++i)
			pass += mid / (long long)times[i];

		if (pass >= n) {
			right = mid - 1;
			if (mid <= answer)
				answer = mid;
		}
		else
			left = mid + 1;
	}
	return answer;
}


void main()
{
	int n = 6;
	vector<int> times = { 7,10 };

	cout << solution(n, times) << endl;



}

//6	[7, 10]	28

*/





























//이분탐색 예산
/*
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	sort(budgets.begin(),budgets.end());

	int total=0;
	int left = 0;
	int right=budgets[budgets.size()-1];
	for(int i=0;i<budgets.size();i++)
	{
		total+=budgets[i];
	}
	if(total<=M)
		return right;
	while(left<=right)
	{
		total = 0;
		int mid = (left+right)/2;
		for(int i=0;i<budgets.size();i++)
		{
			if(budgets[i]<mid)
			{
				total+=budgets[i];
			}
			else
				total+=mid;
		}

		if(total>M)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	return right;
}
*/
/*
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//전체예산 485 지방수로 나눠
//평균나와 -> 완전히 중간은 아닐수도있다. ->중간값 저장!!!
//평균보다 못한애들 차이값 모두 더해
//모두 더한거 미드의 오른쪽 애들 수만큼 나눠 -> 나눈값 저장!!!
//중간값이랑 + 나눈값 = 상한액

//최적의 방법이라는데.
int solution(vector<int> budgets, int M) {
	int answer = 0;
	int numbers = budgets.size();

	sort(budgets.begin(), budgets.end());

	for (auto itr = budgets.begin(); itr != budgets.end(); itr++) {
		if (*itr > (M / numbers)) return M / numbers;
		else {
			M -= *itr;
			numbers--;
		}
	}

	return budgets.back();
}
//int solution(vector<int> budgets, int M) {
//	int answer = 0;
//
//	//엔빵. M
//	//int nbLeft = M % budgets.size();
//	int nb = M / budgets.size();
//	int collectLess = 0; //엔빵한거보다 아래의 차액 합한거.
//	int collectLessIdx = 0;
//
//	int divCollectLess = 0;
//	int divCollectLessLeft = 0;
//
//	sort(budgets.begin(), budgets.end());
//
//	for (int i = 0; i< budgets.size(); i++)
//	{
//		if (budgets[i] <= nb)
//		{
//			collectLess += (nb - budgets[i]);
//			collectLessIdx = i;
//		}
//	}
//
//	divCollectLess = collectLess / (budgets.size() - (collectLessIdx + 1));
//	//divCollectLessLeft = collectLess % (budgets.size() - (collectLessIdx + 1));
//
//	return nb + divCollectLess;// +nbLeft + divCollectLessLeft;
//
//	//return answer;
//}

int main()
{
	vector<int> budgets = { 120, 110, 140, 150 };
	int M = 485;

	cout << solution(budgets, M) << endl;



	return 0;
}

// 120, 110, 140, 150       485
*/










//정렬 hindex 논문
/*
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	std::sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); i++) {
		if (citations.size() - i <= citations[i]) {
			answer = citations.size() - i;
			break;
		}
	}


	return answer;
}
//int solution(vector<int> citations) {
//	int answer = 0;
//	vector<int> citationsCopy;
//	//citationsCopy.insert(citations.begin(),)
//	sort(citations.begin(), citations.end());
//
//	for (int i = 0; i < citations.size(); i++)
//	{
//		for (int j = citations[0]; j <= citations[citations.size() - 1]; j++)
//		{
//			if (citations[i] >= j)
//			{
//				if (j <= citations.size() - i + 1 && j >= i + 1)
//				{
//					return j;
//				}
//			}
//		}
//	}
//
//
//	return answer;
//}


int main()
{
	vector<int> citation = { 3, 0, 6, 1, 5 };

	cout << solution(citation) << endl;

	return 0;
}

//[3, 0, 6, 1, 5]

*/















//정렬 가장 큰 수
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	//해당 케이스에서. return s1 > s2;
	//a가 앞서는거 true.
	//b가 앞서는거 false.

	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);
	return s1 > s2;
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);

	for (auto& i : numbers)
	{
		answer += to_string(i);
	}

	return answer[0] == '0' ? "0" : answer;
}

void main()
{
	int n = 5;
	vector<int> lost = { 3, 30, 34, 5, 9 };

	cout << solution(lost) << endl;

}
*/
/*
#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b)
{
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> strings;

	for (int i : numbers)
		strings.push_back(to_string(i));

	sort(strings.begin(), strings.end(), compare);

	for (auto iter = strings.begin(); iter < strings.end(); ++iter)
		answer += *iter;

	if (answer[0] == '0')
		answer = "0";

	return answer;
}
//#include <string>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//
//using namespace std;
//
////내림차순.
//bool compare(int _left, int _right)
//{
//	int leftMok = _left, rightMok = _right;
//	int leftNam = 0, rightNam = 0;
//
//	int i = 0;
//	//맨왼쪽에서 숫자 하나 떼와야 함.
//	while (true)
//	{
//		i++;
//		leftNam = leftMok % 10;
//		rightNam = rightMok % 10;
//		leftMok /= pow(10, i);
//		rightMok /= pow(10, i);
//
//		if (!(leftMok > 0 && rightMok > 0))
//		{
//			if (leftNam < rightNam)
//			{
//				return false;
//			}
//			else
//			{
//				return true;
//			}
//		}
//	}
//
//}

//string solution(vector<int> numbers) {
//	string answer = "";
//
//	sort(numbers.begin(), numbers.end(), compare);
//
//	for (int _num : numbers)
//	{
//		answer += to_string(_num);
//	}
//
//	return answer;
//}


int main()
{
	vector<int> numbers = { 30, 300, 34, 512, 9 };
	cout<<solution(numbers)<<endl;


	return 0;
}

//[3, 30, 34, 5, 9]

*/

















//정렬 k번째수
/*
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;

	for (vector<int> _info : commands)
	{
		vector<int> _vecTemp;

		for (int i = _info[0]-1;//시작인덱스
			i <= _info[1]-1;//끝인덱스
			i++)
		{
			_vecTemp.push_back(array[i]);
		}

		//sort
		sort(_vecTemp.begin(), _vecTemp.end());

		answer.push_back(_vecTemp[_info[2] - 1]);
	}


	return answer;
}

int main()
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} };

	vector<int> result = solution(array, commands);

	for (int _val : result)
	{
		cout << _val << endl;
	}

	return 0;
}

//[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]

*/










//해시 베스트앨범 음반 듣기 수
/*


#include <iostream>

//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//bool compare(pair<int, int> left, pair<int, int> right) {
//	if (left.first > right.first) {
//		return true;
//	}
//	else if (left.first == right.first) {
//		if (left.second < right.second) {
//			return true;
//		}
//	}
//	return false;
//}

//vector<int> solution(vector<string> genres, vector<int> plays) {
//	vector<int> answer;
//	unordered_map<string, int> summap;
//	unordered_map<string, vector<pair<int, int>>> genmap;
//
//	for (int i = 0; i < genres.size(); i++) {
//		summap[genres[i]] += plays[i];
//		genmap[genres[i]].push_back(make_pair(plays[i], i));
//	}
//
//	vector<pair<int, string>> fororder;
//
//	for (auto x : summap) {
//		fororder.push_back(make_pair(x.second, x.first));
//	}
//
//	sort(fororder.begin(), fororder.end());
//
//	while (fororder.size() > 0) {
//		pair<int, string> temp = fororder.back();
//		fororder.pop_back();
//		vector<pair<int, int>> a = genmap[temp.second];
//		sort(a.begin(), a.end(), compare);
//		//sort(a.begin(), a.end());
//		int lastn = 2;
//		if (a.size() < 2) {
//			lastn = a.size();
//		}
//		for (int i = 0; i < lastn; i++) {
//			answer.push_back(a[i].second);
//		}
//	}
//
//	return answer;
//}


#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare1(pair<int, int> _left, pair<int, int> _right)
{
	if (_left.second > _right.second)
	{
		return true;
	}
	else if (_left.second == _right.second)
	{
		if(_left.first < _right.first)
			return true;
	}

	return false;

	//return _left.second > _right.second;
}

bool compare2(pair<string, int> _left, pair<string, int> _right)
{
	if (_left.second < _right.second)
	{
		return false;
	}
	else
	{
		return true;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, vector<pair<int, int>>> genreByIndexValue;	//index, value
	map<string, int> genreBySumValue;
	vector<pair<string, int>> vecGenreBySumValue;

	for (int i = 0; i < genres.size(); i++)
	{
		vector < pair<int, int>> _valuesByIndex = { pair<int,int>(i, plays[i]) };
		if (genreByIndexValue.count(genres[i]) == 0)
		{
			genreByIndexValue.insert(pair<string, vector < pair<int, int>>>(genres[i], _valuesByIndex));
		}
		else
		{
			genreByIndexValue[genres[i]].push_back(_valuesByIndex[0]);
		}

		genreBySumValue[genres[i]] += plays[i];
	}

	////값을 기준으로 인덱스 정렬. genreByIndexValue
	//for (pair<string, vector<pair<int,int>>> _pair : genreByIndexValue)
	//{
	//	sort(_pair.second.begin(), _pair.second.end(), compare1);


	//	//answer.push_back(_pair.second[0] % 100);
	//	//answer.push_back(_pair.second[1] % 100);
	//}
	for (auto iter = genreByIndexValue.begin(); iter != genreByIndexValue.end(); iter++)
	{
		sort(iter->second.begin(), iter->second.end(), compare1);
	}


	//어떤장르가 우선인지 -> 합을 토대로 정렬.
	for (pair<string, int> _pair : genreBySumValue)
	{
		vecGenreBySumValue.push_back(_pair);
	}
	sort(vecGenreBySumValue.begin(), vecGenreBySumValue.end(), compare2);

	//answer작성
	for (pair<string, int> _pair : vecGenreBySumValue)
	{
		answer.push_back(genreByIndexValue[_pair.first][0].first);

		if (genreByIndexValue[_pair.first].size() > 1)
		{
			answer.push_back(genreByIndexValue[_pair.first][1].first);
		}
	}



	return answer;
}

int main()
{
	vector<string> genres = { "classic","pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	vector<int> answer = solution(genres, plays);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}


//[classic, pop, classic, classic, pop]
//[500, 600, 150, 800, 2500]
*/








/*
//해시 위장.
#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> countByType;

	for (vector<string> _vec : clothes)
	{
		if (countByType.count(_vec[1]) == 0)
		{
			countByType.insert(pair<string, int>(_vec[1], 1));
		}
		else
		{
			countByType[_vec[1]] += 1;
		}
	}

	//갯수만큼 돌려야됨. 타입
	for (auto i = countByType.begin(); i != countByType.end(); i++)
	{
		answer *= (i->second + 1);
	}

	answer--;

	return answer;
}


int main()
{
	vector<vector<string>> clothes = { {"yellow_hat","headgear"}
		,{"blue_sunglasses","eyewear"}
		,{"green_turban","headgear"} };

	cout << solution(clothes) << endl;
	return 0;
}
*/













//해시 전화번호 목록
/*
//#include <string>
#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phoneBook) {
	bool answer = true;

	sort(phoneBook.begin(), phoneBook.end());

	for (int i = 0; i < phoneBook.size() - 1; i++)
	{
		if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
		{
			answer = false;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<string> phone_book = { "119", "97674223", "1195524421" };

	cout << solution(phone_book) << endl;

	return 0;
}


//내가푼거
#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	vector<string> strMinLength;
	int minLength = 21;


	for (string _str : phone_book)
	{
		if (_str.length() <= minLength)
		{
			minLength = _str.length();
			strMinLength.push_back(_str);
		}
	}

	for (string _strMinLength : strMinLength)
	{
		for (string _str : phone_book)
		{
			if (_str != _strMinLength && _str.find(_strMinLength) != string::npos)
			{
				return false;
			}
		}
	}

	return answer;
}

int main()
{
	vector<string> phone_book = { "119", "123", "1195524421" };

	cout << solution(phone_book) << endl;

	return 0;
}
*/




//프로그래머스 코딩테스트 연습 해시 완주하지 못한 선수다른 사람의 풀이

/*
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> d;
	for (auto& i : participant) d[i]++;
	for (auto& i : completion) d[i]--;
	for (auto& i : d)
	{
		if (i.second > 0)
		{
			answer = i.first;
			break;
		}
	}

	return answer;
}
int main()
{
	vector<string> participant = { "leo", "kiki","eden" };
	vector<string> completion = { "kiki","eden" };


	cout << solution(participant, completion) << endl;


	return 0;
}
*/
/*
#include <iostream>


#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> countByName;

	for (string _str : completion)
	{
		if (countByName.count(_str) == 0)
		{
			//not found
			countByName.insert(pair<string, int>(_str, 1));

		}
		else
		{
			//found
			countByName[_str] += 1;
		}
	}

	for (string _str : participant)
	{
		if (countByName.count(_str) == 0)
		{
			return _str;
		}
		else
		{
			//found
			countByName[_str] += 1;
		}
	}

	map<string, int >::iterator iter;
	for (iter = countByName.begin(); iter != countByName.end(); iter++) {
		if (iter->second % 2 == 1)
		{
			return iter->first;
		}
	}




	return answer;
}


int main()
{
	vector<string> participant = { "leo", "kiki","eden" };
	vector<string> completion = { "kiki","eden" };


	cout << solution(participant, completion) << endl;


	return 0;
}
*/
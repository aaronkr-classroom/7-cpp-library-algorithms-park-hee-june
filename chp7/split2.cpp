#include<algorithm> //find_if()
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 인수가 공백일 때는 true,그렇지 않을때는 false
bool space(char c)
{
	return isspace(c);
}
// 인수가 공백일 때는 true,그렇지 않을때는 false
bool not_space(char c)
{
	return !isspace(c);
}
vector<string>split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	// for(iter i = str.begin(); i != str.end(); i++
	while (i != str.end()) {
		cout << "String begin pos:" << distance(str.begin(),i) << endl;
		// 선행 공백을 무시
		// 지금 i위치부터 첫 번째 뛰어쓰기 아닌 문자 찾기
		i = find_if(i, str.end(), not_space);
		cout << "String begin pos:" << distance(str.begin(), i) << endl;

		//다음 단어의 끝을 찾음
		//while 반복
		iter j = find_if(i, str.end(), space);
		cout << "String begin pos:" << distance(str.begin(), j) << endl;

		if (i != str.end()) {
			ret.push_back(string(i, j));

		}
		i = j;
		cout << "i 이동 pos:" << distance(str.begin(), i) << endl;
	}
	return ret;
}
int main() {
	string s;
	//문자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;

}
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
bool not_url_char(char c) {
	static const string url_ch = "~;/?@=&-_.*'(),";

	//c가 url에 들어갈수 있는 문자인지 확인하면 음수를 반환
	return !(
		isalnum(c) ||
		find(url_ch.begin(), url_ch.end(), c) != url_ch.end()
		);
}

string::const_iterator url_end(
	string::const_iterator b,
	string::const_iterator e
) {
	

	return  find_if(b, e, not_url_char); 
}
string::const_iterator url_beg(
	string::const_iterator b,
	string::const_iterator e)
	{
	static const string sep = "://";
	typedef string::const_iterator iter;
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {

		if (i != b && i + sep.size() != e) {
			// beg는 프로토콜 이름의 시작 위치를 표시
			iter beg = i;
			while (beg != b && isalpha(beg[-1])) {
				--beg;
			}
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		//발견한 구분 기호는 URL 일부가 아니므로
		//해당 구분 기호 이후를 표시하도록 i를 증가시킴
		i += sep.size();
	}
	return e;
}

vector<string> find_urls(const string& s) {
	vector<string> urls;
	typedef string::const_iterator iter;
	iter b = s.begin(),
		e = s.end();
	while (b != e) {
		b = url_beg(b, e);// 프로토컬 이름 찾기

		if (b != e) {
			//해당 문자를 찾아다면 URL의 나머지 부분을 탐색
			iter after = url_end(b, e);//프로토컬 이름 후

			// URL을 찾았으면 저장
			urls.push_back(string(b, after));

			//인수로 전달받은 문자열에서 또
			//다른 url을 찾기 위해  b를 증가
			b = after;
		}
	}
	return urls;
}
int main() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = find_urls(s);

		for (vector<string>::const_iterator i = v.begin();
			i != v.end(); i++) {
			cout << *i << endl;
		}

		return 0;
	
	}
}
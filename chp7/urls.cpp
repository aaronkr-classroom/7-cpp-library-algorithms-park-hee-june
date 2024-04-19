#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
bool not_url_char(char c) {
	static const string url_ch = "~;/?@=&-_.*'(),";

	//c�� url�� ���� �ִ� �������� Ȯ���ϸ� ������ ��ȯ
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
			// beg�� �������� �̸��� ���� ��ġ�� ǥ��
			iter beg = i;
			while (beg != b && isalpha(beg[-1])) {
				--beg;
			}
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		//�߰��� ���� ��ȣ�� URL �Ϻΰ� �ƴϹǷ�
		//�ش� ���� ��ȣ ���ĸ� ǥ���ϵ��� i�� ������Ŵ
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
		b = url_beg(b, e);// �������� �̸� ã��

		if (b != e) {
			//�ش� ���ڸ� ã�ƴٸ� URL�� ������ �κ��� Ž��
			iter after = url_end(b, e);//�������� �̸� ��

			// URL�� ã������ ����
			urls.push_back(string(b, after));

			//�μ��� ���޹��� ���ڿ����� ��
			//�ٸ� url�� ã�� ����  b�� ����
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
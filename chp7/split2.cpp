#include<algorithm> //find_if()
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// �μ��� ������ ���� true,�׷��� �������� false
bool space(char c)
{
	return isspace(c);
}
// �μ��� ������ ���� true,�׷��� �������� false
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
		// ���� ������ ����
		// ���� i��ġ���� ù ��° �پ�� �ƴ� ���� ã��
		i = find_if(i, str.end(), not_space);
		cout << "String begin pos:" << distance(str.begin(), i) << endl;

		//���� �ܾ��� ���� ã��
		//while �ݺ�
		iter j = find_if(i, str.end(), space);
		cout << "String begin pos:" << distance(str.begin(), j) << endl;

		if (i != str.end()) {
			ret.push_back(string(i, j));

		}
		i = j;
		cout << "i �̵� pos:" << distance(str.begin(), i) << endl;
	}
	return ret;
}
int main() {
	string s;
	//���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0;
			i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}
	return 0;

}
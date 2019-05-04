/*

Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string encode(string plain_text, string key) {
	string result;
	int key_len = key.length();
	int text_len = plain_text.length();
	int key_index = 0;
	for(int i = 0; i<text_len; i++) {
		int code_byte = plain_text.at(i)^key.at(key_index);
		result += code_byte;
		key_index++;
		if(key_index == key_len) key_index = 0;
	}
	return result;
}
string decode(string cipher, string key) {
	string result;
	int key_len = key.length();
	int cipher_len = cipher.length();
	int key_index = 0;
	for(int i = 0; i<cipher_len; i++) {
		char decoded = cipher.at(i)^key.at(key_index);
		result += decoded;
		key_index++;
		if(key_index == key_len) key_index = 0;
	}
	return result;
}

float printable_part(string str) {
	int len = str.length();
	int count = 0;
	for(int i = 0; i<len; i++) {
		char ch = str.at(i);
		if(ch>='a'&&ch<='z')
			count++;
		else if(ch>='A' && ch<='Z')
			count++;
		else if(ch>='0' && ch<='9')
			count++;
		else if(ch==' ')
			count++;
	}
	return count*100.0/len;
}

int ascii_sum(string s) {
	int len = s.length();
	int sum = 0;
	for(int i = 0; i<len; i++)
		sum += s.at(i);
	return sum;
}
int main() {
	ifstream infile("input/p059_cipher.txt");
	string the_code;
	int byte;
	while(true) {
		infile>>byte;
		infile.ignore();
		if(infile.eof()) break;
		the_code += (char) byte;
	}
	//cout<<the_code<<endl;
	for(char a = 'a'; a<='z'; a++)
	for(char b = 'a'; b<='z'; b++)
	for(char c = 'a'; c<='z'; c++) {
		string the_key;
		the_key+=a;
		the_key+=b;
		the_key+=c;
		string decoded = decode(the_code, the_key);
		if(printable_part(decoded)>95) {
			cout<<decoded<<endl<<"Sum of byte values: "<<ascii_sum(decoded)<<endl;
			cout<<"The key is: "<<the_key<<endl;
		}
	}
	infile.close();
	return 0;
}

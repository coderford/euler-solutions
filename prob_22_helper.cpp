#include <fstream>
using namespace std;

int main() {
    ifstream infile;
    ofstream outfile;
    infile.open("p022_names.txt");
    outfile.open("p22_names_modif.txt");
    char ch;
    infile>>ch;
    while(!infile.eof()) {
        if(ch=='\"') ;
        else if(ch==',') outfile<<" ";
        else outfile<<ch;
        infile>>ch;
    }
    infile.close();
    outfile.close();
    return 0;
}
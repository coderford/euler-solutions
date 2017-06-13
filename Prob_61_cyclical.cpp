#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isInt(double x) {
    if(((int)x) == x)
        return true;
    else
        return false;
}

bool is_triangle(int num) {
    float D = 1 + 8*num;
    if(D<0){
        return false;
    }
    float a = (1 + sqrt(D))/2;
    float b = (1 - sqrt(D))/2;
    if(isInt(a)&&isInt(b)&&(b>0||a>0))
        return true;
}

bool is_square(long x) {
    if(x<0)
        return false;
    if(isInt(sqrt(x)))
        return true;
    return false;
}

bool is_pent(long x) {
    double D = 24*x+1;  //double is necessary as float is not precise enough...
    double sol = (sqrt(D)+1)/6; //i got a close but wrong answer because of float
    if(isInt(sol)) {
        //cout<<"pent: "<<sol<<endl;
        return true;
    }
    return false;
}

bool is_hex(long x) {
    double D = 8*x + 1;    //simply solving the eq for +ve value of n;
    double sol = (sqrt(D)+1)/4;
    if(isInt(sol)) {
        //cout<<"hex: "<<sol<<endl;
        return true;
    }
    return false;
}

bool is_hept(long x) {
    double D = 9 + 40*x;    //simply solving the eq for +ve value of n;
    double sol = (sqrt(D)+3)/10;
    if(isInt(sol)) {
        return true;
    }
    return false;
}

bool is_oct(long x) {
    double D = 4 + 12*x;    //simply solving the eq for +ve value of n;
    double sol = (sqrt(D)+2)/6;
    if(isInt(sol)) {
        return true;
    }
    return false;
}

bool do_link(int a, int b) {
    if(a%100 == b/100)
        return true;
    return false;
}

bool has_all(vector<int> &the_set) {
    int counts[6] = {0};
    int cyc_count[6] = {0};
    for(int i = 0; i<the_set.size(); i++) {
        if(is_triangle(the_set.at(i)))
            { counts[i]++; cyc_count[0]++;}
        if(is_square(the_set.at(i)))
            { counts[i]++; cyc_count[1]++;}
        if(is_pent(the_set.at(i)))
            { counts[i]++; cyc_count[2]++;}
        if(is_hex(the_set.at(i)))
            { counts[i]++; cyc_count[3]++;}
        if(is_hept(the_set.at(i)))
            { counts[i]++; cyc_count[4]++;}
        if(is_oct(the_set.at(i)))
            { counts[i]++; cyc_count[5]++;}
    }
    /*for(int i = 0; i<6; i++) {
        if(counts[i]==0)
            return false;
    }*/
    for(int i = 0; i<6; i++) {
        if(cyc_count[i]==0)
            return false;
    }
    return true;
}

int main() {
    vector<int> tri;
    vector<int> oth;
    for(int i = 1000; i<10000; i++) {
        if(is_triangle(i))
            { tri.push_back(i); continue; }
        if(is_square(i))
            { oth.push_back(i); continue; }
        if(is_pent(i))
            { oth.push_back(i); continue; }
        if(is_hex(i))
            { oth.push_back(i); continue; }
        if(is_hept(i))
            { oth.push_back(i); continue; }
        if(is_oct(i))
            { oth.push_back(i); continue; }
    }
    int tri_count = tri.size();
    int oth_count = oth.size();
    //cout<<tri_count<<" "<<oth_count;
    vector<int> myset;
    for(int i = 0; i<tri_count; i++) {
        myset.clear();
        myset.push_back(tri.at(i));
        for(int j = 0; j<oth_count; j++) {
            if(do_link(myset.at(0), oth.at(j))) {
                myset.erase(myset.begin()+1, myset.end());
                myset.push_back(oth.at(j));
                for(int k = 0; k<oth_count; k++) {
                    if(do_link(myset.at(1), oth.at(k))) {
                        myset.erase(myset.begin()+2, myset.end());
                        myset.push_back(oth.at(k));
                        for(int l = 0; l<oth_count; l++) {
                            if(do_link(myset.at(2), oth.at(l))) {
                                myset.erase(myset.begin()+3, myset.end());
                                myset.push_back(oth.at(l));
                                for(int m = 0; m<oth_count; m++) {
                                    if(do_link(myset.at(3), oth.at(m))) {
                                        myset.erase(myset.begin()+4, myset.end());
                                        myset.push_back(oth.at(m));
                                        for(int n = 0; n<oth_count; n++) {
                                            if(do_link(myset.at(4), oth.at(n))&&do_link(oth.at(n), myset.at(0))) {
                                                myset.erase(myset.begin()+5, myset.end());
                                                myset.push_back(oth.at(n));
                                                if(has_all(myset)) {
                                                    int sum = 0;
                                                    for(int i = 0; i<myset.size(); i++)
                                                        {cout<<myset.at(i)<<" "; sum+=myset.at(i);}
                                                    cout<<" SUM: "<<sum<<endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

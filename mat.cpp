#include "mat.hpp"

using namespace std;

namespace ariel{
    bool check_info(int a, int b, char c, char d){
        //if(c==d) {throw std::runtime_error ("the char are the same");}
        char small_ch ='!';
        char  big_char ='~';
        if(c <small_ch || c>big_char || d<small_ch || d>big_char){throw std:: runtime_error ("this char is not ascii!");}
        if(a%2==0 || b%2==0){throw std::runtime_error ("Mat size is always odd");}
        if(a<1 || b<1){throw std::runtime_error ("error input negative numbers");}
        return true;
    }
    std::string complete_line(int a,int b,char c, char d,const std::string & st){
	unsigned long size = (a-st.length());
	string header;
	for (int i=0; i<size/2;i++){
		if(i%2==0){header+=c;}
		if(i%2==1){header+=d;}
	}
	string rv;
	for(unsigned long i=0;i<header.length();i++){rv+=header[header.length()-1-i];}
	return (header +st + rv);
}
    std::string build_line(int a, int b,char c, char d)
    {
        unsigned long size_of_line =a;
        string my_mat;
        for (int i=0; i<(b/2)+1;i++){
            string st;
            if(i%2==0){for(int j=0;j<a;j++){st+=c;}}
            if(i%2==1){for(int j=0;j<a;j++){st+=d;}}
            st = complete_line((int)size_of_line,b,c,d,st);
            if(a==1){
                while(i<b/2){
                    my_mat+=st;
                    i++;
                }
            }
            a-=2;
            my_mat+=st;
        }
        return my_mat;
    }
    std::string mat(int a, int b, char c, char d)
    {
        check_info(a,b,c,d);
        string my_mat;
        my_mat = build_line(a,b,c,d);
        string tail;
        for (unsigned long i=0; i<my_mat.length()-a;i++){tail+=my_mat[my_mat.length()-a-1-i];}
        my_mat+=tail;
        string temp;
        for (int i=0; i<my_mat.length();i++)
        {
            if(i%a==0 && i!=0){temp+='\n';}
            temp+=my_mat[i];
        }
        return temp;
    }
}


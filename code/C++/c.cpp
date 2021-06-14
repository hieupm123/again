#include<iostream>
#include<ctime>
#include<unistd.h>
#include<set>
#include<vector>
using namespace std;
int rand(int a, int b){
	return a + rand()%(b-a+1);
}
// string gen_random(const int len) {
//     string tmp_s;
//     static const char alphanum[] =
//         "0123456789"
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//         "abcdefghijklmnopqrstuvwxyz";
//     srand( (unsigned) time(NULL) * getpid());
//     tmp_s.reserve(len);
//     for (int i = 0; i < len; ++i) 
//         tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
//     return tmp_s;
// }
string gen_random(const long long len) {
    string tmp_s;
    static const char alphanum[] =
        // "0123456789"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    	// "*.";
    	// "0123456789";
    srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    return tmp_s;
}
int main(int argc, char* argv[]){
	srand(stoi(argv[1]));
	int n = 50, q = 50;
    cout<<n<<" "<<q<<"\n";
    for(int i = 0; i < n; ++i){
        cout<<rand(1,9)<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < q; ++i){
        int a = rand(1,2);
        cout<<a<<" ";
        if(a == 1){
            int b = rand(1,n), c = rand(1, n), d = rand(1,9);
            if(b > c) swap(b,c);
            cout<<b<<" "<<c<<" "<<d<<"\n";
        }else{
            int b = rand(1,n);
            cout<<b<<"\n";
        }
    }
}
#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <fstream>

using namespace std;


int main(){

float summ1 = 0.0;
float summ2 = 0.0;
vector<int> a(1e7);
vector<float> b(1e7);
ofstream out_file;
out_file.open("res1.txt");
for (int i = 1; i <= 1e7; i++){
    summ1 += 1.0/i;
    a[i-1] = i;
    b[i-1] = summ1;
    out_file << a[i-1] << " " << b[i-1] << endl;
}
out_file.close();
vector<int> c(1e7);
vector<float> d(1e7);
int k = 0;
out_file.open("res2.txt");
for (int i = 1e7; i >= 1; i--){
    summ2 += 1.0/i;
    c[k] = k + 1;
    d[k] = summ2;
    out_file << c[k] << " " << d[k] << endl;
    k += 1;
}
out_file.close();
cout << "Completed" << endl;
cout << summ1 << " " << summ2 << endl;
cout << summ2 - summ1;

}

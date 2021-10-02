#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

float kahan_summation(vector<float> const &numbers){
    float sum = 0.f;
    float compensation = 0.f;
    float tmp1, tmp2;

    for (unsigned pos = 0; pos != numbers.size(); ++pos){
        tmp1 = numbers[pos] - compensation;
        tmp2 = sum + tmp1;
        compensation = (tmp2 - sum) - tmp1;
        sum = tmp2;
    }
    return sum;
}
int main(){
    double x, y, xn, yn, xc, yc, dt, w, E_0;
    cin >> xc >> yc;
    xn = xc;
    yn = yc;
    dt = 0.00001;
    w = 1;
    ofstream out_file;
    out_file.open("data_2.txt");
    E_0 = xc*xc/2 + w*w*yc*yc/2;
    for (int t = 0; t < 8000000; t++){
        xn = xc-w*w*yc*dt;
        yn = yc + xc*dt;
        xc = xn;
        yc = yn;
        if (t%10 ==0)
            out_file << t << " " << xn << " " << yn << " " << xn*xn/2 + w*w*yn*yn/2 << " " << ((xn*xn/2 + w*w*yn*yn/2)/E_0)-1 <<  endl;
    }
    /*dy = x*dt;
    dx = -w*w*y*dt;*/
    out_file.close();
    cout << "Completed";
    /*out_file.open("res2.txt");
    double xn2, x20, yn2, yn22, y20, x2c, y2c, y22c;
    cin >> x20 >> y20;
    xn2 = x20;
    yn2 = y20;
    yn22 = y20;
    for (int t = 0; t < 20000; t++){
        xn2 = x2c - w*w*yn22*dt;
        yn22 = x2c*dt/2 + y2c;
        yn2 = y22c + x2c*dt/2;
        x2c = xn2;
        y2c = yn2;
        y22c = yn22;
        out_file << t << " " << xn2 << " " << yn2 << endl;
    }*/

}

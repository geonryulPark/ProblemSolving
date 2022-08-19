#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string& word) {
    if (!inRange(y, x)) return false;
    if 
}

bool inRange(int y, int x) {
    if (y >= 5 || x >= 5) return false;
    return true;
}

int main(void) {

}
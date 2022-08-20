#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];

int countParing(bool taken[10]) {
    bool finished = true;
    for (int i = 0; i < n; i++)
        if (!taken[i]) finished = false;
    if (finished) return 1;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!taken[i] && !taken[j] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countParing(taken);
                taken[i] = taken[j] = false;
            }
        }
    }

    return ret;
}

/*
1. 중복해서 세는 문제
2. 단계별로 찢는 연습

사전 순으로 가장 먼저 오는 답만을 세는 방법으로
중복을 제거할 수 있다.

*/

int countParing(bool taken[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            // 어차피 i 는 오름차순이므로 걸렸을 때 바로 break 하면
            // 가장 낮은 위치를 찾을 수 있다.
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[pairWith] = taken[firstFree] = true;
            ret += countParing(taken);
            taken[pairWith] = taken[firstFree] = false;
        }
    }

    return ret;
}
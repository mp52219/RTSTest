//
// Created by Marin on 13.12.2020..
//

#include <iostream>
#include "GlobalGameVariables.hpp"
#include "FindPath.hpp"
void FindPath::setSrc(int src){
    this->src = src;
};
int FindPath::d(int src, int dst) {
    int dx = abs(src / EFS - dst / EFS);
    int dy = abs(src % EFS - dst % EFS);
    return 14 * std::min(dx, dy) + 10 * (std::max(dx, dy) - std::min(dx, dy)) - 10;
}

FindPath::FindPath(int srcO, int dstO) {
    src = srcO;
    dst = dstO;
    //retList.clear();
}

void FindPath::findPath() {
    int prevDest = retList.back();
    //if destination is not reachable
    if (map[dst] == '*') {
        if (map[dst + 1] != '*')
            dst = dst + 1;
        else if (map[dst - 1] != '*')
            dst = dst - 1;
        else if (map[dst - (EFS + 1)] != '*')
            dst = dst - (EFS + 1);
        else if (map[dst - (EFS - 1)] != '*')
            dst = dst - (EFS - 1);
        else if (map[dst + (EFS + 1)] != '*')
            dst = dst + (EFS + 1);
        else if (map[dst + (EFS - 1)] != '*')
            dst = dst + (EFS - 1);
        else if (map[dst - EFS] != '*')
            dst = dst - EFS;
        else if (map[dst + EFS] != '*')
            dst = dst + EFS;
    }
    if(dst == prevDest || src == dst) {
        return;
    }
    retList.clear();
    for (int i = 0; i < EFS2; i++) {
        map2[i] = '-';
    }
    int slowM = 0;
    int nvs[EFS2];
    int vs[EFS2];
    int chg[EFS2];

    for (int i = 0; i < EFS2; i++) {
        vs[i] = -1;
        nvs[i] = 2147483647;
        chg[i] = -1;
    }
    nvs[src] = 0;
    vs[src] = src;

    int j;
    for (j = 0; j < EFS2; j++) {
        for (int i = 0; i < EFS2; i++) {
            if (vs[i] != -1 && map[i] != '*') {
                if (map[i] == '+')
                    slowM = slow;
                else
                    slowM = 0;
                if (i % EFS != 0 && vs[i - 1] == -1) {
                    if (nvs[i - 1] > nvs[i] + 10 + slowM + d(i - 1, dst)*isAStar) {
                        nvs[i - 1] = nvs[i] + 10 + slowM + d(i - 1, dst)*isAStar;
                        chg[i - 1] = i;
                    }
                }

                if (i % EFS != EFS - 1 && vs[i + 1] == -1) {
                    if (nvs[i + 1] > nvs[i] + 10 + slowM + d(i + 1, dst)*isAStar) {
                        nvs[i + 1] = nvs[i] + 10 + slowM + d(i + 1, dst)*isAStar;
                        chg[i + 1] = i;
                    }
                }
                //up left
                if (i % EFS != 0 && i >= EFS && vs[i - (EFS + 1)] == -1 && map[i-1] != '*' && map[i - EFS] != '*') {
                    if (nvs[i - (EFS + 1)] > nvs[i] + 14 + slowM + d(i - (EFS + 1), dst)*isAStar) {
                        nvs[i - (EFS + 1)] = nvs[i] + 14 + slowM + d(i - (EFS + 1), dst)*isAStar;
                        chg[i - (EFS + 1)] = i;
                    }
                }
                //up right
                if (i > EFS - 1 && i % EFS != EFS - 1 && vs[i - (EFS - 1)] == -1 && map[i+1] != '*' && map[i - EFS] != '*') {
                    if (nvs[i - (EFS - 1)] > nvs[i] + 14 + slowM + d(i - (EFS - 1), dst)*isAStar) {
                        nvs[i - (EFS - 1)] = nvs[i] + 14 + slowM + d(i - (EFS - 1), dst)*isAStar;
                        chg[i - (EFS - 1)] = i;
                    }
                }
                if (i > EFS - 1 && vs[i - EFS] == -1) {
                    if (nvs[i - EFS] > nvs[i] + 10 + slowM + d(i - EFS, dst)*isAStar) {
                        nvs[i - EFS] = nvs[i] + 10 + slowM + d(i - EFS, dst)*isAStar;
                        chg[i - EFS] = i;
                    }
                }
                if (i < EFS2 - EFS && vs[i + EFS] == -1) {
                    if (nvs[i + EFS] > nvs[i] + 10 + slowM + d(i + EFS, dst)*isAStar) {
                        nvs[i + EFS] = nvs[i] + 10 + slowM + d(i + EFS, dst)*isAStar;
                        chg[i + EFS] = i;
                    }
                }
                //down left
                if (i % EFS != 0 && i < EFS2 - EFS && vs[i + (EFS - 1)] == -1 && map[i-1] != '*' && map[i + EFS] != '*') {
                    if (nvs[i + (EFS - 1)] > nvs[i] + 14 + slowM + d(i + (EFS - 1), dst)*isAStar) {
                        nvs[i + (EFS - 1)] = nvs[i] + 14 + slowM + d(i + (EFS - 1), dst)*isAStar;
                        chg[i + (EFS - 1)] = i;
                    }
                }
                //down right
                if (i % EFS != EFS - 1 && i < EFS2 - (EFS + 1) && vs[i + (EFS + 1)] == -1 && map[i+1] != '*' && map[i + EFS] != '*') {
                    if (nvs[i + (EFS + 1)] > nvs[i] + 14 + slowM + d(i + (EFS + 1), dst)*isAStar) {
                        nvs[i + (EFS + 1)] = nvs[i] + 14 + slowM + d(i + (EFS + 1), dst)*isAStar;
                        chg[i + (EFS + 1)] = i;
                    }
                }
            }
        }
        int minimum = 2147483647;
        int t = 0;
        for (int k = 0; k < EFS2; k++) {
            if (nvs[k] < minimum && vs[k] == -1) {
                minimum = nvs[k];
                t = k;
            }
        }
        vs[t] = t;
        map2[t] = '/';
        if (vs[t] == dst) {
            int k = dst;
            retList.push_front(k);
            while (k != src) {
                retList.push_front(chg[k]);
                k = chg[k];
            }
            return;
        }
    }
}


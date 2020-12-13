//
// Created by Marin on 13.12.2020..
//

#include "GlobalGameVariables.hpp"
#include "FindPath.hpp"

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
    retList.clear();
    for (int i = 0; i < EFS2; i++) {
        map2[i] = '-';
    }
    int slow = 0;
    int nvs[EFS2];
    int vs[EFS2];
    int chg[EFS2];

    for (int i = 0; i < EFS2; i++) {
        vs[i] = -1;
        nvs[i] = MAX * MAX * MAX;
        chg[i] = -1;
    }
    if (src == dst) {
        retList.push_back(src);
        return;
    }
    nvs[src] = 0;
    vs[src] = src;
    int j;
    for (j = 0; j < EFS2; j++) {
        for (int i = 0; i < EFS2; i++) {
            if (vs[i] != -1 && map[i] != '*') {
                if (map[i] == '+')
                    slow = 20;
                else
                    slow = 0;
                if (i % EFS != 0 && vs[i - 1] == -1) {
                    if (nvs[i - 1] > nvs[i] + 10 + slow + d(i - 1, dst)) {
                        nvs[i - 1] = nvs[i] + 10 + slow + d(i - 1, dst);
                        chg[i - 1] = i;
                    }
                }

                if (i % EFS != EFS - 1 && vs[i + 1] == -1) {
                    if (nvs[i + 1] > nvs[i] + 10 + slow + d(i + 1, dst)) {
                        nvs[i + 1] = nvs[i] + 10 + slow + d(i + 1, dst);
                        chg[i + 1] = i;
                    }
                }
                if (i % EFS != 0 && i >= EFS && vs[i - (EFS + 1)] == -1) {
                    if (nvs[i - (EFS + 1)] > nvs[i] + 14 + slow + d(i - (EFS + 1), dst)) {
                        nvs[i - (EFS + 1)] = nvs[i] + 14 + slow + d(i - (EFS + 1), dst);
                        chg[i - (EFS + 1)] = i;
                    }
                }
                if (i > EFS - 1 && i % EFS != EFS - 1 && vs[i - (EFS - 1)] == -1) {
                    if (nvs[i - (EFS - 1)] > nvs[i] + 14 + slow + d(i - (EFS - 1), dst)) {
                        nvs[i - (EFS - 1)] = nvs[i] + 14 + slow + d(i - (EFS - 1), dst);
                        chg[i - (EFS - 1)] = i;
                    }
                }
                if (i > EFS - 1 && vs[i - EFS] == -1) {
                    if (nvs[i - EFS] > nvs[i] + 10 + slow + d(i - EFS, dst)) {
                        nvs[i - EFS] = nvs[i] + 10 + slow + d(i - EFS, dst);
                        chg[i - EFS] = i;
                    }
                }
                if (i < EFS2 - EFS && vs[i + EFS] == -1) {
                    if (nvs[i + EFS] > nvs[i] + 10 + slow + d(i + EFS, dst)) {
                        nvs[i + EFS] = nvs[i] + 10 + slow + d(i + EFS, dst);
                        chg[i + EFS] = i;
                    }
                }
                if (i % EFS != 0 && i < EFS2 - EFS && vs[i + (EFS - 1)] == -1) {
                    if (nvs[i + (EFS - 1)] > nvs[i] + 14 + slow + d(i + (EFS - 1), dst)) {
                        nvs[i + (EFS - 1)] = nvs[i] + 14 + slow + d(i + (EFS - 1), dst);
                        chg[i + (EFS - 1)] = i;
                    }
                }
                if (i % EFS != EFS - 1 && i < EFS2 - (EFS + 1) && vs[i + (EFS + 1)] == -1) {
                    if (nvs[i + (EFS + 1)] > nvs[i] + 14 + slow + d(i + (EFS + 1), dst)) {
                        nvs[i + (EFS + 1)] = nvs[i] + 14 + slow + d(i + (EFS + 1), dst);
                        chg[i + (EFS + 1)] = i;
                    }
                }
            }
        }
        int minimum = MAX * MAX * MAX;
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


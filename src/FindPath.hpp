//
// Created by Marin on 13.12.2020..
//

#ifndef RTSTEST_FINDPATH_HPP
#define RTSTEST_FINDPATH_HPP

#include <list>
#include <SFML/Graphics.hpp>

class FindPath {
public:
    int src;
    int dst;
    void setSrc(int src);
    std::list<int> retList;
    int d(int src, int dst);
    FindPath(int srcO,int dstO);

    virtual void findPath();
};


#endif //RTSTEST_FINDPATH_HPP

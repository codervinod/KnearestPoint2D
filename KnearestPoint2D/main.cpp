//
//  main.cpp
//  KnearestPoint2D
//
//  Created by Vinod Gupta on 2/3/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
class Points2D
{
public:
    Points2D(double x,double y):_x(x),_y(y)
    {
        _dist = ((_x*_x) + (_y*_y));
    }
    virtual ~Points2D()
    {
    }
    double getDist() const { return _dist;}
    
    double GetX() {return _x;}
    double GetY() {return _y;}
private:
    double _x;
    double _y;
    double _dist;
};

struct ComparePoints
{
    bool operator()(const Points2D &lhs,const Points2D &rhs)
    {
        return (lhs.getDist() > rhs.getDist());
    }
};

class NearestPoint2D
{
public:
    NearestPoint2D() {}
    virtual ~NearestPoint2D() {}
    
    void AddPoints(const Points2D &points) {_points_pq.push(points);}
    
    bool GetNearestPoints(vector<Points2D> &nearest_points,int K)
    {
        for(int i=0;i<K;++i)
        {
            if(_points_pq.empty()){
                return false;
            }
            
            nearest_points.push_back(_points_pq.top());
            _points_pq.pop();
        }
        return true;
    }
private:
    typedef priority_queue<Points2D,vector<Points2D>,ComparePoints> PointsPQ;
    
    PointsPQ _points_pq;
};

int main(int argc, const char * argv[]) {
    
    NearestPoint2D point_container;
    
    point_container.AddPoints(Points2D(5,13));
    point_container.AddPoints(Points2D(5,14));
    point_container.AddPoints(Points2D(10,10));
    point_container.AddPoints(Points2D(15,15));
    point_container.AddPoints(Points2D(30,10));
    
    vector<Points2D> nearest_points;
    point_container.GetNearestPoints(nearest_points,3);
    
    for(vector<Points2D>::iterator itr = nearest_points.begin(); itr != nearest_points.end(); ++itr)
    {
        cout<<"Nearest Point " << itr->GetX()<<" "<<itr->GetY()<<endl;
    }
    cout<<endl;
    return 0;
}

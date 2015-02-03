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
    }
    virtual ~Points2D()
    {
    }
    double getDist(const Points2D &origin) const
    {
        double xDist = (origin.GetX() - _x);
        double yDist = (origin.GetY() - _y);
        double dist = ((xDist*xDist) + (yDist*yDist));

        return dist;
    }
    
    double GetX() const {return _x;}
    double GetY() const {return _y;}
private:
    double _x;
    double _y;
};

class ComparePoints
{
public:
    ComparePoints (const Points2D &origin):_origin(origin){}
    bool operator()(const Points2D &lhs,const Points2D &rhs)
    {
        return (lhs.getDist(_origin) < rhs.getDist(_origin));
    }
private:
    Points2D _origin;
};

class NearestPoint2D
{
public:
    NearestPoint2D() {}
    virtual ~NearestPoint2D() {}
    
    void AddPoints(const Points2D &points) {_points.push_back(points);}
    
    bool GetNearestPoints(const Points2D &origin,vector<Points2D> &nearest_points,int K)
    {
        ComparePoints comp(origin);
        
        std::make_heap(_points.begin(),_points.end(),comp);
        std::sort_heap(_points.begin(),_points.end(),comp);
        
        for(Points::iterator itr = _points.begin(); itr != _points.end(); ++itr)
        {
            if(nearest_points.size() >= K)
                return true;
            
            nearest_points.push_back(*itr);
        }
        
        
        return false;
    }
private:
    typedef vector<Points2D> Points;
    
    Points _points;
};

int main(int argc, const char * argv[]) {
    
    NearestPoint2D point_container;
    
    point_container.AddPoints(Points2D(5,13));
    point_container.AddPoints(Points2D(5,14));
    point_container.AddPoints(Points2D(10,10));
    point_container.AddPoints(Points2D(15,15));
    point_container.AddPoints(Points2D(30,10));
    
    vector<Points2D> nearest_points;
    point_container.GetNearestPoints(Points2D(30,10),nearest_points,3);
    
    for(vector<Points2D>::iterator itr = nearest_points.begin(); itr != nearest_points.end(); ++itr)
    {
        cout<<"Nearest Point " << itr->GetX()<<" "<<itr->GetY()<<endl;
    }
    cout<<endl;
    return 0;
}

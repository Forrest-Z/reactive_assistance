#ifndef REACTIVE_ASSISTANCE_NS_GAP_H
#define REACTIVE_ASSISTANCE_NS_GAP_H

#include <cmath>

#include <geometry_msgs/Point.h>

#include <reactive_assistance/obstacle.hpp>
#include <reactive_assistance/dist_util.hpp>

namespace reactive_assistance 
{
  class Gap
  { 
    public:
      Gap(const Obstacle& r, const Obstacle& l, bool cr=true) 
            : right(r), left(l), 
              mid(computeMid()), 
              width(computeWidth()), 
              front(isFront()), 
              close_right(cr) 
              {}
      ~Gap() {}
      
      Obstacle right;
      Obstacle left;

      geometry_msgs::Point mid;

      double width;

      bool front;
      bool close_right;

    private:
      inline bool isFront() const { return (std::abs(left.angle - right.angle) <= M_PI); }
      
      inline geometry_msgs::Point computeMid() const
      { 
        geometry_msgs::Point p;

        p.x = (right.point.x + left.point.x)/2.0;
        p.y = (right.point.y + left.point.y)/2.0;
        p.z = 0.0;

        return p;
      }

      inline double computeWidth() const { return dist(left.point, right.point); }
  };
} /* namespace reactive_assistance */
     
#endif

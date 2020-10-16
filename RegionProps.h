#ifndef REGIONPROPS_H
#define REGIONPROPS_H

#include <opencv2/opencv.hpp>
#include <iostream>

#include "region.h"

class RegionProps {
    public:
        
        RegionProps(const std::vector<cv::Point> &_contour, const cv::Mat &_img);
        
        inline Region getRegion() const
        {
            return region;
        }
    private:
        
        void compute();
        
        double area();
       
        double perimeter();
        
        cv::Moments moments();
       
        cv::Point centroid();
        
        cv::Rect boundingbox();
        
        double aspectratio();
        
        double equivalentdiameter();
        
        double extent();
        
        std::vector< cv::Point > convex_hull();
        
        double convexarea();
        
        double solidity();
        
        cv::RotatedRect ellipse();
       
        double majoraxislength();
       
        double minoraxislength();
        
        double orientation();
        
        double eccentricity();
       
        std::vector<cv::Point> approx();
        
        cv::Mat filledimage();
       
        double filledarea();
       
        cv::Mat pixellist();
       
        cv::Mat conveximage();
        
        void pixelparameters();
        
        std::vector<cv::Point> extrema();
        Region region;
        std::vector<cv::Point> contour;
        cv::Mat img;

};


#endif

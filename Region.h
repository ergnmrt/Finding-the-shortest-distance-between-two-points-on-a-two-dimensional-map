#ifndef REGION_H
#define REGION_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Region {
    public:
       
        Region() {}
       
        inline double Area() const
        {
            return area;
        }
        
        inline void setArea(const double &_area)
        {
            area = _area;
        }
        
        inline double Perimeter() const
        {
            return perimeter;
        }
        
        inline void setPerimeter(const double &_perimeter)
        {
            perimeter = _perimeter;
        }
        
        inline cv::Moments Moments() const
        {
            return moments;
        }
       
        inline void setMoments(const cv::Moments &_moments)
        {
            moments = _moments;
        }
        
        inline cv::Rect BoundingBox() const
        {
            return boundingBox;
        }
        
        inline void setBoundingBox(const cv::Rect &_boundingBox)
        {
            boundingBox = _boundingBox;
        }
        
        inline std::vector<cv::Point> ConvexHull() const
        {
            return convex_hull;
        }
       
        inline void setConvexHull(const std::vector<cv::Point> &_convex_hull)
        {
            convex_hull = _convex_hull;
        }
    *
        
        inline double ConvexArea() const
        {
            return convex_area;
        }
        
        inline void setConvexArea(const double &_convex_area)
        {
            convex_area = _convex_area;
        }
       
        inline cv::RotatedRect Ellipse() const
        {
            return ellipse;
        }
        
        inline void setEllipse(const cv::RotatedRect &_ellipse)
        {
            ellipse = _ellipse;
        }
       
        inline double Orientation() const
        {
            return orientation;
        }
       
        inline void setOrientation(const double &_orientation)
        {
            orientation = _orientation;
        }
       
        inline double MinorAxis() const
        {
            return minoraxis_length;
        }
        
        inline void setMinorAxis(const double &minor_axis)
        {
            minoraxis_length = minor_axis;
        }
       
        inline double MajorAxis() const
        {
            return majoraxis_length;
        }
       
        inline void setMajorAxis(const double &major_axis)
        {
            majoraxis_length = major_axis;
        }
        
        inline std::vector<cv::Point> Approx() const
        {
            return approx;
        }
       
        inline void setApprox(const std::vector<cv::Point> &_approx)
        {
            approx = _approx;
        }
       
        inline cv::Mat FilledImage() const
        {
            return filledImage;
        }
        
        inline void setFilledImage(const cv::Mat &_filledImage)
        {
            filledImage = _filledImage;
        }
        
        inline cv::Point Centroid() const
        {
            return centroid;
        }
        
        inline void setCentroid(const cv::Point &_centroid)
        {
            centroid = _centroid;
        }
       
        inline double AspectRatio() const
        {
            return aspect_ratio;
        }
       
        inline void setAspectRatio(const double &_aspect_ratio)
        {
            aspect_ratio = _aspect_ratio;
        }
        
        inline double EquivalentDiameter() const
        {
            return equi_diameter;
        }
       
        inline void setEquivalentDiameter(const double &_equi_diameter)
        {
            equi_diameter = _equi_diameter;
        }
       
        inline double Eccentricity() const
        {
            return eccentricity;
        }
        
        inline void setEccentricity(const double &_eccentricity)
        {
            eccentricity = _eccentricity;
        }
        
        inline double FilledArea() const
        {
            return filledArea;
        }
        
        inline void setFilledArea(const double &_filledArea)
        {
            filledArea = _filledArea;
        }
        
        inline cv::Mat PixelList() const
        {
            return pixelList;
        }
        
        inline void setPixelList(const cv::Mat &_pixelList)
        {
            pixelList = _pixelList;
        }
       
        inline cv::Mat ConvexImage() const
        {
            return convexImage;
        }
       
        inline void setConvexImage(const cv::Mat &_convexImage)
        {
            convexImage = _convexImage;
        }
        
        inline double MaxVal() const
        {
            return maxval;
        }
        
        inline void setMaxVal(const double &_maxval)
        {
            maxval = _maxval;
        }
        
        inline double MinVal() const
        {
            return minval;
        }
        
        inline void setMinVal(const double &_minval)
        {
            minval = _minval;
        }
        
        inline cv::Point MaxLoc() const
        {
            return maxloc;
        }
        
        inline void setMaxLoc(const cv::Point &_maxloc)
        {
            maxloc = _maxloc;
        }
       
        inline cv::Point MinLoc() const
        {
            return minloc;
        }
       
        inline void setMinLoc(const cv::Point &_minloc)
        {
            minloc = _minloc;
        }
       
        inline cv::Scalar MeanVal() const
        {
            return meanval;
        }
        
        inline void setMeanVal(const cv::Scalar &_meanval)
        {
            meanval = _meanval;
        }
        
        inline std::vector<cv::Point> Extrema() const
        {
            return extrema;
        }
        
        inline void setExtrema(const std::vector<cv::Point> &_extrema)
        {
            extrema = _extrema;
        }
        
        inline double Solidity() const
        {
            return solidity;
        }
        
        inline void setSolidity(const double &_solidity)
        {
            solidity = _solidity;
        }

    private:
        double area, perimeter;
        cv::Moments moments;
        cv::Point centroid;
        cv::Rect boundingBox;
        double aspect_ratio, equi_diameter, extent;
        std::vector< cv::Point> convex_hull;
        double convex_area, solidity;
        cv::Point center;
        double majoraxis_length, minoraxis_length;
        double orientation, eccentricity;
        cv::Mat filledImage, pixelList;
        double filledArea;
        cv::Mat convexImage;
        cv::RotatedRect ellipse;
        std::vector<cv::Point> approx;
        double maxval, minval;
        cv::Point maxloc, minloc;
        cv::Scalar meanval;
        std::vector<cv::Point> extrema;
};

#endif

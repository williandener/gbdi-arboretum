/**
* @file
*
* This file defines the distance functions of the Metric Histogram Distance.
*
* @version 1.0
*/

#ifndef METRICHISTOGRAMDISTANCE_H
#define METRICHISTOGRAMDISTANCE_H

#include "DistanceFunction.h"
#include <stdexcept>

/**
* Class to the area diferences between two metric histograms.
*
* @brief Gets the area between the metric histograms.
* @author 006.
* @version 1.0.
*/
template <class ObjectType>
class MetricHistogramDistance : public DistanceFunction <ObjectType> {

    public:

        MetricHistogramDistance();
        virtual ~MetricHistogramDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2) throw (std::length_error);
        double getDistance(ObjectType &obj1, ObjectType &obj2) throw (std::length_error);
};

#include "MetricHistogramDistance-inl.h"
#endif // METRICHISTOGRAMDISTANCE_H

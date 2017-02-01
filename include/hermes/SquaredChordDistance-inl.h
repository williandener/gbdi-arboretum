/**
* Constructor.
*/
template <class ObjectType>
SquaredChordDistance<ObjectType>::SquaredChordDistance(){
}

/**
* Destructor.
*/
template <class ObjectType>
SquaredChordDistance<ObjectType>::~SquaredChordDistance(){
}

/**
* @copydoc DistanceFunction::GetDistance()
*/
template <class ObjectType>
double SquaredChordDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2) throw (std::length_error){

    return getDistance(obj1, obj2);
}

/**
* @copydoc DistanceFunction::getDistance()
*/
template <class ObjectType>
double SquaredChordDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2) throw (std::length_error){

    if (obj1.size() != obj2.size())
        throw std::length_error("The feature vectors do not have the same size.");

    double d;
    double tmp;

    d = 0;

    for (size_t i = 0; i < obj1.size(); i++){
        tmp = sqrt(obj1[i]) - sqrt(obj2[i]);
        d = d + (tmp*tmp);
    }

    // Statistic support
    this->updateDistanceCount();

    return d;
}

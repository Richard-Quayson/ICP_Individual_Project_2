/**
 * the file defines the isValidRoute method for the Routable interface
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H
#define ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H

class Routable {

public:
    /*
     * Checks if the sourceAirportId and destinationAirportId
     * of this route object are both valid (not null or zero)
     * The implementor must ensure that
     *      (r.getDestinationId && r.getSourceAirportId)
     * is not null or zero (where r is a given route object).
     *
     * the virtual keyword enables the derived class to override
     * this method of the base clases to achieve some form of polymorphism
     *
     * @param sourceAirportId
     * @return True or False
     */
    virtual bool isValidRoute();
};
#endif //ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H

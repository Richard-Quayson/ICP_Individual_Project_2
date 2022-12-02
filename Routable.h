/**
 * Description:
 * the file defines the isValidRoute method for the Routable abstract class
 *
 * @author Paa Kwasi Kodua
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H
#define ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H

class Routable {

public:
    /**
     * Checks if the sourceAirportId and destinationAirportId
     * of this route object are both valid (not null or zero)
     * The derived class must ensure that
     *      (r.getDestinationId && r.getSourceAirportId)
     * is not null or zero (where r is a given route object).
     *
     * the virtual keyword enables the derived class to override
     * this method of the base class to achieve some form of polymorphism
     *
     * @param sourceAirportId
     * @return true or false
     */
    virtual bool isValidRoute();
};

#endif //ICP_INDIVIDUAL_PROJECT_C___ROUTABLE_H
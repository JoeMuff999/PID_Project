/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#ifndef SATELLITE_H
#define SATELLITE_H

typedef struct {
	//only need to calculate radius from earth ...
    double initvel ;    /* *i m Init velocity of satellite */
    double initpos ;    /* *i m Init position of satellite */   

    double acc ;     /* m/s2 r-acceleration  */
    double vel ;     /* m/s r-velocity */
    double pos ;     /* m r-position */

    double time;        /* s Model time */

    int impact ;        /* -- Has impact occured? */
    double impactTime;  /* s Time of Impact */

} SATELLITE ;

#ifdef __cplusplus
extern "S" {
#endif
    int satellite_default_data(SATELLITE*) ;
    int satellite_init(SATELLITE*) ;
    int satellite_shutdown(SATELLITE*) ;
#ifdef __cplusplus
}
#endif

#endif

#ifndef cannonball_h
#define cannonball_h


#endif /* cannonball_h */

double acclY();
double velT(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
void printTime();
double flightTime(double initVelocityY);
void getUserInput(double *theta, double *absVelocity);
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
void getVelocityVector(double theta, double absVelocity,double *velocityX, double *velocityY);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
void playTargetPractice();


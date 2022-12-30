#include <iostream>

using namespace std;

int main()
{
    #define INCHES_IN_A_FOOT 12
    double const METERS_IN_A_INCH = 0.0254;

    double distance;
    cout << "Enter a distance in meters: ";
    cin >> distance;

    double inchesInDistance = distance / METERS_IN_A_INCH;
    int feet =  inchesInDistance / INCHES_IN_A_FOOT;

    cout << distance << "m = " << feet << "feet and " << inchesInDistance - (INCHES_IN_A_FOOT * feet) << " inches";

}

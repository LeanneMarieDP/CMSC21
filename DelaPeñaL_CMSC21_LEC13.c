#include <stdio.h>
#include <math.h>

//Declaring a structure for the line
struct line{
    //Declaring a struction for the points
    struct point{
        float x;
        float y;
    }point1, point2;

    float *midpoint; //Midpoint pointer
    float slope; //Slope
    float distance; //Distance between two points of the line
};

//Function that solves the slope of the line
float solveSlope(struct line line1){
    //m = (y2 - y1)/(x2 - x1) = Δy/Δx
    return(line1.point2.y - line1.point1.y) / (line1.point2.x - line1.point1.x);
}

//Function that solves the midpoint of a line
float *solveMidpoint(struct line line1){
    //M(x3, y3) = ((x1 + x2)/2, (y1 + y2)/2)
    static float midpoint[2]; //Static array to hold midpoint coordinates, unstatic array can lead to undefined behavior
    midpoint[0] = (line1.point1.x + line1.point2.x) / 2.0;
    midpoint[1] = (line1.point1.y + line1.point2.y) / 2.0;
    return midpoint;

}

//Function that solves for distance between two points
float solveDistance(struct line line1){
    // distance= √((x2−x1)^2 + (y2−y1)^2).
    // sqrt = square root, pow , 2 = raised to the second power
    return sqrt(pow(line1.point2.x - line1.point1.x, 2) + pow(line1.point2.y - line1.point2.y,2));
}

// Function that solves and prints the slope-intercept form of the line
void getslopeInterceptForm(struct line line1){
    // y=mx+b, b/y-intercept = y-coordinate of a point on the line - (slope * x-coordinate of the same point)
    float slope = solveSlope(line1);
    printf("y = %.6fx + (%.6f)\n", slope, line1.point1.y - slope *line1.point1.x);

}

int main(){
    struct line line1; // structure variable for the line

    //Get coordinates from user input
    printf("Enter x and y for point1: ");
    scanf("%f %f", &line1.point1.x, &line1.point1.y);

    printf("Enter x and y for point2: ");
    scanf("%f %f", &line1.point2.x, &line1.point2.y);

    //calls functions that solve the slope, midpoint and distance respectfully
    line1.slope = solveSlope(line1);
    line1.midpoint = solveMidpoint(line1);
    line1.distance = solveDistance(line1);

    //Print the outputs of the function calls
    printf("Slope: %.6f \n", line1.slope);
    printf("Midpoint: %.6f %.6f \n", line1.midpoint[0], line1.midpoint[1]);
    printf("Distance between 2 points: %.6f \n", line1.distance);
    getslopeInterceptForm(line1); //Prints the slope intercept form

    return 0;

    
}
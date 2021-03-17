class Solution {
public:
    double r , x, y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint()
    {
        double len, theta;
        double random = (double)rand() / RAND_MAX; // 0-1
        theta = random * 2 * 3.141592653589793238;  // 0-2PI
        double random1 = (double)rand() / RAND_MAX; // 0-1
        len = sqrt(random1) * r;
        return vector<double>({x + len * cos(theta), y + len * sin(theta)});
     }
};


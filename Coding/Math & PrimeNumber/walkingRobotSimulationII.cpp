// Leetcode 2069
#include<bits/stdc++.h>
using namespace std;
class Robot {
public:
    int w = 0;
    int h = 0;
    char dir = 'e';
    int x = 0;
    int y = 0;
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    void step(int num) {
        // The robot is always moving along the boundary of the rectangle.
        int perimeter = 2 * (w + h - 2);
        // bottom row + top row + left + right = w + w + (h-2) + (h-2) = 2*(w + h - 2)
        num = num % perimeter;
        // After completing 1 full loop -> robot comes back to same position
        if(num == 0 && x == 0 && y == 0){ // edge case: Robot completed a full cycle, so direction changes
            dir = 's';
            return;
        }
        while(num--){
            int newx = x;
            int newy = y;
            if(dir == 'e') newx++;
            else if(dir == 'n') newy++;
            else if(dir == 'w') newx--;
            else if(dir == 's') newy--;
            if(newx < 0 || newx >= w || newy < 0 || newy >= h){
                // agar out of bound jaa rha hai toh dir ko change krna hai - turn left
                if(dir == 'e') dir = 'n';
                else if(dir == 'n') dir = 'w';
                else if(dir == 'w') dir = 's';
                else if(dir == 's') dir = 'e';
                num++; // retry same step after turning
                // When robot hits the boundary: it does not move, it only turns, so that step is still pending
            }
            else{
                x = newx;
                y = newy;
            }
        }
    }
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir == 'e'){
            return "East";
        }
        else if(dir == 'w'){
            return "West";
        }
        else if(dir == 's'){
            return "South";
        }
        else{
            return "North";
        }
    }
};
int main(){
    
    return 0;
}
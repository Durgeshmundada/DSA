class Solution {
public:

    int result = INT_MAX;

    void mins(int target, int screen, int clipboard, int steps) {

        
        if(screen > target) return;

       
        if(screen == target) {
            result = min(result, steps);
            return;
        }

        if(clipboard > 0) {
            mins(target,
                 screen + clipboard,
                 clipboard,
                 steps + 1);
        }

        
        mins(target,
             screen + screen,
             screen,
             steps + 2);
    }

    int minSteps(int n) {

        if(n == 1) return 0;

        mins(n, 1, 0, 0);

        return result;
    }
};
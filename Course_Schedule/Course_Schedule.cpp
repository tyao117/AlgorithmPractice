https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int size = numCourses;
        int visited = 0;
        vector<int> n(numCourses, 0);
        queue<int> q;
        for (auto i : prerequisites)
        {
            ++(n[i.first]);
        }

        for (int i = 0; i < size; ++i)
        {
            if (n[i] == 0)
                q.emplace(i);
        }
        while (q.size() != 0)
        {
            int temp = q.front();
            q.pop();
            ++visited;
            for (auto i : prerequisites)
            {
                if (i.second == temp)
                {
                    n[i.first]--;
                    if (n[i.first] < 1)
                        q.emplace(i.first);
                }
            }
        }
        if (visited == size)
            return true;
        return false;

    }
};

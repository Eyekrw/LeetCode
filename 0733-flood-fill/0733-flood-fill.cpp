//#include <vector>
//#include <queue>

struct Pos
{
    Pos operator+(const Pos& other)
    {
        Pos tmp = *this;
        tmp.y += other.y;
        tmp.x += other.x;
        return tmp;
    }
    int y;
    int x;
};

Pos front[4] = {
    {-1, 0},  // up
    {0, 1},   // right
    {1, 0},   // down
    {0, -1}   // left
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        int change = image[sr][sc];

        queue<Pos> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (q.empty() == false)
        {
            Pos now = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                Pos next = now + front[i];
                if (next.y >= n || next.y < 0 || next.x >= m || next.x < 0) continue;
                if (image[next.y][next.x] == color) continue;
                if (image[next.y][next.x] != change) continue;
                image[next.y][next.x] = color;
                q.push(next);
            }
        }
        return image;
    }
};
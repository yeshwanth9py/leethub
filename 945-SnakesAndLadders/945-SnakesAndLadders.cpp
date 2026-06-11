// Last updated: 6/11/2026, 11:30:22 AM
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // visited[i] = have we ever enqueued square “i”?
        vector<bool> visited(n * n + 1, false);

        // queue will hold pairs (square_index, moves_so_far)
        queue<pair<int,int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            // If we’ve reached the last square, we’re done.
            if (pos == n * n) {
                return moves;
            }

            // Try all die rolls from 1..6
            for (int die = 1; die <= 6; ++die) {
                int nxt = pos + die;
                if (nxt > n * n) break;           // beyond the board → stop

                // Convert 1D index “nxt” → (r,c) on the n×n “snakes & ladders” board:
                int raw = (nxt - 1) / n;           // which “row from bottom” (0-based)
                int r   = n - 1 - raw;             // flip to 0-based from top
                int c   = (nxt - 1) % n;
                if (raw % 2 == 1) {
                    // odd “row from bottom” → that row is right→left
                    c = n - 1 - c;
                }

                // If there’s a snake/ladder at board[r][c], we “jump” to that destination.
                if (board[r][c] != -1) {
                    nxt = board[r][c];
                }

                // Enqueue “nxt” if not seen before
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push({nxt, moves + 1});
                }
            }
        }

        // If we empty the queue without reaching square n*n, it’s unreachable
        return -1;
    }
};

-- Last updated: 6/11/2026, 11:29:11 AM
# Write your MySQL query statement below
SELECT DISTINCT author_id as id
FROM Views 
WHERE author_id  = viewer_id
ORDER BY id ASC;


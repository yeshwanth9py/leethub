-- Last updated: 6/11/2026, 11:35:11 AM
SELECT w2.id from Weather as w1 JOIN Weather as w2
ON w2.temperature > w1.temperature AND
datediff(w2.recordDate,w1.recordDate) = 1;
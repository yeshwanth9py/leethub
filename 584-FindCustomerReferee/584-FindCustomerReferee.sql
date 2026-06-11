-- Last updated: 6/11/2026, 11:32:24 AM
SELECT name 
FROM Customer 
WHERE referee_id != 2 OR referee_id IS NULL;
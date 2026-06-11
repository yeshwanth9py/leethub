-- Last updated: 6/11/2026, 11:26:06 AM
# Write your MySQL query statement below
select user_id, count(follower_id) as followers_count from Followers
group by user_id
order by user_id asc;
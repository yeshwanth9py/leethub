-- Last updated: 6/11/2026, 11:32:20 AM
# Write your MySQL query statement below
select class from Courses
group by class
having count(student)>=5;
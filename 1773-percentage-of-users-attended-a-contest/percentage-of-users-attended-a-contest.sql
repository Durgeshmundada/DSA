# Write your MySQL query statement below
select r.contest_id, ROUND(COUNT(*) * 100.0 /
             (SELECT COUNT(*) FROM Users), 2) AS percentage
from register r
group by r.contest_id
ORDER BY percentage DESC, contest_id;
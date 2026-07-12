# Write your MySQL query statement below
SELECT s.user_id, case
                 WHEN s.user_id NOT IN (SELECT user_id FROM Confirmations) then 0
                 when s.user_id = c.user_id then round(1.0*(select count(*) from Confirmations where user_id=s.user_id and action='confirmed')/(select count(*) from Confirmations where user_id=s.user_id),2)
            end as confirmation_rate
from signups s
left join Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id
order by confirmation_rate asc;
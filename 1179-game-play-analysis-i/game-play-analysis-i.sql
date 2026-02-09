# Write your MySQL query statement below
select a1.player_id,a1.event_date as first_login
from Activity a1
left join Activity a2 
on a1.event_date>a2.event_date
And a1.player_id=a2.player_id
where a2.event_date is null
#also can with
#SELECT player_id, MIN(event_date) AS first_login
#FROM Activity
#GROUP BY player_id;

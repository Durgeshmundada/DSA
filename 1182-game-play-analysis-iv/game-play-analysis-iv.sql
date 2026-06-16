# Write your MySQL query statement below
select Round((
   SELECT count(cnt)
FROM (
    SELECT min(event_date) AS cnt,player_id
    FROM Activity
    GROUP BY player_id

) t,Activity
where Activity.player_id = t.player_id AND DATE_ADD(cnt, INTERVAL 1 DAY) = event_date
)/count(distinct(player_id)),2) as fraction
from Activity;

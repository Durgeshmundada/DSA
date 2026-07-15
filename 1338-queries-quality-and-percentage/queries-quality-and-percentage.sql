# Write your MySQL query statement below
select query_name, round(AVG(rating/position),2) as quality, round(ifnull((select count(*) from queries q where rating<3 and qs.query_name=q.query_name group by query_name )/count(query_name)*100,0),2) as poor_query_percentage
from queries qs
group by query_name;
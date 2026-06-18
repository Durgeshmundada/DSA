# Write your MySQL query statement below
SELECT id, CASE 
            WHEN p_id is null then 'Root'
            when id not in (select Distinct p_id from Tree WHERE p_id IS NOT NULL) then 'Leaf'
            else 'Inner'
          END as type
from Tree;